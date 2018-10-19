// Transmitter.h: interface for the CTransmitter class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRANSMITTER_H__0976D701_816C_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_TRANSMITTER_H__0976D701_816C_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

// Transmitter components
#include "AnalogueConverter.h"
#include "Switches.h"
#include "Encoder.h"
#include "RFTransmitter.h"

// Configuration
#include "TemplateList.h"
#include "ModelList.h"

class CTransmitter  
{
public:
	CTransmitter();
	virtual ~CTransmitter();

  // Configuration
  CTemplateList& Templates();
  CModelList& Models();

  // Hardware
  CAnalogueConverter& ADC();
  CSwitches& Switches();
  CEncoder& Encoder();

private:
  CTemplateList m_templates;
  CModelList m_models;

  CAnalogueConverter m_adc;
  CSwitches m_switches;
  CEncoder m_encoder;
  CRFTransmitter m_rfSection;

};

CTransmitter& Tx();

#endif // !defined(AFX_TRANSMITTER_H__0976D701_816C_11D2_BB29_F5D419D58836__INCLUDED_)
