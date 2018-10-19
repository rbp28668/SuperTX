// Encoder.h: interface for the CEncoder class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ENCODER_H__84EF3BE2_355C_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_ENCODER_H__84EF3BE2_355C_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


#include "Widgets.hpp"


class CRFTransmitter;
class CEncoderProxy;

/**********************************************************************
* Class: CEncoder
* This class models the encoder which encodes 8 analogue channels on
* to the output data stream. The analogue channel data is from the
* CEncoderProxy object of the current model.
**********************************************************************/
class CEncoder  
{

  CRFTransmitter* m_pRFStage;
  const CEncoderProxy* m_pProxy;
  
  CWinThread* m_pThread;
  bool m_blTerminate;

  static unsigned int __cdecl DoThread(LPVOID pParam);
  unsigned int ThreadFunction();

public:
	CEncoder();
	virtual ~CEncoder();

  void SetOutput(CRFTransmitter* ptx);
  void Connect(const CEncoderProxy* pProxy);

  void Run();
  void Stop();

};

#endif // !defined(AFX_ENCODER_H__84EF3BE2_355C_11D2_BB29_F5D419D58836__INCLUDED_)
