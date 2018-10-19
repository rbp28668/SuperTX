#if !defined(AFX_EDITGROUPDLG_H__EA11F901_5A22_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_EDITGROUPDLG_H__EA11F901_5A22_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// EditGroupDlg.h : header file
//

#include "WidgetListBox.h"
class CEditContext;
class CWidgetList;

/////////////////////////////////////////////////////////////////////////////
// CEditGroupDlg dialog

/**********************************************************************
* Class: CEditGroupDlg
* Dialog class for editing a CGroup which is a compound widget
**********************************************************************/
class CEditGroupDlg : public CDialog
{
  const CEditContext* m_pContext;
  CWidgetList* m_pWidgets;

// Construction
public:
	CEditGroupDlg(CWidgetList* pWidgets, const CEditContext* pContext, CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEditGroupDlg)
	enum { IDD = IDD_EDIT_MIXER_SETTINGS };
	CWidgetListBox	m_lstWidgets;
	CButton	m_cmdEdit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditGroupDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEditGroupDlg)
	afx_msg void OnSelchangeLstWidgets();
	afx_msg void OnCmdEdit();
	virtual BOOL OnInitDialog();
	afx_msg void OnDblclkLstWidgets();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDITGROUPDLG_H__EA11F901_5A22_11D2_BB29_F5D419D58836__INCLUDED_)
