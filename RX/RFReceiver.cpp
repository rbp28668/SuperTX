// RFReceiver.cpp: implementation of the RFReceiver class.
//
//////////////////////////////////////////////////////////////////////
// Note that the receiver is in a number of states
// LISTENING - No "carrier" - it can't open the event & attempts to
//             open it every 250 mS
// RECEIVING - Getting an event signalled every 20mS (or so)
// FAILSAFE - Event times out- no signal for 1s
// A channel change goes into "LISTENING" on the new channel.
// LISTENING -> RECEIVING when event is opened
// FAILSAFE -> RECEIVING when an event is signalled.

#include "stdafx.h"
#include <sstream>
#include <assert.h>

#include "RX.h"
#include "RFReceiver.h"
#include "..\DataPacket.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

RFReceiver::RFReceiver()
: m_iChannel(0)
, m_hEvent(0)
, m_state(IDLE)
, m_pThread(0)
, m_blTerminate(false)
, m_hMapping(0)
, m_pvBase(0)  // base addr of mapping
{
  Channel(65);
}

RFReceiver::~RFReceiver()
{
  if(m_pThread)
    Stop();
  FreeResources();
}

unsigned int RFReceiver::DoThread(LPVOID pParam)
{
  return static_cast<RFReceiver*>(pParam)->ThreadFunction();
}

unsigned int RFReceiver::ThreadFunction()
{
  while(!m_blTerminate)
    {
    
    switch(m_state)
      {
      case IDLE:
        break;

      case LISTENING:
        if(Channel(m_iChannel))
          {
          m_state = RECEIVING;
          if(m_hwndNotify)
            ::PostMessage(m_hwndNotify,WM_RX_STATE_CHANGE,WPARAM(m_state),0);
          }
          
        break;

      case FAILSAFE:
        // DROP THROUGH

      case RECEIVING:
        {
        DWORD dwRet = ::WaitForSingleObject(m_hEvent, 1000); // 1s timeout
        switch(dwRet)
          {
          case WAIT_OBJECT_0:  // signal received
            m_packet = *static_cast<const CDataPacket*>(m_pvBase);
            if(m_hwndNotify)
              ::PostMessage(m_hwndNotify,WM_RX_DATA,0,LPARAM(&m_packet));

            if(m_state == FAILSAFE)
              {
              m_state = RECEIVING;
              if(m_hwndNotify)
                ::PostMessage(m_hwndNotify,WM_RX_STATE_CHANGE,WPARAM(m_state),0);
              }
            break;

          case WAIT_TIMEOUT:   // no signal
            m_state = FAILSAFE;
            if(m_hwndNotify)
              ::PostMessage(m_hwndNotify,WM_RX_STATE_CHANGE,WPARAM(m_state),0);
            break;

          case WAIT_FAILED:  // general failure
            ::CloseHandle(m_hEvent);
            m_hEvent = 0;
            m_state = LISTENING;
            if(m_hwndNotify)
              ::PostMessage(m_hwndNotify,WM_RX_STATE_CHANGE,WPARAM(m_state),0);
            break;
          }
        break;
        }
      }
    }

  return 0;
}

void RFReceiver::FreeResources()
{
  if(m_pvBase)
    {
    ::UnmapViewOfFile(m_pvBase);
    m_pvBase = 0;
    }

  if(m_hMapping)
    {
    ::CloseHandle(m_hMapping);
    m_hMapping = 0;
    }


  if(m_hEvent)
    {
    m_state = IDLE;
    ::CloseHandle(m_hEvent);
    m_hEvent = 0;
    }
}

bool RFReceiver::Channel(short iChan)
{
  assert(this);

  if(iChan >= 0 && iChan <= 90)  
    {
    FreeResources();

    std::ostringstream ost;
    ost << "SuperTXChan" << iChan << "Event" << std::ends;
    std::string str = ost.str();

    m_iChannel = iChan;
    m_hEvent = ::OpenEvent( EVENT_ALL_ACCESS
                              ,false    // not inheritable
                              ,str.c_str()
                              );
    }

  if(m_hEvent != NULL)
    {
    std::ostringstream ost;
    ost << "SuperTXChan" << iChan << "Data" << std::ends;
    std::string str = ost.str(); 

    m_hMapping = ::OpenFileMapping( FILE_MAP_READ
                                    ,FALSE // don't inherit
                                    ,str.c_str()  // named channel for map
                                    );
    
    if(m_hMapping != NULL)
      {
      m_pvBase =  ::MapViewOfFile( m_hMapping
                                  ,FILE_MAP_READ
                                  ,0          // 0 file offset high
                                  ,0          // 0 file offset low
                                  ,sizeof(CDataPacket) // size
                                  );
      }
    }

  if(m_pvBase)
    m_state = RECEIVING;
  else
    m_state = LISTENING;

  return m_hEvent != NULL;
}

void RFReceiver::Run()
{
  assert(this);
  assert(!m_pThread); // shouldn't be running already.

  m_pThread = AfxBeginThread(DoThread
                           , static_cast<void*>(this)
                           , THREAD_PRIORITY_NORMAL
                           ,0
                           ,CREATE_SUSPENDED);
  m_pThread->m_bAutoDelete = FALSE;
  m_pThread->ResumeThread();
}

void RFReceiver::Stop()
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

void RFReceiver::SetNotify(HWND hwnd)
{
  m_hwndNotify = hwnd;
}
