#if !defined(AFX_EDITMODELDLG_H__A8749022_5248_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_EDITMODELDLG_H__A8749022_5248_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// EditModelDlg.h : header file
//

#include "WidgetComboBox.h"
#include "InputComboBox.h"
#include "OutputComboBox.h"
#include "WidgetTemplateListBox.h"
#include "WidgetListBox.h"

class CModel;
class CTemplateList;
/////////////////////////////////////////////////////////////////////////////
// CEditModelDlg dialog

/**********************************************************************
* Class: CEditModelDlg
* Dialog class for editing a model
**********************************************************************/
class CEditModelDlg : public CDialog
{
  CModel* m_pModel;
  CTemplateList* m_pTemplates;

// Construction
public:
	CEditModelDlg(CModel* pModel, CTemplateList* pTemplates, CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEditModelDlg)
	enum { IDD = IDD_EDIT_MODEL };
	CButton	m_cmdDeleteWidget;
	CButton	m_cmdEditMixer;
	CButton	m_cmdAddWidget;
	CWidgetListBox	m_lstModelWidgets;
	CWidgetTemplateListBox	m_lstWidgets;
	CButton	m_cmdConnect;
	COutputComboBox	m_cmbSourceOutput;
	CInputComboBox	m_cmbDestInput;
	CWidgetComboBox	m_cmbSourceWidget;
	CWidgetComboBox	m_cmbDestWidget;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditModelDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEditModelDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeCmbDestWidget();
	afx_msg void OnSelchangeCmbSourceWidget();
	afx_msg void OnSelchangeCmbDestInput();
	afx_msg void OnSelchangeCmbSourceOutput();
	afx_msg void OnCmdConnect();
	afx_msg void OnSelchangeLstWidgets();
	afx_msg void OnCmdAddWidget();
	afx_msg void OnCmdDeleteWidget();
	afx_msg void OnCmdEditMixer();
	afx_msg void OnSelchangeLstModelWidgets();
	afx_msg void OnDblclkLstWidgets();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDITMODELDLG_H__A8749022_5248_11D2_BB29_F5D419D58836__INCLUDED_)
