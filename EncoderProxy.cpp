// EncoderProxy.cpp: implementation of the CEncoderProxy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <strstrea.h>

#include "EncoderProxy.h"
#include "Value.h"
#include "Type.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

CEncoderProxy::CEncoderInput::CEncoderInput()
: m_pProxy(0)
, m_pOutput(0)
{
}

void CEncoderProxy::CEncoderInput::Set(CEncoderProxy* pProxy, const std::string& strName)
{
  assert(this);
  assert(pProxy);
  m_pProxy = pProxy;
  m_strName = strName;
}

const std::string& CEncoderProxy::CEncoderInput::Name() const
{
  assert(this);
  return m_strName;
}

CType CEncoderProxy::CEncoderInput::Type() const
{
  assert(this);
  return CType::Analogue();
}

bool CEncoderProxy::CEncoderInput::Connect(const COutput* pOutput)
{
  assert(this);
  assert(pOutput);  // likely an error to connect to nul output
  if(PathExists(pOutput)) // don't create circular paths
    return false;
  m_pOutput = pOutput;
  return true;
}

void CEncoderProxy::CEncoderInput::Disconnect()
{
  assert(this);
  m_pOutput = 0;
}

const COutput* CEncoderProxy::CEncoderInput::Source() const
{
  assert(this);
  return m_pOutput;
}

CValue CEncoderProxy::CEncoderInput::Value() const
{
  assert(this);
  if(m_pOutput)
    return m_pOutput->Value();
  else
    return CValue(0);
}


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CEncoderProxy::CEncoderProxy()
: m_strName("Encoder")
, m_strTypeName("Encoder")
{
  for(int i=0; i<CHANNELS; ++i)
    {
    char ach[16];
    ostrstream os(ach,sizeof(ach));
    
    os << "Channel" << i +1 << ends;
    m_aInputs[i].Set(this,std::string(ach));
    }

}

CEncoderProxy::~CEncoderProxy()
{

}

CInput* CEncoderProxy::Input(int idx)
{
  assert(this);
  assert(idx >= 0 && idx < InputCount());
  return m_aInputs + idx;
}

const CInput& CEncoderProxy::Input(int idx) const
{
  assert(this);
  assert(idx >= 0 && idx < InputCount());
  return m_aInputs[idx];
}

int CEncoderProxy::InputCount() const
{
  assert(this);
  return CHANNELS;
}

const std::string& CEncoderProxy::Name() const
{
  assert(this);
  return m_strName;
}

const std::string& CEncoderProxy::TypeName() const
{
  assert(this);
  return m_strTypeName;
}


CValue CEncoderProxy::Channel(int idx) const
{
  assert(this);
  assert(idx >=0 && idx < CHANNELS);
  return m_aInputs[idx].Value(); 
}