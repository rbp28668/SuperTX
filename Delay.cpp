// Delay.cpp: implementation of the CDelay class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Delay.h"
#include "Value.h"
#include "Type.h"
#include "EditContext.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

///////////////////////////////////////////////////////////////////////
// CDelayOutput

CDelay::CDelayOutput::CDelayOutput(CStandardWidget* pWidget)
: CDigitalOutput(pWidget)
{
  assert(this);
  assert(pWidget);
}


CValue CDelay::CDelayOutput::Value() const
{
  assert(this);
  return static_cast<const CDelay*>(Parent())->Value();
}


///////////////////////////////////////////////////////////////////////
// CDelay

#pragma warning(disable : 4355) // 'this' : used in base member initializer list

CDelay::CDelay(const CWidgetTemplate* pTemplate,const std::string& strName)
: CStandardWidget(pTemplate, strName)
, m_output(this)
, m_blEditable(true)
, m_nDelay(0)
, m_nTickCount(0)
, m_blPreviousState(false)
, m_blCurrentState(false)
{
  assert(this);
  assert(pTemplate);
  m_input.Parent(this);
}

CDelay::~CDelay()
{
}

COutput* CDelay::Output(int idx)
{
  assert(this);
  assert(idx == 0);
  return &m_output;
}

const COutput& CDelay::Output(int idx) const
{
  assert(this);
  assert(idx == 0);
  return m_output;
}

CInput* CDelay::Input(int idx)
{
  assert(this);
  assert(idx >= 0 && idx < InputCount());
  return &m_input;
}

const CInput& CDelay::Input(int idx) const
{
  assert(this);
  assert(idx >= 0 && idx < InputCount());
  return m_input;
}

CWidget* CDelay::Clone(const std::string& strName) const
{
  assert(this);
  CDelay* pWidget = static_cast<CDelay*>(CStandardWidget::Clone(strName));
  pWidget->m_blEditable = m_blEditable;
  pWidget->m_nDelay = m_nDelay;
  return pWidget;
}

bool CDelay::CanEdit() const
{
  assert(this);
  return m_blEditable;
}

void CDelay::Edit(const CEditContext* pContext)
{
  assert(this);
  assert(pContext);
  pContext->EditCDelay(this);
}

void CDelay::Freeze()
{
  assert(this);
  m_blEditable = false;
}


CValue CDelay::Value() const
{
  assert(this);

  bool blVal = m_input.Value();
  if(blVal != m_blPreviousState) // transition?
    m_nTickCount = m_nDelay;
  m_blPreviousState = blVal;

  if(m_nTickCount > 0)
    {
    blVal = m_blCurrentState;
    --m_nTickCount;
    }
  else // timed out - so go into new state
    {
    m_blCurrentState = blVal;
    }

  return CValue(blVal);
}

int& CDelay::Delay()
{
  assert(this);
  return m_nDelay;
}

///////////////////////////////////////////////////////////////////////
// CDelayTemplate
CDelayTemplate::CDelayTemplate()
: CStandardWidgetTemplate("Delay")
, m_inputDesc("In")
, m_outputDesc("Value")
{
}

CDelayTemplate::~CDelayTemplate()
{
}


CWidget* CDelayTemplate::Create(const std::string& strName) const
{
  assert(this);
  return new CDelay(this,strName);
}

const CConnectorDescription& CDelayTemplate::Output(int idx) const
{
  assert(this);
  assert(idx >=0 && idx < OutputCount());
  return m_outputDesc;
}

int CDelayTemplate::OutputCount() const
{
  assert(this);
  return 1;
}

const CConnectorDescription& CDelayTemplate::Input(int idx) const
{
  assert(this);
  assert(idx >= 0 && idx < InputCount());
  return m_inputDesc;
}

int CDelayTemplate::InputCount() const
{
  assert(this);
  return 1;
}

