// Selection.cpp: implementation of the CSelection class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SuperTX.h"
#include "Selection.h"
#include "Display.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

CSelectionEntry::CSelectionEntry() : m_ptr(0) {}
CSelectionEntry::CSelectionEntry(const std::string& str, void* ptr)
: m_str(str), m_ptr(ptr) {}

bool CSelectionEntry::operator == (const CSelectionEntry& rhs) const {return m_str.compare(rhs.m_str) == 0;}
bool CSelectionEntry::operator != (const CSelectionEntry& rhs) const {return m_str.compare(rhs.m_str) != 0;}
bool CSelectionEntry::operator < (const CSelectionEntry& rhs) const {return m_str.compare(rhs.m_str) == -1;}
bool CSelectionEntry::operator > (const CSelectionEntry& rhs) const {return m_str.compare(rhs.m_str) == 1;}

void* CSelectionEntry::Ptr() const {return m_ptr;}
const std::string& CSelectionEntry::Str() const {return m_str;}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSelection::CSelection()
: m_iPos(0)
, m_iOffset(0)
, m_iDisplaySize(0)
{
  m_pos = m_entries.end();
}

CSelection::~CSelection()
{

}

void CSelection::RemoveAll()
{
  assert(this);
  m_entries.clear();
  m_pos = m_entries.end();
}

void CSelection::SetPosition(const CRect& rPosition)
{
  assert(this);
  m_rPosition = rPosition;

  // Work out number of entries we can display in selection
  int iDispHeight = rPosition.Height();
  int cy = Font().m_iHeight;

  iDispHeight -= 1; // blank at top of title
  iDispHeight -= cy; // title text
  iDispHeight -= 2; // blank & line at bottom of title

  m_iDisplaySize = iDispHeight/(cy+1); // allow 1 pixel between entries
}

void CSelection::Paint(CDisplay* pDisplay)
{
  assert(this);
  assert(pDisplay);

  pDisplay->Rectangle (m_rPosition.left, m_rPosition.top, m_rPosition.right, m_rPosition.bottom);
  
  int cx = Font().m_iWidth;
  int cy = Font().m_iHeight;

  int ix = m_rPosition.left + cx/2;
  int iy = m_rPosition.top + 1;

  pDisplay->Text(m_strTitle, ix,iy, Font());

  iy += cy + 2; // thickness of line + 1 pixel space
  pDisplay->Line(m_rPosition.left, iy, m_rPosition.right, iy);

  // Erase old data
  pDisplay->FilledRectangle(m_rPosition.left + 1
                          ,iy + 1
                          ,m_rPosition.right
                          ,m_rPosition.bottom
                          ,false);
  
  EntryList::iterator pos = m_entries.begin();

  // if list is scrolled, skip to start of visible region
  int iOffset = m_iOffset;
  while(iOffset > 0 && pos != m_entries.end())
    {
    ++pos;
    --iOffset;
    }

  // display visible bits.
  int iToDisplay = m_iDisplaySize;
  while(pos != m_entries.end() && iToDisplay > 0)
    {
    ++iy; // allow 1 pixel between entries.
    pDisplay->TextBack(pos->Str(),ix,iy,Font(), pos != m_pos);
    iy += cy;
    ++pos;
    --iToDisplay;
    }

}

void CSelection::Title(const std::string& strTitle)
{
  assert(this);
  m_strTitle = strTitle;
}

const std::string& CSelection::Selected()
{
  assert(this);
  assert(m_pos != m_entries.end());
  return m_pos->Str();
}

bool CSelection::SelectionValid()
{
  assert(this);
  return m_pos != m_entries.end();
}

void CSelection::Add(const std::string& strName, void* ptr, CDisplay* pDisplay)
{
  assert(this);
  assert(ptr);

  bool blIsFirst = m_entries.empty();
  CSelectionEntry e(strName,ptr);
  m_entries.push_back(e);
  if(blIsFirst)
    {
    m_pos = m_entries.begin();
    m_iPos = 0;
    }

  // if add & update then pDisplay is non-null
  if(pDisplay)
    {
    Paint(pDisplay);
    pDisplay->Update();
    }
}

void CSelection::Up()
{
  assert(this);
  if(!m_entries.empty())
    {
    if(m_pos == m_entries.begin())
      {
      m_pos = m_entries.end();
      m_iPos = m_entries.size();
      m_iOffset = m_iPos - m_iDisplaySize;
      }
    else // moving up normally
      {
      if(m_iPos <= m_iOffset)  // need to scroll
        --m_iOffset;
      }
    --m_pos;
    --m_iPos;
    }

}

void CSelection::Down()
{
  assert(this);
  if(!m_entries.empty())
    {
    ++m_pos;
    ++m_iPos;

    if(m_pos == m_entries.end()) // wrap to start
      {
      m_pos = m_entries.begin();
      m_iPos = 0;
      m_iOffset = 0;
      }
    else // just moving down normally
      {
      // Scrolled off end of display?
      if(m_iPos >= m_iOffset + m_iDisplaySize)
        ++m_iOffset;
      }
    }
}



void* CSelection::SelectedPtr()
{
  assert(this);
  assert(m_pos != m_entries.end());
  return m_pos->Ptr();
}

const FontT& CSelection::Font() const
{
  assert(this);
  return font8;
}

CRect& CSelection::ScreenPosition()
{
  assert(this);
  return m_rPosition;
}
