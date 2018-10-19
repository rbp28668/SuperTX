// StandardInput.cpp: implementation of the CStandardInput class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Standard.h"
#include "Value.h"
#include "Type.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

///////////////////////////////////////////////////////////////////////
// CStandardInput

CStandardWidget::CStandardWidget(const CWidgetTemplate* pTemplate,const std::string& strName)
: m_strName(strName)
, m_pTemplate(pTemplate)
{
  assert(this);
  assert(pTemplate);
}

CStandardWidget::~CStandardWidget()
{
  assert(this);
}

const CConnectorDescription& CStandardWidget::GetInputDesc(const CInput* pInput) const
{
  assert(this);
  assert(pInput);
  int nInputs = InputCount();
  for(int i=0; i<nInputs; ++i)
    {
    if(pInput == &Input(i))
      return m_pTemplate->Input(i);
    }
  assert(false);  // should ALWAYS find the input
  return m_pTemplate->Input(0);
}

const CConnectorDescription& CStandardWidget::GetOutputDesc(const COutput* pOutput) const
{
  assert(this);
  assert(pOutput);
  int nOutputs = OutputCount();
  for(int i=0; i<nOutputs; ++i)
    {
    if(pOutput == &Output(i))
      return m_pTemplate->Output(i);
    }
  assert(false);  // should ALWAYS find the outuput
  return m_pTemplate->Output(0);
}

int CStandardWidget::OutputCount() const
{
  assert(this);
  return m_pTemplate->OutputCount();
}


int CStandardWidget::InputCount() const
{
  assert(this);
  return m_pTemplate->InputCount();
}


const std::string& CStandardWidget::Name() const
{
  assert(this);
  return m_strName;
}

const std::string& CStandardWidget::TypeName() const
{
  assert(this);
  return m_pTemplate->Name();
}

CWidget* CStandardWidget::Clone(const std::string& strName) const
{
  assert(this);
  return m_pTemplate->Create(strName);
}

bool CStandardWidget::CanDelete() const
{
  assert(this);
  return true;
}

bool CStandardWidget::CanEdit() const
{
  assert(this);
  return false;
}

void CStandardWidget::Edit(const CEditContext* /*pContext*/)
{
  assert(this);
  assert(false);
}

void CStandardWidget::Freeze()
{
  assert(this);
  assert(false);
}


///////////////////////////////////////////////////////////////////////
// CStandardInput

CStandardInput::CStandardInput()
: m_pOutput(0)
, m_pWidget(0)
{
  assert(this);
}

CStandardInput::~CStandardInput()
{
}

void CStandardInput::Parent(const CStandardWidget* pWidget)
{
  assert(this);
  assert(pWidget);
  m_pWidget = pWidget;
}

const std::string& CStandardInput::Name() const
{
  assert(this);
  assert(m_pWidget);
  return m_pWidget->GetInputDesc(this).Name();
}

bool CStandardInput::Connect(const COutput* pOutput)
{
  assert(this);
  assert(pOutput);
  if(PathExists(pOutput)) // don't create circular paths
    return false;
  m_pOutput = pOutput;
  return true;
}

void CStandardInput::Disconnect()
{
  assert(this);
  m_pOutput = 0;
}

const COutput* CStandardInput::Source() const
{
  assert(this);
  return m_pOutput;
}

CValue CStandardInput::Value() const
{
  assert(this);
  if(m_pOutput)
    return m_pOutput->Value();
  else
    return CValue(0);
}

///////////////////////////////////////////////////////////////////////
// CAnalogueInput
CAnalogueInput::CAnalogueInput()
{
}

CAnalogueInput::~CAnalogueInput()
{
}

CType CAnalogueInput::Type() const
{
  assert(this);
  return CType::Analogue();
}


///////////////////////////////////////////////////////////////////////
// CDigitalInput

CDigitalInput::CDigitalInput()
{
}

CDigitalInput::~CDigitalInput()
{
}

CType CDigitalInput::Type() const
{
  assert(this);
  return CType::Digital();
}

///////////////////////////////////////////////////////////////////////
// CStandardOutput
CStandardOutput::CStandardOutput(const CStandardWidget* pWidget)
: m_pWidget(pWidget)
{
  assert(this);
  assert(pWidget);
}

const std::string& CStandardOutput::Name() const
{
  assert(this);
  return m_pWidget->GetOutputDesc(this).Name();
}

const CWidget* CStandardOutput::Parent() const
{
  assert(this);
  assert(m_pWidget);
  return(m_pWidget);
}

void CStandardOutput::Parent(const CStandardWidget* pWidget)
{
  assert(this);
  assert(pWidget);
  m_pWidget = pWidget;
}

///////////////////////////////////////////////////////////////////////
// CAnalogueOutput

CAnalogueOutput::CAnalogueOutput(const CStandardWidget* pWidget)
: CStandardOutput(pWidget)
{
}

CType CAnalogueOutput::Type() const
{
  assert(this);
  return CType::Analogue();
}

///////////////////////////////////////////////////////////////////////
// CDigitalOutput
CDigitalOutput::CDigitalOutput(const CStandardWidget* pWidget)
: CStandardOutput(pWidget)
{
}

CType CDigitalOutput::Type() const
{
  assert(this);
  return CType::Digital();
}


///////////////////////////////////////////////////////////////////////
// CStandardConnectorDescription
CStandardConnectorDescription::CStandardConnectorDescription()
: m_strName("")
{
  assert(this);
}

CStandardConnectorDescription::CStandardConnectorDescription(const std::string& strName)
: m_strName(strName)
{
  assert(this);
}

CStandardConnectorDescription::~CStandardConnectorDescription()
{
  assert(this);
}


void CStandardConnectorDescription::Name(const std::string& strName)
{
  assert(this);
  m_strName = strName;
}


const std::string& CStandardConnectorDescription::Name() const
{
  assert(this);
  return m_strName;
}

///////////////////////////////////////////////////////////////////////
// CAnalogueConnectorDescription
CAnalogueConnectorDescription::CAnalogueConnectorDescription()
{
  assert(this);
}

CAnalogueConnectorDescription::CAnalogueConnectorDescription(const std::string& strName)
: CStandardConnectorDescription(strName)
{
  assert(this);
}

CAnalogueConnectorDescription::~CAnalogueConnectorDescription()
{
  assert(this);
}

CType CAnalogueConnectorDescription::Type() const
{
  assert(this);
  return CType::Analogue();
}

///////////////////////////////////////////////////////////////////////
// CDigitalConnectorDescription
CDigitalConnectorDescription::CDigitalConnectorDescription()
{
  assert(this);
}

CDigitalConnectorDescription::CDigitalConnectorDescription(const std::string& strName)
: CStandardConnectorDescription(strName)
{
  assert(this);
}

CDigitalConnectorDescription::~CDigitalConnectorDescription()
{
  assert(this);
}

CType CDigitalConnectorDescription::Type() const
{
  assert(this);
  return CType::Analogue();
}

///////////////////////////////////////////////////////////////////////
// CStandardWidgetTemplate
CStandardWidgetTemplate::CStandardWidgetTemplate(const std::string& strName)
: m_strName(strName)
{
}

const std::string& CStandardWidgetTemplate::Name() const
{
  assert(this);
  return m_strName;
}

bool CStandardWidgetTemplate::CanEdit() const
{
  assert(this);
  return false;
}

void CStandardWidgetTemplate::Edit(CTemplateEditContext* /*pContext*/,  CTemplateList* /*pTemplates*/)
{
  assert(this);
}
