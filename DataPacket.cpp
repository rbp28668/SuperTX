// DataPacket.cpp: implementation of the CDataPacket class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <assert.h>
#include "DataPacket.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDataPacket::CDataPacket()
{
}

CDataPacket::~CDataPacket()
{
}

short CDataPacket::operator[](int idx) const
{
  assert(this);
  assert(idx >=0 && idx < CHANNELS);
  return m_aiChannels[idx];
}

short& CDataPacket::operator[](int idx)
{
  assert(this);
  assert(idx >=0 && idx < CHANNELS);
  return m_aiChannels[idx];
}
