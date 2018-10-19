// RFTransmitter.h: interface for the CRFTransmitter class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RFTRANSMITTER_H__217F8681_3A86_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_RFTRANSMITTER_H__217F8681_3A86_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CDataPacket;

/**********************************************************************
* Class: CRFTransmitter
* Class for transmitting data packets.  This implementation uses
* a shared memory mapped file and a named events for cross
* process communication with the receiver.
**********************************************************************/
class CRFTransmitter  
{
  short m_iChannel;
  HANDLE m_hEvent;

  // File mapping
  HANDLE m_hMapping;    // handle to file mapping
  LPVOID m_pvBase;      // base addr of mapping

  void FreeResources();

public:
	CRFTransmitter();
	virtual ~CRFTransmitter();

  short Channel() const;
  void Channel(short iChan);

  void Transmit(const CDataPacket& data);
};

#endif // !defined(AFX_RFTRANSMITTER_H__217F8681_3A86_11D2_BB29_F5D419D58836__INCLUDED_)
