// NewWidgetDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SuperTX.h"
#include "NewWidgetDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNewWidgetDlg dialog


CNewWidgetDlg::CNewWidgetDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNewWidgetDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNewWidgetDlg)
	m_strName = _T("");
	//}}AFX_DATA_INIT
}


void CNewWidgetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNewWidgetDlg)
	DDX_Control(pDX, IDOK, m_cmdOK);
	DDX_Control(pDX, IDC_EDT_WIDGET_NAME, m_edtName);
	DDX_Text(pDX, IDC_EDT_WIDGET_NAME, m_strName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNewWidgetDlg, CDialog)
	//{{AFX_MSG_MAP(CNewWidgetDlg)
	ON_EN_CHANGE(IDC_EDT_WIDGET_NAME, OnChangeEdtWidgetName)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNewWidgetDlg message handlers

void CNewWidgetDlg::OnChangeEdtWidgetName() 
{
  m_cmdOK.EnableWindow(UpdateData() && !m_strName.IsEmpty());
}
