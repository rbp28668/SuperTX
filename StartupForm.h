// StartupForm.h: interface for the CStartupForm class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STARTUPFORM_H__2ABA5AE3_646B_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_STARTUPFORM_H__2ABA5AE3_646B_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Form.h"

class CFormManager;

class CStartupForm : public CForm  
{
public:
	CStartupForm(CFormManager* pManager);

	virtual ~CStartupForm();

  virtual void OnCmd0();
  virtual void OnCmd1();
  virtual void OnCmd2();
  virtual void OnCmd3();
  virtual void OnCmd4();
  virtual void OnCmd5();
  virtual void OnCmd6();
  virtual void OnCmd7();

  virtual void Paint(CDisplay* pDisplay);

private:
  void OnButton();
};

#endif // !defined(AFX_STARTUPFORM_H__2ABA5AE3_646B_11D2_BB29_F5D419D58836__INCLUDED_)
