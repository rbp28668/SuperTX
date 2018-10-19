#if !defined(AFX_MAINEDITDLG_H__97337621_5188_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_MAINEDITDLG_H__97337621_5188_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// MainEditDlg.h : header file
//

class CModelList;
class CEncoder;

#include "ModelListBox.h"
#include "EditModelDlg.h"
#include "WidgetTemplateListBox.h"

/////////////////////////////////////////////////////////////////////////////
// CMainEditDlg dialog

/**********************************************************************
* Class: CMainEditDlg
* Dialog class which provides a (temporary) main entry to editing
**********************************************************************/
class CMainEditDlg : public CDialog
{

  CModelList* m_pModels;
  CEncoder* m_pEncoder;
  CTemplateList* m_pTemplates;

// Construction
public:
	CMainEditDlg( CEncoder* pEncoder, CModelList* pModels, CTemplateList* pTemplates, CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMainEditDlg)
	enum { IDD = IDD_EDIT_MAIN };
	CWidgetTemplateListBox	m_lstTemplates;
	CButton	m_cmdTemplateEdit;
	CButton	m_cmdModelSelect;
	CButton	m_cmdModelEdit;
	CModelListBox	m_lstModels;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainEditDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMainEditDlg)
	afx_msg void OnCmdModelEdit();
	afx_msg void OnCmdModelNew();
	afx_msg void OnCmdModelSelect();
	afx_msg void OnCmdTemplateEdit();
	afx_msg void OnCmdTemplatesNew();
	afx_msg void OnSelchangeLstModelSelect();
	afx_msg void OnDblclkLstModelSelect();
	afx_msg void OnDblclkLstTemplates();
	afx_msg void OnSelchangeLstTemplates();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINEDITDLG_H__97337621_5188_11D2_BB29_F5D419D58836__INCLUDED_)
