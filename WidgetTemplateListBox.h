#if !defined(AFX_WIDGETTEMPLATELISTBOX_H__23E640C1_5305_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_WIDGETTEMPLATELISTBOX_H__23E640C1_5305_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// WidgetTemplateListBox.h : header file
//

class CWidgetTemplate;
class CTemplateList;

/////////////////////////////////////////////////////////////////////////////
// CWidgetTemplateListBox window

/**********************************************************************
* Class: CWidgetTemplateListBox
* A windows list box for displaying a list of widget templates
**********************************************************************/
class CWidgetTemplateListBox : public CListBox
{
// Construction
public:
	CWidgetTemplateListBox();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWidgetTemplateListBox)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CWidgetTemplateListBox();

  void Add(CWidgetTemplate* pWidgetTemplate);
  void Update(CTemplateList& list);
  CWidgetTemplate* Selected();

	// Generated message map functions
protected:
	//{{AFX_MSG(CWidgetTemplateListBox)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WIDGETTEMPLATELISTBOX_H__23E640C1_5305_11D2_BB29_F5D419D58836__INCLUDED_)
