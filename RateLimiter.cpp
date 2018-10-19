// RateLimiter.cpp: implementation of the CRateLimiter class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RateLimiter.h"
#include "Value.h"
#include "Type.h"
#include "EditContext.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

///////////////////////////////////////////////////////////////////////
// CRateLimiterOutput

CRateLimiter::CRateLimiterOutput::CRateLimiterOutput(CStandardWidget* pWidget)
: CAnalogueOutput(pWidget)
{
  assert(this);
  assert(pWidget);
}


CValue CRateLimiter::CRateLimiterOutput::Value() const
{
  assert(this);
  return static_cast<const CRateLimiter*>(Parent())->Value();
}


///////////////////////////////////////////////////////////////////////
// CRateLimiter

#pragma warning(disable : 4355) // 'this' : used in base member initializer list

CRateLimiter::CRateLimiter(const CWidgetTemplate* pTemplate,const std::string& strName)
: CStandardWidget(pTemplate, strName)
, m_output(this)
, m_valCurrent(0)
, m_valDelta(5,512)  // approx 2s from neutral to end
, m_blEditable(true)
{
  assert(this);
  assert(pTemplate);
  m_input.Parent(this);
}

CRateLimiter::~CRateLimiter()
{
}

COutput* CRateLimiter::Output(int idx)
{
  assert(this);
  assert(idx == 0);
  return &m_output;
}

const COutput& CRateLimiter::Output(int idx) const
{
  assert(this);
  assert(idx == 0);
  return m_output;
}

CInput* CRateLimiter::Input(int idx)
{
  assert(this);
  assert(idx >= 0 && idx < InputCount());
  return &m_input;
}

const CInput& CRateLimiter::Input(int idx) const
{
  assert(this);
  assert(idx >= 0 && idx < InputCount());
  return m_input;
}

CWidget* CRateLimiter::Clone(const std::string& strName) const
{
  assert(this);
  CRateLimiter* pWidget = static_cast<CRateLimiter*>(CStandardWidget::Clone(strName));
  pWidget->m_blEditable = m_blEditable;
  pWidget->m_valDelta = m_valDelta;
  return pWidget;
}

bool CRateLimiter::CanEdit() const
{
  assert(this);
  return m_blEditable;
}

void CRateLimiter::Edit(const CEditContext* pContext)
{
  assert(this);
  assert(pContext);
  pContext->EditCRateLimiter(this);
}

void CRateLimiter::Freeze()
{
  assert(this);
  m_blEditable = false;
}


CValue CRateLimiter::Value() const
{
  assert(this);
  CValue blVal = m_input.Value();

  if(blVal > m_valCurrent)
    {
    m_valCurrent = m_valCurrent + m_valDelta;
    if(m_valCurrent > blVal)
      m_valCurrent = blVal;
    }
  else if(blVal < m_valCurrent)
    {
    m_valCurrent = m_valCurrent - m_valDelta;
    if(m_valCurrent < blVal)
      m_valCurrent = blVal;
    }
  // else blVal == m_valCurrent so don't bother setting m_valCurrent
  return m_valCurrent;
}

CValue CRateLimiter::Delta() const
{
  assert(this);
  return m_valDelta;
}

void CRateLimiter::Delta(CValue delta)
{
  assert(this);
  int iDelta = delta.Scale(CValue::Precision());
  if(iDelta <= 0)
    iDelta = 1;
  m_valDelta.Set(iDelta,CValue::Precision());
}
///////////////////////////////////////////////////////////////////////
// CRateLimiterTemplate
CRateLimiterTemplate::CRateLimiterTemplate()
: CStandardWidgetTemplate("RateLimiter")
, m_inputDesc("In")
, m_outputDesc("Value")
{
}

CRateLimiterTemplate::~CRateLimiterTemplate()
{
}


CWidget* CRateLimiterTemplate::Create(const std::string& strName) const
{
  assert(this);
  return new CRateLimiter(this,strName);
}

const CConnectorDescription& CRateLimiterTemplate::Output(int idx) const
{
  assert(this);
  assert(idx >=0 && idx < OutputCount());
  return m_outputDesc;
}

int CRateLimiterTemplate::OutputCount() const
{
  assert(this);
  return 1;
}

const CConnectorDescription& CRateLimiterTemplate::Input(int idx) const
{
  assert(this);
  assert(idx >= 0 && idx < InputCount());
  return m_inputDesc;
}

int CRateLimiterTemplate::InputCount() const
{
  assert(this);
  return 1;
}

