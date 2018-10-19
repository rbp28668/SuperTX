// TXEditContext.h: interface for the CTXEditContext class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TXEDITCONTEXT_H__ACFD9EC2_849D_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_TXEDITCONTEXT_H__ACFD9EC2_849D_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "EditContext.h"
class CFormManager;

/**********************************************************************
* Class: CTXEditContext
* Concrete class for editing widgets using the LCD screen on
* the transmitter.
**********************************************************************/
class CTXEditContext : public CEditContext  
{
public:
	CTXEditContext(CFormManager* pManager);
	virtual ~CTXEditContext();

  virtual void EditCAnalogueSetting(CAnalogueSetting* pWidget) const;
  virtual void EditCDigitalSetting(CDigitalSetting* pWidget) const;
  virtual void EditCGroup(CGroup* pWidget) const;
  virtual void EditCDelay(CDelay* pWidget) const;
  virtual void EditCRateLimiter(CRateLimiter* pWidget) const;
  virtual void EditCLinearPieceWise(CLinearPieceWise* pWidget) const;

private:
  CFormManager* m_pManager;

};

#endif // !defined(AFX_TXEDITCONTEXT_H__ACFD9EC2_849D_11D2_BB29_F5D419D58836__INCLUDED_)
