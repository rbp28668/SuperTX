// WindowsEditContext.h: interface for the CWindowsEditContext class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WINDOWSEDITCONTEXT_H__88BB1A62_543C_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_WINDOWSEDITCONTEXT_H__88BB1A62_543C_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "EditContext.h"

/**********************************************************************
* Class: CWindowsEditContext
* Concrete implementation of CEditContext to allow editing of widgets
* using standard windows dialogs.
**********************************************************************/
class CWindowsEditContext : public CEditContext  
{
public:
	CWindowsEditContext();
	virtual ~CWindowsEditContext();

  virtual void EditCAnalogueSetting(CAnalogueSetting* pWidget) const;
  virtual void EditCDigitalSetting(CDigitalSetting* pWidget) const;
  virtual void EditCGroup(CGroup* pWidget) const;
  virtual void EditCDelay(CDelay* pWidget) const;
  virtual void EditCRateLimiter(CRateLimiter* pWidget) const;
  virtual void EditCLinearPieceWise(CLinearPieceWise* pWidget) const;

};

#endif // !defined(AFX_WINDOWSEDITCONTEXT_H__88BB1A62_543C_11D2_BB29_F5D419D58836__INCLUDED_)
