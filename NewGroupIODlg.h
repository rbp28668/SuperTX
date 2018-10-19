#if !defined(AFX_GETIDENTIFIERDLG_H__43CA92A1_5699_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_GETIDENTIFIERDLG_H__43CA92A1_5699_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// GetIdentifierDlg.h : header file
//

#include "Type.h"

/////////////////////////////////////////////////////////////////////////////
// CNewGroupIODlg dialog

/**********************************************************************
* Class: CNewGroupIODlg
* Dialog class for adding inputs or outputs to a group widget
**********************************************************************/
class CNewGroupIODlg : public CDialog
{
  CString m_strTitle;
  CType m_type;

// Construction
public:
	CNewGroupIODlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CNewGroupIODlg)
	enum { IDD = IDD_NEW_IO };
	CButton	m_cmdOK;
	CString	m_strName;
	int		m_iType;
	//}}AFX_DATA

  void SetTitle(const CString& strTitle);
  CType Type() const;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewGroupIODlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL


// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNewGroupIODlg)
	afx_msg void OnChangeEdtName();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETIDENTIFIERDLG_H__43CA92A1_5699_11D2_BB29_F5D419D58836__INCLUDED_)
