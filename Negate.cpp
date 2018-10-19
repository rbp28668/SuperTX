// Negate.cpp: implementation of the CNegate class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Negate.h"
#include "Value.h"
#include "Type.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


///////////////////////////////////////////////////////////////////////
// CNegateOutput

CNegate::CNegateOutput::CNegateOutput(CStandardWidget* pWidget)
: CAnalogueOutput(pWidget)
{
  assert(this);
  assert(pWidget);
}


CValue CNegate::CNegateOutput::Value() const
{
  assert(this);
  return CValue(0) - Parent()->Input(0).Value();
}


///////////////////////////////////////////////////////////////////////
// CNegate

#pragma warning(disable : 4355) // 'this' : used in base member initializer list

CNegate::CNegate(const CWidgetTemplate* pTemplate,const std::string& strName)
: CStandardWidget(pTemplate, strName)
, m_output(this)
{
  assert(this);
  assert(pTemplate);
  m_input.Parent(this);
}

CNegate::~CNegate()
{
}

COutput* CNegate::Output(int idx)
{
  assert(this);
  assert(idx == 0);
  return &m_output;
}

const COutput& CNegate::Output(int idx) const
{
  assert(this);
  assert(idx == 0);
  return m_output;
}

CInput* CNegate::Input(int idx)
{
  assert(this);
  assert(idx >= 0 && idx < InputCount());
  return &m_input;
}

const CInput& CNegate::Input(int idx) const
{
  assert(this);
  assert(idx >= 0 && idx < InputCount());
  return m_input;
}

///////////////////////////////////////////////////////////////////////
// CNegateTemplate
CNegateTemplate::CNegateTemplate()
: CStandardWidgetTemplate("Negate")
, m_inputDesc("In")
, m_outputDesc("Value")
{
}

CNegateTemplate::~CNegateTemplate()
{
}


CWidget* CNegateTemplate::Create(const std::string& strName) const
{
  assert(this);
  return new CNegate(this,strName);
}

const CConnectorDescription& CNegateTemplate::Output(int idx) const
{
  assert(this);
  assert(idx >=0 && idx < OutputCount());
  return m_outputDesc;
}

int CNegateTemplate::OutputCount() const
{
  assert(this);
  return 1;
}

const CConnectorDescription& CNegateTemplate::Input(int idx) const
{
  assert(this);
  assert(idx >= 0 && idx < InputCount());
  return m_inputDesc;
}

int CNegateTemplate::InputCount() const
{
  assert(this);
  return 1;
}

