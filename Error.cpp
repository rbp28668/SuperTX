// Error.cpp: implementation of the CError class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Error.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CError::CError(int idErr)
{
  CString strMsg;
  strMsg.LoadString(idErr);
  ::MessageBox(0,strMsg,"SuperTX", MB_OK | MB_ICONEXCLAMATION);
}

CError::~CError()
{

}
