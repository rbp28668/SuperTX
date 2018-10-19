// Or.cpp: implementation of the COr class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Or.h"
#include "Type.h"
#include "Value.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


///////////////////////////////////////////////////////////////////////
// COrOutput

COr::COrOutput::COrOutput(CStandardWidget* pWidget)
: CDigitalOutput(pWidget)
{
  assert(this);
  assert(pWidget);
}


CValue COr::COrOutput::Value() const
{
  assert(this);
  return CValue(bool(Parent()->Input(0).Value()) && bool(Parent()->Input(1).Value()));
}


///////////////////////////////////////////////////////////////////////
// COr

#pragma warning(disable : 4355) // 'this' : used in base member initializer list

COr::COr(const CWidgetTemplate* pTemplate,const std::string& strName)
: CStandardWidget(pTemplate, strName)
, m_output(this)
{
  assert(this);
  assert(pTemplate);
  m_inputs[0].Parent(this);
  m_inputs[1].Parent(this);
}

COr::~COr()
{
}

COutput* COr::Output(int idx)
{
  assert(this);
  assert(idx == 0);
  return &m_output;
}

const COutput& COr::Output(int idx) const
{
  assert(this);
  assert(idx == 0);
  return m_output;
}

CInput* COr::Input(int idx)
{
  assert(this);
  assert(idx >= 0 && idx < InputCount());
  return &m_inputs[idx];
}

const CInput& COr::Input(int idx) const
{
  assert(this);
  assert(idx >= 0 && idx < InputCount());
  return m_inputs[idx];
}

///////////////////////////////////////////////////////////////////////
// COrTemplate
COrTemplate::COrTemplate()
: CStandardWidgetTemplate("Or")
, m_outputDesc("Value")
{
  m_ainputDesc[0].Name("A");
  m_ainputDesc[1].Name("B");
}

COrTemplate::~COrTemplate()
{
}


CWidget* COrTemplate::Create(const std::string& strName) const
{
  assert(this);
  return new COr(this,strName);
}

const CConnectorDescription& COrTemplate::Output(int idx) const
{
  assert(this);
  assert(idx >=0 && idx < OutputCount());
  return m_outputDesc;
}

int COrTemplate::OutputCount() const
{
  assert(this);
  return 1;
}

const CConnectorDescription& COrTemplate::Input(int idx) const
{
  assert(this);
  assert(idx >= 0 && idx < InputCount());
  return m_ainputDesc[idx];
}

int COrTemplate::InputCount() const
{
  assert(this);
  return 2;
}
