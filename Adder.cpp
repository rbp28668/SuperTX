// Adder.cpp: implementation of the CAdder class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Adder.h"
#include "Value.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////
// CAdderOutput

CAdder::CAdderOutput::CAdderOutput(CStandardWidget* pWidget)
: CAnalogueOutput(pWidget)
{
  assert(this);
  assert(pWidget);
}


CValue CAdder::CAdderOutput::Value() const
{
  assert(this);
  return Parent()->Input(0).Value() + Parent()->Input(1).Value();
}


///////////////////////////////////////////////////////////////////////
// CAdder

#pragma warning(disable : 4355) // 'this' : used in base member initializer list

CAdder::CAdder(const CWidgetTemplate* pTemplate,const std::string& strName)
: CStandardWidget(pTemplate, strName)
, m_output(this)
{
  assert(this);
  assert(pTemplate);
  m_inputs[0].Parent(this);
  m_inputs[1].Parent(this);
}

CAdder::~CAdder()
{
}

COutput* CAdder::Output(int idx)
{
  assert(this);
  assert(idx == 0);
  return &m_output;
}

const COutput& CAdder::Output(int idx) const
{
  assert(this);
  assert(idx == 0);
  return m_output;
}

CInput* CAdder::Input(int idx)
{
  assert(this);
  assert(idx >= 0 && idx < InputCount());
  return &m_inputs[idx];
}

const CInput& CAdder::Input(int idx) const
{
  assert(this);
  assert(idx >= 0 && idx < InputCount());
  return m_inputs[idx];
}

///////////////////////////////////////////////////////////////////////
// CAdderTemplate
CAdderTemplate::CAdderTemplate()
: CStandardWidgetTemplate("Adder")
, m_outputDesc("Value")
{
  m_ainputDesc[0].Name("A");
  m_ainputDesc[1].Name("B");
}

CAdderTemplate::~CAdderTemplate()
{
}

CWidget* CAdderTemplate::Create(const std::string& strName) const
{
  assert(this);
  return new CAdder(this,strName);
}

const CConnectorDescription& CAdderTemplate::Output(int idx) const
{
  assert(this);
  assert(idx >=0 && idx < OutputCount());
  return m_outputDesc;
}

int CAdderTemplate::OutputCount() const
{
  assert(this);
  return 1;
}

const CConnectorDescription& CAdderTemplate::Input(int idx) const
{
  assert(this);
  assert(idx >= 0 && idx < InputCount());
  return m_ainputDesc[idx];
}

int CAdderTemplate::InputCount() const
{
  assert(this);
  return 2;
}

