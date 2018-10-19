// Exponential.cpp: implementation of the CExponential class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Exponential.h"
#include "Value.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

///////////////////////////////////////////////////////////////////////
// CExponentialOutput

CExponential::CExponentialOutput::CExponentialOutput(CStandardWidget* pWidget)
: CAnalogueOutput(pWidget)
{
  assert(this);
  assert(pWidget);
}


CValue CExponential::CExponentialOutput::Value() const
{
  assert(this);
  CValue valSig = Parent()->Input(0).Value();
  CValue valControl = (Parent()->Input(1).Value() + CValue(1)) * CValue(1,2); // range 0..1

  return  valSig * valSig* valSig * valSig * valSig * valControl 
    + (CValue(1) - valControl) * valSig;
}


///////////////////////////////////////////////////////////////////////
// CExponential

#pragma warning(disable : 4355) // 'this' : used in base member initializer list

CExponential::CExponential(const CWidgetTemplate* pTemplate,const std::string& strName)
: CStandardWidget(pTemplate, strName)
, m_output(this)
{
  assert(this);
  assert(pTemplate);
  m_inputs[0].Parent(this);
  m_inputs[1].Parent(this);
}

CExponential::~CExponential()
{
}

COutput* CExponential::Output(int idx)
{
  assert(this);
  assert(idx == 0);
  return &m_output;
}

const COutput& CExponential::Output(int idx) const
{
  assert(this);
  assert(idx == 0);
  return m_output;
}

CInput* CExponential::Input(int idx)
{
  assert(this);
  assert(idx >= 0 && idx < InputCount());
  return &m_inputs[idx];
}

const CInput& CExponential::Input(int idx) const
{
  assert(this);
  assert(idx >= 0 && idx < InputCount());
  return m_inputs[idx];
}

///////////////////////////////////////////////////////////////////////
// CExponentialTemplate
CExponentialTemplate::CExponentialTemplate()
: CStandardWidgetTemplate("Exponential")
, m_outputDesc("Value")
{
  m_ainputDesc[0].Name("Signal");
  m_ainputDesc[1].Name("Control");
}

CExponentialTemplate::~CExponentialTemplate()
{
}


CWidget* CExponentialTemplate::Create(const std::string& strName) const
{
  assert(this);
  return new CExponential(this,strName);
}

const CConnectorDescription& CExponentialTemplate::Output(int idx) const
{
  assert(this);
  assert(idx >=0 && idx < OutputCount());
  return m_outputDesc;
}

int CExponentialTemplate::OutputCount() const
{
  assert(this);
  return 1;
}

const CConnectorDescription& CExponentialTemplate::Input(int idx) const
{
  assert(this);
  assert(idx >= 0 && idx < InputCount());
  return m_ainputDesc[idx];
}

int CExponentialTemplate::InputCount() const
{
  assert(this);
  return 2;
}
