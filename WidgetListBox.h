#if !defined(AFX_WIDGETLISTBOX_H__23E640C2_5305_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_WIDGETLISTBOX_H__23E640C2_5305_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// WidgetListBox.h : header file
//

class CWidget;
class CWidgetList;

/////////////////////////////////////////////////////////////////////////////
// CWidgetListBox window

/**********************************************************************
* Class: CWidgetListBox
* A windows list box for holding a list of widgets
**********************************************************************/
class CWidgetListBox : public CListBox
{
// Construction
public:
	CWidgetListBox();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWidgetListBox)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CWidgetListBox();

  void Add(CWidget* pWidget);
  void Update(CWidgetList& list);
  void UpdateEditable(CWidgetList& list);
  CWidget* Selected();

	// Generated message map functions
protected:
	//{{AFX_MSG(CWidgetListBox)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WIDGETLISTBOX_H__23E640C2_5305_11D2_BB29_F5D419D58836__INCLUDED_)
