#if !defined(AFX_EDITDIGITALSETTINGDLG_H__07383D42_54AC_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_EDITDIGITALSETTINGDLG_H__07383D42_54AC_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// EditDigitalSettingDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEditDigitalSettingDlg dialog

/**********************************************************************
* Class: CEditDigitalSettingDlg
* Dialog class for editing a CDigitalDisplay widget
**********************************************************************/
class CEditDigitalSettingDlg : public CDialog
{
// Construction
public:
	CEditDigitalSettingDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEditDigitalSettingDlg)
	enum { IDD = IDD_EDIT_DIGITAL_SETTING };
	int		m_iOnOff;
	CString	m_strTitle;
	//}}AFX_DATA
  bool m_blVal;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditDigitalSettingDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEditDigitalSettingDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDITDIGITALSETTINGDLG_H__07383D42_54AC_11D2_BB29_F5D419D58836__INCLUDED_)
