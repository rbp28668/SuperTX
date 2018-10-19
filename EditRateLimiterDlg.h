#if !defined(AFX_EDITRATELIMITERDLG_H__EA11F903_5A22_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_EDITRATELIMITERDLG_H__EA11F903_5A22_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// EditRateLimiterDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEditRateLimiterDlg dialog

/**********************************************************************
* Class: CEditRateLimiterDlg
* Dialog class for editing a CRateLimiter widget
**********************************************************************/
class CEditRateLimiterDlg : public CDialog
{
// Construction
public:
	CEditRateLimiterDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEditRateLimiterDlg)
	enum { IDD = IDD_EDIT_RATE_LIMITER };
	CButton	m_cmdOK;
	int		m_iTransitTime;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditRateLimiterDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEditRateLimiterDlg)
	afx_msg void OnChangeEdtTransitTime();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDITRATELIMITERDLG_H__EA11F903_5A22_11D2_BB29_F5D419D58836__INCLUDED_)
