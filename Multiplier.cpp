// Multiplier.cpp: implementation of the CMultiplier class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Multiplier.h"
#include "Value.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


///////////////////////////////////////////////////////////////////////
// CMultiplierOutput

CMultiplier::CMultiplierOutput::CMultiplierOutput(CStandardWidget* pWidget)
: CAnalogueOutput(pWidget)
{
  assert(this);
  assert(pWidget);
}


CValue CMultiplier::CMultiplierOutput::Value() const
{
  assert(this);
  return Parent()->Input(0).Value() * Parent()->Input(1).Value();
}


///////////////////////////////////////////////////////////////////////
// CMultiplier

#pragma warning(disable : 4355) // 'this' : used in base member initializer list

CMultiplier::CMultiplier(const CWidgetTemplate* pTemplate,const std::string& strName)
: CStandardWidget(pTemplate, strName)
, m_output(this)
{
  assert(this);
  assert(pTemplate);
  m_inputs[0].Parent(this);
  m_inputs[1].Parent(this);
}

CMultiplier::~CMultiplier()
{
}

COutput* CMultiplier::Output(int idx)
{
  assert(this);
  assert(idx == 0);
  return &m_output;
}

const COutput& CMultiplier::Output(int idx) const
{
  assert(this);
  assert(idx == 0);
  return m_output;
}

CInput* CMultiplier::Input(int idx)
{
  assert(this);
  assert(idx >= 0 && idx < InputCount());
  return &m_inputs[idx];
}

const CInput& CMultiplier::Input(int idx) const
{
  assert(this);
  assert(idx >= 0 && idx < InputCount());
  return m_inputs[idx];
}

///////////////////////////////////////////////////////////////////////
// CMultiplierTemplate
CMultiplierTemplate::CMultiplierTemplate()
: CStandardWidgetTemplate("Multiplier")
, m_outputDesc("Value")
{
  m_ainputDesc[0].Name("A");
  m_ainputDesc[1].Name("B");
}

CMultiplierTemplate::~CMultiplierTemplate()
{
}


CWidget* CMultiplierTemplate::Create(const std::string& strName) const
{
  assert(this);
  return new CMultiplier(this,strName);
}

const CConnectorDescription& CMultiplierTemplate::Output(int idx) const
{
  assert(this);
  assert(idx >=0 && idx < OutputCount());
  return m_outputDesc;
}

int CMultiplierTemplate::OutputCount() const
{
  assert(this);
  return 1;
}

const CConnectorDescription& CMultiplierTemplate::Input(int idx) const
{
  assert(this);
  assert(idx >= 0 && idx < InputCount());
  return m_ainputDesc[idx];
}

int CMultiplierTemplate::InputCount() const
{
  assert(this);
  return 2;
}

