#if !defined(AFX_EDITANALOGUESETTINGDLG_H__07383D41_54AC_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_EDITANALOGUESETTINGDLG_H__07383D41_54AC_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// EditAnalogueSettingDlg.h : header file
//

#include "Value.h"


/////////////////////////////////////////////////////////////////////////////
// CEditAnalogueSettingDlg dialog

/**********************************************************************
* Class: CEditAnalogueSettingDlg
* Dialog class for editing the CAnalogueSetting widget
**********************************************************************/
class CEditAnalogueSettingDlg : public CDialog
{
  CValue* m_pValue;
  CValue m_valOriginal;

// Construction
public:
	CEditAnalogueSettingDlg(CValue* pValue, CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEditAnalogueSettingDlg)
	enum { IDD = IDD_EDIT_ANALOGUE_SETTING };
	CSliderCtrl	m_sliderValue;
	CString	m_strValue;
	CString	m_strTitle;
	//}}AFX_DATA

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditAnalogueSettingDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEditAnalogueSettingDlg)
	afx_msg void OnChangeEdtValue();
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDITANALOGUESETTINGDLG_H__07383D41_54AC_11D2_BB29_F5D419D58836__INCLUDED_)
