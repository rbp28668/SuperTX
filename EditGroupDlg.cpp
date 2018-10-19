// EditGroupDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SuperTX.h"
#include "EditGroupDlg.h"
#include "EditContext.h"
#include "Widgets.hpp"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEditGroupDlg dialog


CEditGroupDlg::CEditGroupDlg(CWidgetList* pWidgets, const CEditContext* pContext, CWnd* pParent /*=NULL*/)
	: CDialog(CEditGroupDlg::IDD, pParent)
  , m_pContext(pContext)
  , m_pWidgets(pWidgets)
{
	//{{AFX_DATA_INIT(CEditGroupDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CEditGroupDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEditGroupDlg)
	DDX_Control(pDX, IDC_LST_WIDGETS, m_lstWidgets);
	DDX_Control(pDX, IDC_CMD_EDIT, m_cmdEdit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEditGroupDlg, CDialog)
	//{{AFX_MSG_MAP(CEditGroupDlg)
	ON_LBN_SELCHANGE(IDC_LST_WIDGETS, OnSelchangeLstWidgets)
	ON_BN_CLICKED(IDC_CMD_EDIT, OnCmdEdit)
	ON_LBN_DBLCLK(IDC_LST_WIDGETS, OnDblclkLstWidgets)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEditGroupDlg message handlers

void CEditGroupDlg::OnSelchangeLstWidgets() 
{
  m_cmdEdit.EnableWindow(m_lstWidgets.Selected() != 0);
}

void CEditGroupDlg::OnCmdEdit() 
{
  assert(this);
  assert(m_lstWidgets.Selected());
  m_lstWidgets.Selected()->Edit(m_pContext);
}

BOOL CEditGroupDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_lstWidgets.UpdateEditable(*m_pWidgets);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CEditGroupDlg::OnDblclkLstWidgets() 
{
  OnCmdEdit();	
}
