// NewModelDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SuperTX.h"
#include "NewModelDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNewModelDlg dialog


CNewModelDlg::CNewModelDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNewModelDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNewModelDlg)
	m_strName = _T("");
	//}}AFX_DATA_INIT
}


void CNewModelDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNewModelDlg)
	DDX_Control(pDX, IDOK, m_cmdOK);
	DDX_Text(pDX, IDC_EDT_MODEL_NAME, m_strName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNewModelDlg, CDialog)
	//{{AFX_MSG_MAP(CNewModelDlg)
	ON_EN_CHANGE(IDC_EDT_MODEL_NAME, OnChangeEdtModelName)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNewModelDlg message handlers

void CNewModelDlg::OnChangeEdtModelName() 
{
  BOOL blOK = UpdateData() && !m_strName.IsEmpty();
  m_cmdOK.EnableWindow(blOK);
    
}
