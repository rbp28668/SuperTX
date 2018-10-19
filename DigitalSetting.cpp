// DigitalSetting.cpp: implementation of the CDigitalSetting class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DigitalSetting.h"
#include "EditContext.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif



///////////////////////////////////////////////////////////////////////
// CDigitalSettingOutput

CDigitalSetting::CDigitalSettingOutput::CDigitalSettingOutput(CStandardWidget* pWidget)
: CDigitalOutput(pWidget)
{
  assert(this);
  assert(pWidget);
}


CValue CDigitalSetting::CDigitalSettingOutput::Value() const
{
  assert(this);
  return m_val;
}

void CDigitalSetting::CDigitalSettingOutput::Value(CValue val)
{
  assert(this);
  m_val = val;
}
  

///////////////////////////////////////////////////////////////////////
// CDigitalSetting

#pragma warning(disable : 4355) // 'this' : used in base member initializer list

CDigitalSetting::CDigitalSetting(const CWidgetTemplate* pTemplate,const std::string& strName)
: CStandardWidget(pTemplate, strName)
, m_output(this)
, m_blEditable(true)
{
  assert(this);
  assert(pTemplate);
}

CDigitalSetting::~CDigitalSetting()
{
}

COutput* CDigitalSetting::Output(int idx)
{
  assert(this);
  assert(idx == 0);
  return &m_output;
}

const COutput& CDigitalSetting::Output(int idx) const
{
  assert(this);
  assert(idx == 0);
  return m_output;
}

CInput* CDigitalSetting::Input(int /*idx*/)
{
  assert(this);
  assert(false);
  return static_cast<CInput*>(0);
}

const CInput& CDigitalSetting::Input(int /*idx*/) const
{
  assert(this);
  assert(false);
  return *static_cast<CInput*>(0);
}

CWidget* CDigitalSetting::Clone(const std::string& strName) const
{
  assert(this);
  CDigitalSetting* pWidget = static_cast<CDigitalSetting*>(CStandardWidget::Clone(strName));
  pWidget->m_blEditable = m_blEditable;
  pWidget->m_output.Value(m_output.Value());
  return pWidget;
}

bool CDigitalSetting::CanEdit() const
{
  assert(this);
  return m_blEditable;
}

void CDigitalSetting::Edit(const CEditContext* pContext)
{
  assert(this);
  assert(pContext);
  assert(m_blEditable);
  pContext->EditCDigitalSetting(this);
}

void CDigitalSetting::Freeze()
{ 
  assert(this);
  m_blEditable = false;
}

bool CDigitalSetting::Value() const
{
  assert(this);
  return bool(m_output.Value());
}

void CDigitalSetting::Value(bool blVal)
{
  assert(this);
  m_output.Value(CValue(blVal));
}
///////////////////////////////////////////////////////////////////////
// CDigitalSettingTemplate
CDigitalSettingTemplate::CDigitalSettingTemplate()
: CStandardWidgetTemplate("DigitalSetting")
, m_outputDesc("Value")
{
}

CDigitalSettingTemplate::~CDigitalSettingTemplate()
{
}


CWidget* CDigitalSettingTemplate::Create(const std::string& strName) const
{
  assert(this);
  return new CDigitalSetting(this,strName);
}

const CConnectorDescription& CDigitalSettingTemplate::Output(int idx) const
{
  assert(this);
  assert(idx >=0 && idx < OutputCount());
  return m_outputDesc;
}

int CDigitalSettingTemplate::OutputCount() const
{
  assert(this);
  return 1;
}

const CConnectorDescription& CDigitalSettingTemplate::Input(int idx) const
{
  assert(this);
  assert(false);
  return *static_cast<CConnectorDescription*>(0);
}

int CDigitalSettingTemplate::InputCount() const
{
  assert(this);
  return 0;
}

