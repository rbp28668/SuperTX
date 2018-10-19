// Encoder.cpp           : implementation of the CEncoder class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Encoder.h"
#include "Value.h"
#include "Type.h"
#include "DataPacket.h"
#include "RFTransmitter.h"
#include "EncoderProxy.h"
#include "TimerManager.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CEncoder::CEncoder()
: m_pRFStage(0)
, m_pThread(0)
, m_blTerminate(false)
, m_pProxy(0)
{

  
}

CEncoder::~CEncoder()
{
  if(m_pThread)
    Stop();
}

unsigned int CEncoder::DoThread(LPVOID pParam)
{
  return static_cast<CEncoder*>(pParam)->ThreadFunction();
}

unsigned int CEncoder::ThreadFunction()
{
  CDataPacket packet;

  while(!m_blTerminate)
    {
    if(m_pProxy)
      {
      int nChannels = m_pProxy->InputCount();

      for(int i=0; i<nChannels; ++i)
        {
        // Scale output by 2048 to range -2048.. +2047 & offset to 0..4095
        short iVal = m_pProxy->Channel(i).Scale(2048) + 2048; 
        if(iVal < 0)
          iVal = 0;
        else if (iVal > 4095)
          iVal = 4095;

        packet[i] = iVal;
        }
      }
          
    m_pRFStage->Transmit(packet);

    // tick any time dependent stuff
    CTimerManager::Timers().Tick();

    ::Sleep(20); // approx 50Hz update
    }

  return 0;
}

void CEncoder::SetOutput(CRFTransmitter* ptx)
{
  assert(this);
  assert(ptx);
  m_pRFStage = ptx;
}

void CEncoder::Run()
{
  assert(this);
  assert(m_pRFStage); // must have been connected before running encoder
  assert(!m_pThread); // shouldn't be running already.

  m_pThread = AfxBeginThread(DoThread
                           , static_cast<void*>(this)
                           , THREAD_PRIORITY_NORMAL
                           ,0
                           ,CREATE_SUSPENDED);
  m_pThread->m_bAutoDelete = FALSE;
  m_pThread->ResumeThread();
}

void CEncoder::Stop()
{
  assert(this);
  assert(m_pThread);
  m_blTerminate = true;
  
  DWORD dwRet = 0;
  while(::GetExitCodeThread(m_pThread->m_hThread, &dwRet) 
                              && dwRet == STILL_ACTIVE)
    {
    ::Sleep(0);
    }
  delete m_pThread;
  m_pThread = 0;
}

void CEncoder::Connect(const CEncoderProxy* pProxy)
{
  assert(this);
  assert(pProxy);
  m_pProxy = pProxy;
}


