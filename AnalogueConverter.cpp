// AnalogueConverter.cpp: implementation of the CAnalogueConverter class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SuperTX.h"
#include "AnalogueConverter.h"
#include "type.h"
#include "value.h"
#include "SuperTXDlg.h" // source of inputs

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

///////////////////////////////////////////////////////////////////////
// CAnalogueConverter::CADCOutput

CAnalogueConverter::CADCOutput::CADCOutput()
: m_pADC(0)
 ,m_strName("")
 ,m_iChannel(0)
{
}

void CAnalogueConverter::CADCOutput::Set(CAnalogueConverter* pADC
                                    ,const std::string& strName
                                    ,int iChannel)
{
  assert(this);
  assert(pADC);
  m_pADC = pADC;
  m_strName = strName;
  m_iChannel = iChannel;
}

const std::string& CAnalogueConverter::CADCOutput::Name() const
{
  assert(this);
  return m_strName;
}

const CWidget* CAnalogueConverter::CADCOutput::Parent() const
{
  assert(this);
  return m_pADC;
}

CType CAnalogueConverter::CADCOutput::Type() const
{
  assert(this);
  return CType::Analogue();
}

CValue CAnalogueConverter::CADCOutput::Value() const
{
  assert(this);
  return m_pADC->ChannelValue(m_iChannel);
}


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CAnalogueConverter::CAnalogueConverter()
: m_strName("ADC")
, m_strTypeName("ADC")
, m_pDlg(0)
{
  m_aOutputs[0].Set(this,"Aileron",0);
  m_aOutputs[1].Set(this,"Elevator",1);
  m_aOutputs[2].Set(this,"Rudder",2);
  m_aOutputs[3].Set(this,"Throttle",3);
  m_aOutputs[4].Set(this,"Aux1",4);
  m_aOutputs[5].Set(this,"Aux2",5);
  m_aOutputs[6].Set(this,"Aux3",6);
  m_aOutputs[7].Set(this,"Aux4",7);
}

CAnalogueConverter::~CAnalogueConverter()
{

}

void CAnalogueConverter::Tie(CSuperTXDlg* pDlg)
{
  assert(this);
  assert(pDlg);
  m_pDlg = pDlg;
}

CValue CAnalogueConverter::ChannelValue(int iChannel)
{
  assert(this);
  assert(m_pDlg);
  assert(iChannel >= 0 && iChannel <= OUTPUT_COUNT);

  CValue val(0);

  // ADC channels are hard-wired to sticks, knobs & sliders
  short iChanVal = 2048; // mid position
  switch(iChannel)
    {
    case 0: // aileron
      iChanVal = m_pDlg->RightStick().XPosition();
      break;

    case 1: // elevator
      iChanVal = m_pDlg->RightStick().YPosition();
      break;

    case 2: // rudder
      iChanVal = m_pDlg->LeftStick().XPosition();
      break;

    case 3: // throttle
      iChanVal = m_pDlg->LeftStick().YPosition();
      break;

    case 4: // aux1
      iChanVal = m_pDlg->Aux1().Position();
      break;

    case 5: // aux2
      iChanVal = m_pDlg->Aux2().Position();
      break;

    case 6: // aux3
      iChanVal = m_pDlg->Aux3().Position();
      break;

    case 7: // aux4
      iChanVal = m_pDlg->Aux4().Position();
      break;

    default:
      assert(false);
      break;
    }
  val.Set(iChanVal-2048,2048); // scale 0-4095 to -1..+1

  return val;
}

COutput* CAnalogueConverter::Output(int idx)
{
  assert(this);
  assert(idx >= 0 && idx < OUTPUT_COUNT);

  return m_aOutputs + idx;
}

const COutput& CAnalogueConverter::Output(int idx) const
{
  assert(this);
  assert(idx >= 0 && idx < OUTPUT_COUNT);

  return m_aOutputs[idx];
}

int CAnalogueConverter::OutputCount() const
{
  assert(this);
  return OUTPUT_COUNT;
}


const std::string& CAnalogueConverter::Name() const
{
  assert(this);
  return m_strName;
}

const std::string& CAnalogueConverter::TypeName() const
{
  assert(this);
  return m_strTypeName;
}

