// EditDelayDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SuperTX.h"
#include "EditDelayDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEditDelayDlg dialog


CEditDelayDlg::CEditDelayDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEditDelayDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEditDelayDlg)
	m_iDelay = 0;
	//}}AFX_DATA_INIT
}


void CEditDelayDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEditDelayDlg)
	DDX_Control(pDX, IDOK, m_cmdOK);
	DDX_Text(pDX, IDC_EDT_DELAY, m_iDelay);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEditDelayDlg, CDialog)
	//{{AFX_MSG_MAP(CEditDelayDlg)
	ON_EN_CHANGE(IDC_EDT_DELAY, OnChangeEdtDelay)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEditDelayDlg message handlers

void CEditDelayDlg::OnChangeEdtDelay() 
{
  BOOL blEnable = UpdateData() && m_iDelay != 0;
  m_cmdOK.EnableWindow(blEnable);	
}
