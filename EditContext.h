// EditContext.h: interface for the CEditContext class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EDITCONTEXT_H__88BB1A61_543C_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_EDITCONTEXT_H__88BB1A61_543C_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CAnalogueSetting;
class CDigitalSetting;
class CGroup;
class CDelay;
class CRateLimiter;
class CLinearPieceWise;

/**********************************************************************
* Class: CEditContext
* Abstract base class to allow editing of widgets. When a widget
* is asked to edit itself,it is passed a pointer to a CEditContext.
* This allows the editing code to be changed (e.g. from windows
* to transmitter specific) without having to modify the
* widgets.
**********************************************************************/
class CEditContext  
{
public:
	CEditContext();
	virtual ~CEditContext();

  virtual void EditCAnalogueSetting(CAnalogueSetting* pWidget) const = 0;
  virtual void EditCDigitalSetting(CDigitalSetting* pWidget) const = 0;
  virtual void EditCGroup(CGroup* pWidget) const = 0;
  virtual void EditCDelay(CDelay* pWidget) const = 0;
  virtual void EditCRateLimiter(CRateLimiter* pWidget) const = 0;
  virtual void EditCLinearPieceWise(CLinearPieceWise* pWidget) const = 0;
};

#endif // !defined(AFX_EDITCONTEXT_H__88BB1A61_543C_11D2_BB29_F5D419D58836__INCLUDED_)
