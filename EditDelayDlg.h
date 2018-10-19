#if !defined(AFX_EDITDELAYDLG_H__EA11F902_5A22_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_EDITDELAYDLG_H__EA11F902_5A22_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// EditDelayDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEditDelayDlg dialog

/**********************************************************************
* Class: CEditDelayDlg
* Dialog class for editing a CDelay widget
**********************************************************************/
class CEditDelayDlg : public CDialog
{
// Construction
public:
	CEditDelayDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEditDelayDlg)
	enum { IDD = IDD_EDIT_DELAY };
	CButton	m_cmdOK;
	int		m_iDelay;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditDelayDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEditDelayDlg)
	afx_msg void OnChangeEdtDelay();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDITDELAYDLG_H__EA11F902_5A22_11D2_BB29_F5D419D58836__INCLUDED_)
