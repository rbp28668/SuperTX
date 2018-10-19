// Switches.cpp: implementation of the CSwitches class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SuperTx.h" // needed for main dialog
#include "Switches.h"
#include "Type.h"
#include "Value.h"
#include "SuperTXDlg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


///////////////////////////////////////////////////////////////////////
// CSwitches::CSwitchOutput

CSwitches::CSwitchOutput::CSwitchOutput()
: m_pSwitches(0)
 ,m_strName("")
 ,m_iChannel(0)
{
}

void CSwitches::CSwitchOutput::Set(CSwitches* pSwitches
                                    ,const std::string& strName
                                    ,int iChannel)
{
  assert(this);
  assert(pSwitches);
  m_pSwitches = pSwitches;
  m_strName = strName;
  m_iChannel = iChannel;
}

const std::string& CSwitches::CSwitchOutput::Name() const
{
  assert(this);
  return m_strName;
}

const CWidget* CSwitches::CSwitchOutput::Parent() const
{
  assert(this);
  return m_pSwitches;
}


CType CSwitches::CSwitchOutput::Type() const
{
  assert(this);
  return CType::Digital();
}

CValue CSwitches::CSwitchOutput::Value() const
{
  assert(this);
  assert(m_pSwitches);
  assert(m_iChannel >= 0 && m_iChannel < m_pSwitches->OutputCount());
  return m_pSwitches->ChannelValue(m_iChannel);
}


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


CSwitches::CSwitches()
: m_strName("Switches")
, m_strTypeName("Switches")
, m_pDlg(0)
{
  m_aOutputs[0].Set(this,"Sw1",0);
  m_aOutputs[1].Set(this,"Sw2",1);
  m_aOutputs[2].Set(this,"Sw3",2);
  m_aOutputs[3].Set(this,"Sw4",3);
  m_aOutputs[4].Set(this,"Sw5",4);
  m_aOutputs[5].Set(this,"Sw6",5);
}

CSwitches::~CSwitches()
{

}

void CSwitches::Tie(CSuperTXDlg *pDlg)
{
  assert(this);
  assert(pDlg);
  m_pDlg = pDlg;
}

CValue CSwitches::ChannelValue(int iChannel)
{
  assert(this);
  assert(m_pDlg);
  assert(iChannel >= 0 && iChannel <= OUTPUT_COUNT);

  CValue val(false);

  // switch channels are hard-wired
  switch(iChannel)
    {
    case 0: val.Set(m_pDlg->Sw1().State());  break;
    case 1: val.Set(m_pDlg->Sw2().State());  break;
    case 2: val.Set(m_pDlg->Sw3().State());  break;
    case 3: val.Set(m_pDlg->Sw4().State());  break;
    case 4: val.Set(m_pDlg->Sw5().State());  break;
    case 5: val.Set(m_pDlg->Sw6().State());  break;


    default:
      assert(false);
      break;
    }

  return val;
}

COutput* CSwitches::Output(int idx)
{
  assert(this);
  assert(idx >= 0 && idx < OUTPUT_COUNT);

  return m_aOutputs + idx;
}

const COutput& CSwitches::Output(int idx) const
{
  assert(this);
  assert(idx >= 0 && idx < OUTPUT_COUNT);

  return m_aOutputs[idx];
}

int CSwitches::OutputCount() const
{
  assert(this);
  return OUTPUT_COUNT;
}

const std::string& CSwitches::Name() const
{
  assert(this);
  return m_strName;
}

const std::string& CSwitches::TypeName() const
{
  assert(this);
  return m_strTypeName;
}



