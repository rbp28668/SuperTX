// SelectionForm.h: interface for the CSelectionForm class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SELECTIONFORM_H__BA8537C1_6854_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_SELECTIONFORM_H__BA8537C1_6854_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Form.h"

class CSelection;

class CSelectionForm : public CForm  
{
public:
	CSelectionForm(CFormManager* pManager, CSelection* pSelection);
	virtual ~CSelectionForm();

  virtual void OnCmd4();  // Up arrow
  virtual void OnCmd5();  // Down arrow
  virtual void OnCmd7();  // close

  virtual void Paint(CDisplay* pDisplay);

private:
  CSelection* m_pSelection;
};

#endif // !defined(AFX_SELECTIONFORM_H__BA8537C1_6854_11D2_BB29_F5D419D58836__INCLUDED_)
