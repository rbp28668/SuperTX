// StringEntryForm.cpp: implementation of the CStringEntryForm class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <ctype.h>
#include "SuperTX.h"
#include "StringEntryForm.h"
#include "Arrows.h"
#include "FormManager.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

char* CStringEntryForm::m_aszKeys[] = 
  {
  "0123456789",
  "QWERTYUIOP",
  "ASDFGHJKL",
  "ZXCVBNM"
  };

int CStringEntryForm::m_aiLengths[] = 
  {
  10,10,9,7
  }; 

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CStringEntryForm::CStringEntryForm(CFormManager* pManager)
: CForm(pManager)
, m_iRow(0)
, m_iColumn(0)
, m_strText("")
, m_blCaps(false)
{

}

CStringEntryForm::~CStringEntryForm()
{

}

void CStringEntryForm::OnCmd0() // Insert
{
  assert(this);
  
  char ch = m_aszKeys[m_iRow][m_iColumn];
  if(!m_blCaps)
    ch = tolower(ch);
  
  m_strText.append(1,ch);

  std::string strRepaint(1,ch);
  
  int nChars = m_strText.size();
  int ix = m_ptBuffer.x + (nChars-1) * Font().m_iWidth;
  int iy = m_ptBuffer.y;
  Manager()->Display().TextBack(strRepaint,ix,iy,Font());

  Manager()->Display().Update();
}

void CStringEntryForm::OnCmd1() // Delete
{
  assert(this);

  int nChars = m_strText.size();
  if(nChars > 0)
    {
    std::string::iterator end = m_strText.end();
    --end;
    m_strText.erase(end);

    std::string strRepaint(1,' ');
    --nChars;
    int ix = m_ptBuffer.x + nChars * Font().m_iWidth;
    int iy = m_ptBuffer.y;
    Manager()->Display().TextBack(strRepaint,ix,iy,Font());

    Manager()->Display().Update();
    }

}

void CStringEntryForm::OnCmd2() // Right
{
  assert(this);

  // Delete old char
  UpdateKey(false);

  // Move right, wrapping down a row if necessary
  ++m_iColumn;
  if(m_iColumn >= m_aiLengths[m_iRow])
    {
    ++m_iRow;
    if(m_iRow >= KEY_ROWS)
      m_iRow = 0;
    m_iColumn = 0;
    }

  // Draw new char
  UpdateKey(true);

  Manager()->Display().Update();
}

void CStringEntryForm::OnCmd3() // Left
{
  assert(this);

  // Delete old char
  UpdateKey(false);

  // Move left, wrapping up a row if necessary
  --m_iColumn;
  if(m_iColumn < 0)
    {
    --m_iRow;
    if(m_iRow < 0)
      m_iRow = KEY_ROWS-1;
    m_iColumn = m_aiLengths[m_iRow] - 1;
    }

  // Draw new char
  UpdateKey(true);

  Manager()->Display().Update();
}

void CStringEntryForm::OnCmd4() // Caps
{
  assert(this);
  m_blCaps = !m_blCaps;

  // need status display.
  Manager()->Display().Update();
}

void CStringEntryForm::OnCmd5()
{
  assert(this);
}

void CStringEntryForm::OnCmd6() // Cancel
{
  assert(this);
  Manager()->EndModal(IDCANCEL);
}

void CStringEntryForm::OnCmd7() // OK
{
  assert(this);
  Manager()->EndModal(IDOK);
}


void CStringEntryForm::Paint(CDisplay* pDisplay)
{
  assert(this);
  assert(pDisplay);

  pDisplay->Clear();

  SetButton(0,"Ins");
  SetButton(1,"Del");
  SetButton(2,&RightArrow);
  SetButton(3,&LeftArrow);
  SetButton(4,"Caps");
  SetButton(6,"Cancel");
  SetButton(7,"Close");

  CRect rClient = Client();

  int iy = rClient.top + Font().m_iHeight;

  // edit box, allow for top & bottom border (2 pixels total))
  pDisplay->Rectangle(rClient.left, iy, rClient.right, iy + Font().m_iHeight + 2);
  m_ptBuffer.x = rClient.left + 1;
  m_ptBuffer.y = iy + 1;

  pDisplay->Text(m_strText,m_ptBuffer.x, m_ptBuffer.y, Font());

  // Skip box + 1 line spacing
  iy += 2 + 2* Font().m_iHeight;

  int ixLeft = rClient.Width() - Font().m_iWidth * 10; // 10 keys across max
  ixLeft = ixLeft/2 + rClient.left;

  pDisplay->Text(m_aszKeys[0],ixLeft,iy,Font());
  m_aptRowStart[0].x = ixLeft;
  m_aptRowStart[0].y = iy;
  iy += Font().m_iHeight;

  pDisplay->Text(m_aszKeys[1],ixLeft,iy,Font());
  m_aptRowStart[1].x = ixLeft;
  m_aptRowStart[1].y = iy;
  iy += Font().m_iHeight;
  ixLeft += Font().m_iWidth/2;

  pDisplay->Text(m_aszKeys[2],ixLeft,iy,Font());
  m_aptRowStart[2].x = ixLeft;
  m_aptRowStart[2].y = iy;
  iy += Font().m_iHeight;
  ixLeft += Font().m_iWidth/2;

  pDisplay->Text(m_aszKeys[3],ixLeft,iy,Font());
  m_aptRowStart[3].x = ixLeft;
  m_aptRowStart[3].y = iy;

  UpdateKey(true);

  pDisplay->Update();

}

const std::string& CStringEntryForm::Text() const
{
  assert(this);
  return m_strText;
}

void CStringEntryForm::SetText(const std::string& str)
{
  assert(this);
  m_strText = str;
}

void CStringEntryForm::UpdateKey(bool blInvert)
{
  assert(this);

  std::string strOld(1,m_aszKeys[m_iRow][m_iColumn]);
  int ix = m_aptRowStart[m_iRow].x;
  int iy = m_aptRowStart[m_iRow].y;
  ix += Font().m_iWidth * m_iColumn;
  Manager()->Display().TextBack(strOld,ix,iy,Font(),!blInvert);
}
