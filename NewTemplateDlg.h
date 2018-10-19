#if !defined(AFX_NEWTEMPLATEDLG_H__0B74A1C1_53D8_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_NEWTEMPLATEDLG_H__0B74A1C1_53D8_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// NewTemplateDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNewTemplateDlg dialog

/**********************************************************************
* Class: CNewTemplateDlg
* Dialog class for creating a new template.
**********************************************************************/
class CNewTemplateDlg : public CDialog
{
// Construction
public:
	CNewTemplateDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CNewTemplateDlg)
	enum { IDD = IDD_NEW_TEMPLATE };
	CButton	m_cmdOK;
	CString	m_strName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewTemplateDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNewTemplateDlg)
	afx_msg void OnChangeEdtTemplateName();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWTEMPLATEDLG_H__0B74A1C1_53D8_11D2_BB29_F5D419D58836__INCLUDED_)
