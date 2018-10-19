#if !defined(AFX_INPUTLISTBOX_H__B37359E1_5705_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_INPUTLISTBOX_H__B37359E1_5705_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// InputListBox.h : header file
//

class CInput;
class CWidget;

/////////////////////////////////////////////////////////////////////////////
// CInputListBox window

/**********************************************************************
* Class: CInputListBox
* Windows list box for displaying inputs to a widget
**********************************************************************/
class CInputListBox : public CListBox
{
// Construction
public:
	CInputListBox();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInputListBox)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CInputListBox();

  void Add(const CInput* pInput);
  void Update(const CWidget& widget);
  const CInput* Selected();

	// Generated message map functions
protected:
	//{{AFX_MSG(CInputListBox)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INPUTLISTBOX_H__B37359E1_5705_11D2_BB29_F5D419D58836__INCLUDED_)
