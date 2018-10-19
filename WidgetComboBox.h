#if !defined(AFX_WIDGETCOMBOBOX_H__A8749023_5248_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_WIDGETCOMBOBOX_H__A8749023_5248_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// WidgetComboBox.h : header file
//

class CWidget;
class CWidgetList;

/////////////////////////////////////////////////////////////////////////////
// CWidgetComboBox window

/**********************************************************************
* Class: CWidgetComboBox
* Windows combo box for displaying a list of widgets
**********************************************************************/
class CWidgetComboBox : public CComboBox
{
// Construction
public:
	CWidgetComboBox();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWidgetComboBox)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CWidgetComboBox();

  void Add(CWidget* pWidget);
  void Update(CWidgetList& list);
  CWidget* Selected();

	// Generated message map functions
protected:
	//{{AFX_MSG(CWidgetComboBox)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WIDGETCOMBOBOX_H__A8749023_5248_11D2_BB29_F5D419D58836__INCLUDED_)
