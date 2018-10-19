// LinearPieceWise.cpp: implementation of the CLinearPieceWise class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "LinearPieceWise.h"
#include "Value.h"
#include "Type.h"
#include "EditContext.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

         
///////////////////////////////////////////////////////////////////////
// CLinearPieceWiseOutput

CLinearPieceWise::CLinearPieceWiseOutput::CLinearPieceWiseOutput(CStandardWidget* pWidget)
: CAnalogueOutput(pWidget)
{
  assert(this);
  assert(pWidget);
}


CValue CLinearPieceWise::CLinearPieceWiseOutput::Value() const
{
  assert(this);
  return static_cast<const CLinearPieceWise*>(Parent())->Value();
}


///////////////////////////////////////////////////////////////////////
// CLinearPieceWise

#pragma warning(disable : 4355) // 'this' : used in base member initializer list

CLinearPieceWise::CLinearPieceWise(const CWidgetTemplate* pTemplate,const std::string& strName)
: CStandardWidget(pTemplate, strName)
, m_output(this)
, m_blEditable(true)
{
  assert(this);
  assert(pTemplate);
  m_input.Parent(this);
}

CLinearPieceWise::~CLinearPieceWise()
{
}

COutput* CLinearPieceWise::Output(int idx)
{
  assert(this);
  assert(idx == 0);
  return &m_output;
}

const COutput& CLinearPieceWise::Output(int idx) const
{
  assert(this);
  assert(idx == 0);
  return m_output;
}

CInput* CLinearPieceWise::Input(int idx)
{
  assert(this);
  assert(idx >= 0 && idx < InputCount());
  return &m_input;
}

const CInput& CLinearPieceWise::Input(int idx) const
{
  assert(this);
  assert(idx >= 0 && idx < InputCount());
  return m_input;
}

CWidget* CLinearPieceWise::Clone(const std::string& strName) const
{
  assert(this);
  CLinearPieceWise* pWidget = static_cast<CLinearPieceWise*>(CStandardWidget::Clone(strName));
  pWidget->m_blEditable = m_blEditable;

  for(SegmentList::const_iterator iter = m_segments.begin()
    ; iter != m_segments.end()
    ; ++iter)
    {
    pWidget->m_segments.push_back(*iter);
    }

  return pWidget;
}

bool CLinearPieceWise::CanEdit() const
{
  assert(this);
  return m_blEditable;
}

void CLinearPieceWise::Edit(const CEditContext* pContext)
{
  assert(this);
  assert(pContext);
  pContext->EditCLinearPieceWise(this);
}

void CLinearPieceWise::Freeze()
{
  assert(this);
  m_blEditable = false;
}


CValue CLinearPieceWise::Value() const
{
  assert(this);
  int nPoints = PointCount();
  CValue x = m_input.Value();
  CValue y = x;
  if(nPoints > 1) // need 2 or more points for a line
    {
    SegmentList::const_iterator pos = m_segments.end();
    --pos;

    SegmentList::const_iterator iter = m_segments.begin();
    ++iter;
    while(iter != m_segments.end())
      {
      if(x < iter->x)
        {
        pos = --iter;
        break;
        }
      ++iter;
      }

    y = pos->m * (x - pos->x) + pos->y;
    }

  return y;
}

int CLinearPieceWise::PointCount() const
{
  assert(this);
  return m_segments.size();
}

CLinearPieceWise::SegmentList::iterator CLinearPieceWise::Points()
{
  assert(this);
  return m_segments.begin();
}

bool CLinearPieceWise::NextPoint(CLinearPieceWise::SegmentList::const_iterator& iter, CValue& x, CValue& y) const
{
  assert(this);
  if(iter != m_segments.end())
    {
    x = iter->x;
    y = iter->y;
    ++iter;
    return true;
    }

  return false;
}

void CLinearPieceWise::AddPoint(CValue x, CValue y)
{
  assert(this);

  CSegment seg;
  seg.x = x;
  seg.y = y;
  m_segments.push_back(seg);

  Update();
}

void CLinearPieceWise::DeletePoint(SegmentList::iterator& iter)
{
  assert(this);
  m_segments.erase(iter);
  Update();
}

void CLinearPieceWise::Clear()
{
  assert(this);
  m_segments.clear();
}

void CLinearPieceWise::Update()
{
  assert(this);
  m_segments.sort();
  m_segments.unique();

  SegmentList::iterator iter = m_segments.begin();
  SegmentList::iterator next = iter;
  ++next;
  for(; next != m_segments.end(); ++iter, ++next)
    {
    int x0 = iter->x.Scale(CValue::Precision());
    int y0 = iter->y.Scale(CValue::Precision());
    int x1 = next->x.Scale(CValue::Precision());
    int y1 = next->y.Scale(CValue::Precision());
    iter->m.Set(y1 - y0, x1 - x0);
    next->m = iter->m; // ensure last value set.
    }
}
///////////////////////////////////////////////////////////////////////
// CLinearPieceWiseTemplate
CLinearPieceWiseTemplate::CLinearPieceWiseTemplate()
: CStandardWidgetTemplate("LinearPieceWise")
, m_inputDesc("In")
, m_outputDesc("Value")
{
}

CLinearPieceWiseTemplate::~CLinearPieceWiseTemplate()
{
}


CWidget* CLinearPieceWiseTemplate::Create(const std::string& strName) const
{
  assert(this);
  return new CLinearPieceWise(this,strName);
}

const CConnectorDescription& CLinearPieceWiseTemplate::Output(int idx) const
{
  assert(this);
  assert(idx >=0 && idx < OutputCount());
  return m_outputDesc;
}

int CLinearPieceWiseTemplate::OutputCount() const
{
  assert(this);
  return 1;
}

const CConnectorDescription& CLinearPieceWiseTemplate::Input(int idx) const
{
  assert(this);
  assert(idx >= 0 && idx < InputCount());
  return m_inputDesc;
}

int CLinearPieceWiseTemplate::InputCount() const
{
  assert(this);
  return 1;
}

