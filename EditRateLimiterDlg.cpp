// EditRateLimiterDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SuperTX.h"
#include "EditRateLimiterDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEditRateLimiterDlg dialog


CEditRateLimiterDlg::CEditRateLimiterDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEditRateLimiterDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEditRateLimiterDlg)
	m_iTransitTime = 0;
	//}}AFX_DATA_INIT
}


void CEditRateLimiterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEditRateLimiterDlg)
	DDX_Control(pDX, IDOK, m_cmdOK);
	DDX_Text(pDX, IDC_EDT_TRANSIT_TIME, m_iTransitTime);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEditRateLimiterDlg, CDialog)
	//{{AFX_MSG_MAP(CEditRateLimiterDlg)
	ON_EN_CHANGE(IDC_EDT_TRANSIT_TIME, OnChangeEdtTransitTime)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEditRateLimiterDlg message handlers

void CEditRateLimiterDlg::OnChangeEdtTransitTime() 
{
  m_cmdOK.EnableWindow(UpdateData() && m_iTransitTime > 0);
}
