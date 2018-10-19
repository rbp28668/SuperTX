// TXEditContext.cpp: implementation of the CTXEditContext class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SuperTX.h"
#include "TXEditContext.h"
#include "FormManager.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTXEditContext::CTXEditContext(CFormManager* pManager)
: m_pManager(pManager)
{
  assert(pManager);
  pManager->MarkCurrent(); // always return to current form
                            // note - implies the edit context
                            // is created just in time

}

CTXEditContext::~CTXEditContext()
{

}

void CTXEditContext::EditCAnalogueSetting(CAnalogueSetting* pWidget) const
{
  assert(this);
  assert(pWidget);
}

void CTXEditContext::EditCDigitalSetting(CDigitalSetting* pWidget) const
{
  assert(this);
  assert(pWidget);
}

void CTXEditContext::EditCGroup(CGroup* pWidget) const
{
  assert(this);
  assert(pWidget);
}

void CTXEditContext::EditCDelay(CDelay* pWidget) const
{
  assert(this);
  assert(pWidget);
}

void CTXEditContext::EditCRateLimiter(CRateLimiter* pWidget) const
{
  assert(this);
  assert(pWidget);
}

void CTXEditContext::EditCLinearPieceWise(CLinearPieceWise* pWidget) const
{
  assert(this);
  assert(pWidget);
}

