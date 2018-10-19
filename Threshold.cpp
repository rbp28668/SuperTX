// Threshold.cpp: implementation of the CThreshold class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Threshold.h"
#include "Type.h"
#include "Value.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


///////////////////////////////////////////////////////////////////////
// CThresholdOutput

CThreshold::CThresholdOutput::CThresholdOutput(CStandardWidget* pWidget)
: CDigitalOutput(pWidget)
{
  assert(this);
  assert(pWidget);
}


CValue CThreshold::CThresholdOutput::Value() const
{
  assert(this);
  return CValue(Parent()->Input(0).Value() > Parent()->Input(1).Value());
}


///////////////////////////////////////////////////////////////////////
// CThreshold

#pragma warning(disable : 4355) // 'this' : used in base member initializer list

CThreshold::CThreshold(const CWidgetTemplate* pTemplate,const std::string& strName)
: CStandardWidget(pTemplate, strName)
, m_output(this)
{
  assert(this);
  assert(pTemplate);
  m_inputs[0].Parent(this);
  m_inputs[1].Parent(this);
}

CThreshold::~CThreshold()
{
}

COutput* CThreshold::Output(int idx)
{
  assert(this);
  assert(idx == 0);
  return &m_output;
}

const COutput& CThreshold::Output(int idx) const
{
  assert(this);
  assert(idx == 0);
  return m_output;
}

CInput* CThreshold::Input(int idx)
{
  assert(this);
  assert(idx >= 0 && idx < InputCount());
  return &m_inputs[idx];
}

const CInput& CThreshold::Input(int idx) const
{
  assert(this);
  assert(idx >= 0 && idx < InputCount());
  return m_inputs[idx];
}

///////////////////////////////////////////////////////////////////////
// CThresholdTemplate
CThresholdTemplate::CThresholdTemplate()
: CStandardWidgetTemplate("Threshold")
, m_outputDesc("Value")
{
  m_ainputDesc[0].Name("A");
  m_ainputDesc[1].Name("B");
}

CThresholdTemplate::~CThresholdTemplate()
{
}


CWidget* CThresholdTemplate::Create(const std::string& strName) const
{
  assert(this);
  return new CThreshold(this,strName);
}

const CConnectorDescription& CThresholdTemplate::Output(int idx) const
{
  assert(this);
  assert(idx >=0 && idx < OutputCount());
  return m_outputDesc;
}

int CThresholdTemplate::OutputCount() const
{
  assert(this);
  return 1;
}

const CConnectorDescription& CThresholdTemplate::Input(int idx) const
{
  assert(this);
  assert(idx >= 0 && idx < InputCount());
  return m_ainputDesc[idx];
}

int CThresholdTemplate::InputCount() const
{
  assert(this);
  return 2;
}

