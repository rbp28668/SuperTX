// RFTransmitter.cpp: implementation of the CRFTransmitter class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <sstream>
#include "RFTransmitter.h"
#include "DataPacket.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRFTransmitter::CRFTransmitter()
: m_hEvent(0)
, m_hMapping(0)
, m_pvBase(0)  // base addr of mapping

{
  Channel(65); 
}

CRFTransmitter::~CRFTransmitter()
{
  FreeResources();
}

void CRFTransmitter::FreeResources()
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
    ::CloseHandle(m_hEvent);
    m_hEvent = 0;
    }
}

short CRFTransmitter::Channel() const
{
  assert(this);
  return m_iChannel;
}

void CRFTransmitter::Channel(short iChan)
{
  assert(this);
  if(iChan >= 0 && iChan <= 90)  
    {

    FreeResources();  // from any current connection

    std::ostringstream ost;
    ost << "SuperTXChan" << iChan << "Event" << std::ends;
    
    std::string str = ost.str();
    
    m_iChannel = iChan;
    m_hEvent = ::CreateEvent( 0         // no security attibutes
                              ,true     // manual reset
                              ,false    // initial state not signalled
                              ,str.c_str()
                              );

    ost.seekp(0);
    ost << "SuperTXChan" << iChan << "Data" << std::ends;
    str =  ost.str();




    m_hMapping = ::CreateFileMapping( HANDLE(0xFFFFFFFF) // use paging file
                                    ,NULL   // handle can't be inherited
                                    ,PAGE_READWRITE
                                    ,0      // max size high (0 so 4GB limit)
                                    ,sizeof(CDataPacket) // size low
                                    ,str.c_str()  // named channel for map
                                    );
    
    if(m_hMapping != NULL)
      {
      m_pvBase =  ::MapViewOfFile( m_hMapping
                                  ,FILE_MAP_WRITE
                                  ,0          // 0 file offset high
                                  ,0          // 0 file offset low
                                  ,sizeof(CDataPacket) // size
                                  );
      }
  
    }

}

void CRFTransmitter::Transmit(const CDataPacket& data)
{
  assert(this);

  if(m_pvBase)
    {
    CDataPacket* pPacket = static_cast<CDataPacket*>(m_pvBase);
    *pPacket = data;
    }

  if(m_hEvent)
    ::PulseEvent(m_hEvent);
}
