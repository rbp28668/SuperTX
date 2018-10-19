// And.cpp: implementation of the CAnd class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "And.h"
#include "Type.h"
#include "Value.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


///////////////////////////////////////////////////////////////////////
// CAndOutput

CAnd::CAndOutput::CAndOutput(CStandardWidget* pWidget)
: CDigitalOutput(pWidget)
{
  assert(this);
  assert(pWidget);
}


CValue CAnd::CAndOutput::Value() const
{
  assert(this);
  return CValue(bool(Parent()->Input(0).Value()) && bool(Parent()->Input(1).Value()));
}


///////////////////////////////////////////////////////////////////////
// CAnd

#pragma warning(disable : 4355) // 'this' : used in base member initializer list

CAnd::CAnd(const CWidgetTemplate* pTemplate,const std::string& strName)
: CStandardWidget(pTemplate, strName)
, m_output(this)
{
  assert(this);
  assert(pTemplate);
  m_inputs[0].Parent(this);
  m_inputs[1].Parent(this);
}

CAnd::~CAnd()
{
}

COutput* CAnd::Output(int idx)
{
  assert(this);
  assert(idx == 0);
  return &m_output;
}

const COutput& CAnd::Output(int idx) const
{
  assert(this);
  assert(idx == 0);
  return m_output;
}

CInput* CAnd::Input(int idx)
{
  assert(this);
  assert(idx >= 0 && idx < InputCount());
  return &m_inputs[idx];
}

const CInput& CAnd::Input(int idx) const
{
  assert(this);
  assert(idx >= 0 && idx < InputCount());
  return m_inputs[idx];
}

///////////////////////////////////////////////////////////////////////
// CAndTemplate
CAndTemplate::CAndTemplate()
: CStandardWidgetTemplate("And")
, m_outputDesc("Value")
{
  m_ainputDesc[0].Name("A");
  m_ainputDesc[1].Name("B");
}

CAndTemplate::~CAndTemplate()
{
}


CWidget* CAndTemplate::Create(const std::string& strName) const
{
  assert(this);
  return new CAnd(this,strName);
}

const CConnectorDescription& CAndTemplate::Output(int idx) const
{
  assert(this);
  assert(idx >=0 && idx < OutputCount());
  return m_outputDesc;
}

int CAndTemplate::OutputCount() const
{
  assert(this);
  return 1;
}

const CConnectorDescription& CAndTemplate::Input(int idx) const
{
  assert(this);
  assert(idx >= 0 && idx < InputCount());
  return m_ainputDesc[idx];
}

int CAndTemplate::InputCount() const
{
  assert(this);
  return 2;
}
