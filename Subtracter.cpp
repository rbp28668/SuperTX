// Subtracter.cpp: implementation of the CSubtracter class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Subtracter.h"
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
// CSubtracterOutput

CSubtracter::CSubtracterOutput::CSubtracterOutput(CStandardWidget* pWidget)
: CAnalogueOutput(pWidget)
{
  assert(this);
  assert(pWidget);
}


CValue CSubtracter::CSubtracterOutput::Value() const
{
  assert(this);
  return Parent()->Input(0).Value() - Parent()->Input(1).Value();
}


///////////////////////////////////////////////////////////////////////
// CSubtracter

#pragma warning(disable : 4355) // 'this' : used in base member initializer list

CSubtracter::CSubtracter(const CWidgetTemplate* pTemplate,const std::string& strName)
: CStandardWidget(pTemplate, strName)
, m_output(this)
{
  assert(this);
  assert(pTemplate);
  m_inputs[0].Parent(this);
  m_inputs[1].Parent(this);
}

CSubtracter::~CSubtracter()
{
}

COutput* CSubtracter::Output(int idx)
{
  assert(this);
  assert(idx == 0);
  return &m_output;
}

const COutput& CSubtracter::Output(int idx) const
{
  assert(this);
  assert(idx == 0);
  return m_output;
}

CInput* CSubtracter::Input(int idx)
{
  assert(this);
  assert(idx >= 0 && idx < InputCount());
  return &m_inputs[idx];
}

const CInput& CSubtracter::Input(int idx) const
{
  assert(this);
  assert(idx >= 0 && idx < InputCount());
  return m_inputs[idx];
}

///////////////////////////////////////////////////////////////////////
// CSubtracterTemplate
CSubtracterTemplate::CSubtracterTemplate()
: CStandardWidgetTemplate("Subtracter")
, m_outputDesc("Value")
{
  m_ainputDesc[0].Name("A");
  m_ainputDesc[1].Name("B");
}

CSubtracterTemplate::~CSubtracterTemplate()
{
}


CWidget* CSubtracterTemplate::Create(const std::string& strName) const
{
  assert(this);
  return new CSubtracter(this,strName);
}

const CConnectorDescription& CSubtracterTemplate::Output(int idx) const
{
  assert(this);
  assert(idx >=0 && idx < OutputCount());
  return m_outputDesc;
}

int CSubtracterTemplate::OutputCount() const
{
  assert(this);
  return 1;
}

const CConnectorDescription& CSubtracterTemplate::Input(int idx) const
{
  assert(this);
  assert(idx >= 0 && idx < InputCount());
  return m_ainputDesc[idx];
}

int CSubtracterTemplate::InputCount() const
{
  assert(this);
  return 2;
}

