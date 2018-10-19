// Not.cpp: implementation of the CNot class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Not.h"
#include "Value.h"
#include "Type.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

///////////////////////////////////////////////////////////////////////
// CNotOutput

CNot::CNotOutput::CNotOutput(CStandardWidget* pWidget)
: CDigitalOutput(pWidget)
{
  assert(this);
  assert(pWidget);
}


CValue CNot::CNotOutput::Value() const
{
  assert(this);

  return CValue( !bool(Parent()->Input(0).Value()));
}


///////////////////////////////////////////////////////////////////////
// CNot

#pragma warning(disable : 4355) // 'this' : used in base member initializer list

CNot::CNot(const CWidgetTemplate* pTemplate,const std::string& strName)
: CStandardWidget(pTemplate, strName)
, m_output(this)
{
  assert(this);
  assert(pTemplate);
  m_input.Parent(this);
}

CNot::~CNot()
{
}

COutput* CNot::Output(int idx)
{
  assert(this);
  assert(idx == 0);
  return &m_output;
}

const COutput& CNot::Output(int idx) const
{
  assert(this);
  assert(idx == 0);
  return m_output;
}

CInput* CNot::Input(int idx)
{
  assert(this);
  assert(idx >= 0 && idx < InputCount());
  return &m_input;
}

const CInput& CNot::Input(int idx) const
{
  assert(this);
  assert(idx >= 0 && idx < InputCount());
  return m_input;
}

///////////////////////////////////////////////////////////////////////
// CNotTemplate
CNotTemplate::CNotTemplate()
: CStandardWidgetTemplate("Not")
, m_inputDesc("In")
, m_outputDesc("Value")
{
}

CNotTemplate::~CNotTemplate()
{
}


CWidget* CNotTemplate::Create(const std::string& strName) const
{
  assert(this);
  return new CNot(this,strName);
}

const CConnectorDescription& CNotTemplate::Output(int idx) const
{
  assert(this);
  assert(idx >=0 && idx < OutputCount());
  return m_outputDesc;
}

int CNotTemplate::OutputCount() const
{
  assert(this);
  return 1;
}

const CConnectorDescription& CNotTemplate::Input(int idx) const
{
  assert(this);
  assert(idx >= 0 && idx < InputCount());
  return m_inputDesc;
}

int CNotTemplate::InputCount() const
{
  assert(this);
  return 1;
}

