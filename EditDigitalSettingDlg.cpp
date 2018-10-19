// EditDigitalSettingDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SuperTX.h"
#include "EditDigitalSettingDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEditDigitalSettingDlg dialog


CEditDigitalSettingDlg::CEditDigitalSettingDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEditDigitalSettingDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEditDigitalSettingDlg)
	m_iOnOff = -1;
	m_strTitle = _T("");
	//}}AFX_DATA_INIT
}


void CEditDigitalSettingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEditDigitalSettingDlg)
	DDX_Radio(pDX, IDC_RAD_ON, m_iOnOff);
	DDX_Text(pDX, IDC_LBL_TITLE, m_strTitle);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEditDigitalSettingDlg, CDialog)
	//{{AFX_MSG_MAP(CEditDigitalSettingDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEditDigitalSettingDlg message handlers

BOOL CEditDigitalSettingDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
  if(m_blVal)
    m_iOnOff = 0; // on
  else
    m_iOnOff = 1;

  UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CEditDigitalSettingDlg::OnOK() 
{
  UpdateData();
	m_blVal = m_iOnOff == 0;
	CDialog::OnOK();
}
