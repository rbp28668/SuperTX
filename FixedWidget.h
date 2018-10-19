// FixedWidget.h: interface for the CFixedWidget class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FIXEDWIDGET_H__88BB1A63_543C_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_FIXEDWIDGET_H__88BB1A63_543C_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Widgets.hpp"

/**********************************************************************
* Class: CFixedWidget
* Base class for all the fixed widgets i.e. those built into the
* hardware such as ADC, encoder, switches.  This provides default
* implementations for most of the methods- unless over-ridden
* a fixed widget will have 0 inputs & outputs.
**********************************************************************/
class CFixedWidget : public CWidget  
{
public:
	CFixedWidget();
	virtual ~CFixedWidget();

  virtual COutput* Output(int idx);
  virtual const COutput& Output(int idx) const;
  virtual int OutputCount() const;
  
  // Inputs
  virtual CInput* Input(int idx);
  virtual const CInput& Input(int idx) const;
  virtual int InputCount() const;

  // Info
  virtual const std::string& Name() const = 0;
  virtual const std::string& TypeName() const = 0;

  // Creation
  virtual CWidget* Clone(const std::string& strName) const;
  virtual bool CanDelete() const;

  // Editing
  virtual bool CanEdit() const;
  virtual void Edit(const CEditContext* pContext);
  virtual void Freeze();
};

#endif // !defined(AFX_FIXEDWIDGET_H__88BB1A63_543C_11D2_BB29_F5D419D58836__INCLUDED_)
