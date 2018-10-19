#if !defined(AFX_INPUTCOMBOBOX_H__A8749025_5248_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_INPUTCOMBOBOX_H__A8749025_5248_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// InputComboBox.h : header file
//

class CInput;
class CWidget;

/////////////////////////////////////////////////////////////////////////////
// CInputComboBox window

/**********************************************************************
* Class: CInputComboBox
* Windows combo box for displaying inputs to a widget
**********************************************************************/
class CInputComboBox : public CComboBox
{
// Construction
public:
	CInputComboBox();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInputComboBox)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CInputComboBox();

  void Add(CInput* pInput);
  void Update(CWidget& widget);
  CInput* Selected();

	// Generated message map functions
protected:
	//{{AFX_MSG(CInputComboBox)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INPUTCOMBOBOX_H__A8749025_5248_11D2_BB29_F5D419D58836__INCLUDED_)
