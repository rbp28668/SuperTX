#if !defined(AFX_NEWWIDGETDLG_H__23E640C3_5305_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_NEWWIDGETDLG_H__23E640C3_5305_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// NewWidgetDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNewWidgetDlg dialog

/**********************************************************************
* Class: CNewWidgetDlg
* Dialog class for creating a new widget - the type has already
* been selected, this allows the user to specify a name
**********************************************************************/
class CNewWidgetDlg : public CDialog
{
// Construction
public:
	CNewWidgetDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CNewWidgetDlg)
	enum { IDD = IDD_NEW_WIDGET };
	CButton	m_cmdOK;
	CEdit	m_edtName;
	CString	m_strName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewWidgetDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNewWidgetDlg)
	afx_msg void OnChangeEdtWidgetName();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWWIDGETDLG_H__23E640C3_5305_11D2_BB29_F5D419D58836__INCLUDED_)
