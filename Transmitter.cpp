// Transmitter.cpp: implementation of the CTransmitter class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SuperTX.h"
#include "Transmitter.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

CTransmitter theTx;

CTransmitter& Tx()
{
  return theTx;
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTransmitter::CTransmitter()
:  m_models(&m_adc, &m_switches)
{

  // Set up transmitter stuff. Create a default model & tie it to the encoder
  CModel* pModel = Models().NewModel("Default");
  Encoder().Connect(pModel->Proxy());
  Encoder().SetOutput(&m_rfSection);

}

CTransmitter::~CTransmitter()
{

}

CTemplateList& CTransmitter::Templates()
{
  assert(this);
  return m_templates;
}

CModelList& CTransmitter::Models()
{
  assert(this);
  return m_models;
}

CAnalogueConverter& CTransmitter::ADC()
{
  assert(this);
  return m_adc;
}

CSwitches& CTransmitter::Switches()
{
  assert(this);
  return m_switches;
}

CEncoder& CTransmitter::Encoder()
{
  assert(this);
  return m_encoder;
}

