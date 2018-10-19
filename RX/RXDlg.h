// RXDlg.h : header file
//

#if !defined(AFX_RXDLG_H__792BBAC7_386F_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_RXDLG_H__792BBAC7_386F_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "RFReceiver.h"

/////////////////////////////////////////////////////////////////////////////
// CRXDlg dialog

class CRXDlg : public CDialog
{
  RFReceiver m_rx;

// Construction
public:
	CRXDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRXDlg)
	enum { IDD = IDD_RX_DIALOG };
	CProgressCtrl	m_prgChan8;
	CProgressCtrl	m_prgChan7;
	CProgressCtrl	m_prgChan6;
	CProgressCtrl	m_prgChan5;
	CProgressCtrl	m_prgChan4;
	CProgressCtrl	m_prgChan3;
	CProgressCtrl	m_prgChan2;
	CProgressCtrl	m_prgChan1;
	CStatic	m_lblState;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRXDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRXDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDestroy();
  afx_msg LONG OnRXData(WPARAM wParam, LPARAM lParam);
  afx_msg LONG OnRXStateChanged(WPARAM wParam, LPARAM lParam);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RXDLG_H__792BBAC7_386F_11D2_BB29_F5D419D58836__INCLUDED_)
