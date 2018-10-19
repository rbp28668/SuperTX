#if !defined(AFX_NEWMODELDLG_H__97337622_5188_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_NEWMODELDLG_H__97337622_5188_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// NewModelDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNewModelDlg dialog

/**********************************************************************
* Class: CNewModelDlg
* Dialog class for creating a new model
**********************************************************************/
class CNewModelDlg : public CDialog
{
// Construction
public:
	CNewModelDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CNewModelDlg)
	enum { IDD = IDD_NEW_MODEL };
	CButton	m_cmdOK;
	CString	m_strName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewModelDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNewModelDlg)
	afx_msg void OnChangeEdtModelName();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWMODELDLG_H__97337622_5188_11D2_BB29_F5D419D58836__INCLUDED_)
