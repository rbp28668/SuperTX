// RFReceiver.h: interface for the RFReceiver class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RFRECEIVER_H__05FED761_3AD8_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_RFRECEIVER_H__05FED761_3AD8_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "..\DataPacket.h"

#define WM_RX_DATA            (WM_USER + 100)
#define WM_RX_STATE_CHANGE    (WM_USER + 101)


class RFReceiver  
{
  public:

  enum StateT
    {
    IDLE,
    LISTENING,
    RECEIVING,
    FAILSAFE
    };

  private:

  CDataPacket m_packet;

  short m_iChannel;
  HANDLE m_hEvent;
  StateT m_state;

  CWinThread* m_pThread;
  bool m_blTerminate;

  HWND m_hwndNotify;

  // File mapping
  HANDLE m_hMapping;    // handle to file mapping
  LPVOID m_pvBase;      // base addr of mapping

  static unsigned int __cdecl DoThread(LPVOID pParam);
  unsigned int ThreadFunction();
  void FreeResources();

public:
	RFReceiver();
	virtual ~RFReceiver();

  bool Channel(short iChan);

  void Run();
  void Stop();

  StateT State() const {return m_state;}
  const CDataPacket& Packet() const {return m_packet;}

  void SetNotify(HWND hwnd);
};

#endif // !defined(AFX_RFRECEIVER_H__05FED761_3AD8_11D2_BB29_F5D419D58836__INCLUDED_)
