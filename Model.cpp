// Model.cpp: implementation of the CModel class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Model.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#include "AnalogueConverter.h"
#include "Switches.h"
#include "EncoderProxy.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CModel::CModel(const std::string& strName, CAnalogueConverter* pADC, CSwitches* pSwitches)
: m_strName(strName)
{
  assert(this);
  assert(pADC);
  assert(pSwitches);

  m_widgets.Add(pADC);
  m_widgets.Add(pSwitches);
  m_widgets.Add(&m_EncoderProxy);

  int iChannels = min(m_EncoderProxy.InputCount(), pADC->OutputCount());
  for(int i=0; i<iChannels; ++i)
    {
    const COutput* pOutput = pADC->Output(i);
    CInput* pInput = m_EncoderProxy.Input(i);
    pInput->Connect(pOutput);
    }

}

CModel::~CModel()
{
}

const CEncoderProxy* CModel::Proxy() const
{
  assert(this);
  return &m_EncoderProxy;
}

const std::string& CModel::Name() const
{
  assert(this);
  return m_strName;
}

CWidgetList& CModel::Widgets()
{
  assert(this);
  return m_widgets;
}
