// NewTemplateDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SuperTX.h"
#include "NewTemplateDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNewTemplateDlg dialog


CNewTemplateDlg::CNewTemplateDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNewTemplateDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNewTemplateDlg)
	m_strName = _T("");
	//}}AFX_DATA_INIT
}


void CNewTemplateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNewTemplateDlg)
	DDX_Control(pDX, IDOK, m_cmdOK);
	DDX_Text(pDX, IDC_EDT_TEMPLATE_NAME, m_strName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNewTemplateDlg, CDialog)
	//{{AFX_MSG_MAP(CNewTemplateDlg)
	ON_EN_CHANGE(IDC_EDT_TEMPLATE_NAME, OnChangeEdtTemplateName)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNewTemplateDlg message handlers

void CNewTemplateDlg::OnChangeEdtTemplateName() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function to send the EM_SETEVENTMASK message to the control
	// with the ENM_CHANGE flag ORed into the lParam mask.
	
	// TODO: Add your control notification handler code here
	
}
