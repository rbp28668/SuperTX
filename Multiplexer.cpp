// Multiplexer.cpp: implementation of the CMultiplexer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Multiplexer.h"
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
// CMultiplexerOutput

CMultiplexer::CMultiplexerOutput::CMultiplexerOutput(CStandardWidget* pWidget)
: CAnalogueOutput(pWidget)
{
  assert(this);
  assert(pWidget);
}


CValue CMultiplexer::CMultiplexerOutput::Value() const
{
  assert(this);
  if(Parent()->Input(2).Value())
    return Parent()->Input(1).Value();
  else
    return Parent()->Input(0).Value();
}


///////////////////////////////////////////////////////////////////////
// CMultiplexer

#pragma warning(disable : 4355) // 'this' : used in base member initializer list

CMultiplexer::CMultiplexer(const CWidgetTemplate* pTemplate,const std::string& strName)
: CStandardWidget(pTemplate, strName)
, m_output(this)
{
  assert(this);
  assert(pTemplate);
  m_inputs[0].Parent(this);
  m_inputs[1].Parent(this);
  m_switchInput.Parent(this);
}

CMultiplexer::~CMultiplexer()
{
}

COutput* CMultiplexer::Output(int idx)
{
  assert(this);
  assert(idx == 0);
  return &m_output;
}

const COutput& CMultiplexer::Output(int idx) const
{
  assert(this);
  assert(idx == 0);
  return m_output;
}

CInput* CMultiplexer::Input(int idx)
{
  assert(this);
  assert(idx >= 0 && idx < InputCount());
  switch(idx)
    {
    case 0:   return &m_inputs[idx];
    case 1:   return &m_inputs[idx];
    }
  return &m_switchInput;
}

const CInput& CMultiplexer::Input(int idx) const
{
  assert(this);
  assert(idx >= 0 && idx < InputCount());
  switch(idx)
    {
    case 0:   return m_inputs[idx];
    case 1:   return m_inputs[idx];
    }
  return m_switchInput;
}

///////////////////////////////////////////////////////////////////////
// CMultiplexerTemplate
CMultiplexerTemplate::CMultiplexerTemplate()
: CStandardWidgetTemplate("Multiplexer")
, m_outputDesc("Value")
{
  m_ainputDesc[0].Name("A");
  m_ainputDesc[1].Name("B");
  m_switchedInputDesc.Name("Select");
}

CMultiplexerTemplate::~CMultiplexerTemplate()
{
}

CWidget* CMultiplexerTemplate::Create(const std::string& strName) const
{
  assert(this);
  return new CMultiplexer(this,strName);
}

const CConnectorDescription& CMultiplexerTemplate::Output(int idx) const
{
  assert(this);
  assert(idx >=0 && idx < OutputCount());
  return m_outputDesc;
}

int CMultiplexerTemplate::OutputCount() const
{
  assert(this);
  return 1;
}

const CConnectorDescription& CMultiplexerTemplate::Input(int idx) const
{
  assert(this);
  assert(idx >= 0 && idx < InputCount());
  switch(idx)
    {
    case 0: return m_ainputDesc[idx];
    case 1: return m_ainputDesc[idx];
    }
  return m_switchedInputDesc;
}

int CMultiplexerTemplate::InputCount() const
{
  assert(this);
  return 3;
}

