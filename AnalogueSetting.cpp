// AnalogueSetting.cpp: implementation of the CAnalogueSetting class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AnalogueSetting.h"
#include "EditContext.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif




///////////////////////////////////////////////////////////////////////
// CAnalogueSettingOutput

CAnalogueSetting::CAnalogueSettingOutput::CAnalogueSettingOutput(CStandardWidget* pWidget)
: CAnalogueOutput(pWidget)
{
  assert(this);
  assert(pWidget);
}


CValue CAnalogueSetting::CAnalogueSettingOutput::Value() const
{
  assert(this);
  return m_val;
}

CValue& CAnalogueSetting::CAnalogueSettingOutput::EditVal()
{
  assert(this);
  return m_val;
}
  

///////////////////////////////////////////////////////////////////////
// CAnalogueSetting

#pragma warning(disable : 4355) // 'this' : used in base member initializer list

CAnalogueSetting::CAnalogueSetting(const CWidgetTemplate* pTemplate,const std::string& strName)
: CStandardWidget(pTemplate, strName)
, m_output(this)
, m_blEditable(true)
{
  assert(this);
  assert(pTemplate);
}

CAnalogueSetting::~CAnalogueSetting()
{
}

COutput* CAnalogueSetting::Output(int idx)
{
  assert(this);
  assert(idx == 0);
  return &m_output;
}

const COutput& CAnalogueSetting::Output(int idx) const
{
  assert(this);
  assert(idx == 0);
  return m_output;
}

CInput* CAnalogueSetting::Input(int /*idx*/)
{
  assert(this);
  assert(false);
  return static_cast<CInput*>(0);
}

const CInput& CAnalogueSetting::Input(int /*idx*/) const
{
  assert(this);
  assert(false);
  return *static_cast<CInput*>(0);
}

CValue& CAnalogueSetting::Value()
{
  assert(this);
  return m_output.EditVal();
}

CWidget* CAnalogueSetting::Clone(const std::string& strName) const
{
  assert(this);
  CAnalogueSetting* pWidget = static_cast<CAnalogueSetting*>(CStandardWidget::Clone(strName));
  pWidget->m_blEditable = m_blEditable;
  pWidget->m_output.EditVal() = m_output.Value();
  return pWidget;
}

bool CAnalogueSetting::CanEdit() const
{
  assert(this);
  return m_blEditable;
}

void CAnalogueSetting::Edit(const CEditContext* pContext)
{
  assert(this);
  assert(pContext);
  assert(m_blEditable);
  pContext->EditCAnalogueSetting(this);
}

void CAnalogueSetting::Freeze()
{ 
  assert(this);
  m_blEditable = false;
}

///////////////////////////////////////////////////////////////////////
// CAnalogueSettingTemplate
CAnalogueSettingTemplate::CAnalogueSettingTemplate()
: CStandardWidgetTemplate("AnalogueSetting")
, m_outputDesc("Value")
{
}

CAnalogueSettingTemplate::~CAnalogueSettingTemplate()
{
}


CWidget* CAnalogueSettingTemplate::Create(const std::string& strName) const
{
  assert(this);
  return new CAnalogueSetting(this,strName);
}

const CConnectorDescription& CAnalogueSettingTemplate::Output(int idx) const
{
  assert(this);
  assert(idx >=0 && idx < OutputCount());
  return m_outputDesc;
}

int CAnalogueSettingTemplate::OutputCount() const
{
  assert(this);
  return 1;
}

const CConnectorDescription& CAnalogueSettingTemplate::Input(int idx) const
{
  assert(this);
  assert(false);
  return *static_cast<CConnectorDescription*>(0);
}

int CAnalogueSettingTemplate::InputCount() const
{
  assert(this);
  return 0;
}

