// DataPacket.h: interface for the CDataPacket class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DATAPACKET_H__217F8682_3A86_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_DATAPACKET_H__217F8682_3A86_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/**********************************************************************
* Class: CDataPacket
* A class which encapsulates the packet of data transmitted on
* every frame.
**********************************************************************/
class CDataPacket  
{
  enum {CHANNELS = 8};

  short m_aiChannels[CHANNELS];

public:
	CDataPacket();
	~CDataPacket();

  short operator[](int idx) const;
  short& operator[](int idx);
};

#endif // !defined(AFX_DATAPACKET_H__217F8682_3A86_11D2_BB29_F5D419D58836__INCLUDED_)
