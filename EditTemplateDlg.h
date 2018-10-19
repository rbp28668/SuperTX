#if !defined(AFX_EDITTEMPLATEDLG_H__B23BC923_55E5_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_EDITTEMPLATEDLG_H__B23BC923_55E5_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// EditTemplateDlg.h : header file
//

#include "WidgetTemplateListBox.h"
#include "WidgetComboBox.h"
#include "WidgetListBox.h"
#include "OutputComboBox.h"
#include "InputComboBox.h"	
#include "OutputListBox.h"
#include "InputListBox.h"


class CGroupTemplate;
class CTemplateList;

/////////////////////////////////////////////////////////////////////////////
// CEditTemplateDlg dialog

/**********************************************************************
* Class: CEditTemplateDlg
* Dialog class for editing a group template.
**********************************************************************/
class CEditTemplateDlg : public CDialog
{
  CGroupTemplate* m_pTemplate;        // template being edited
  CTemplateList* m_pTemplates;        // list of all available templates.

// Construction
public:
	CEditTemplateDlg(CGroupTemplate* pTemplate, CTemplateList* pTemplates, CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEditTemplateDlg)
	enum { IDD = IDD_EDIT_MIXER };
	CButton	m_cmdFreeze;
	COutputListBox	m_lstOutputs;
	CInputListBox	m_lstInputs;
	CWidgetListBox	m_lstTemplateWidgets;
	CButton	m_cmdAddWidget;
	CWidgetTemplateListBox	m_lstTemplates;
	CButton	m_cmdEditMixer;
	CButton	m_cmdDeleteMixer;
	CButton	m_cmdDeleteOutput;
	CButton	m_cmdDeleteInput;
	CButton	m_cmdConnect;
	CWidgetComboBox	m_cmbSourceWidget;
	COutputComboBox	m_cmbSourceOutput;
	CWidgetComboBox	m_cmbDestWidget;
	CInputComboBox	m_cmbDestInput;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditTemplateDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEditTemplateDlg)
	afx_msg void OnDblclkLstWidgets();
	afx_msg void OnSelchangeLstWidgets();
	afx_msg void OnSelchangeCmbDestInput();
	afx_msg void OnSelchangeCmbDestWidget();
	afx_msg void OnSelchangeCmbSourceOutput();
	afx_msg void OnSelchangeCmbSourceWidget();
	afx_msg void OnCmdAddInput();
	afx_msg void OnCmdAddOutput();
	afx_msg void OnCmdAddWidget();
	afx_msg void OnCmdConnect();
	afx_msg void OnCmdDeleteInput();
	afx_msg void OnCmdDeleteOutput();
	afx_msg void OnCmdDeleteWidget();
	afx_msg void OnCmdEditMixer();
	afx_msg void OnSelchangeLstInputs();
	afx_msg void OnSelchangeLstOutputs();
	virtual BOOL OnInitDialog();
	afx_msg void OnCmdFreeze();
	afx_msg void OnSelchangeLstTemplateWidgets();
	afx_msg void OnDblclkLstTemplateWidgets();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDITTEMPLATEDLG_H__B23BC923_55E5_11D2_BB29_F5D419D58836__INCLUDED_)
