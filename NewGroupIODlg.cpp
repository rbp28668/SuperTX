// GetIdentifierDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SuperTX.h"
#include "NewGroupIODlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNewGroupIODlg dialog


CNewGroupIODlg::CNewGroupIODlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNewGroupIODlg::IDD, pParent)
  , m_strTitle("Enter Name")
  , m_type(CType::Analogue())
{
	//{{AFX_DATA_INIT(CNewGroupIODlg)
	m_strName = _T("");
	m_iType = 0;
	//}}AFX_DATA_INIT
}


void CNewGroupIODlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNewGroupIODlg)
	DDX_Control(pDX, IDOK, m_cmdOK);
	DDX_Text(pDX, IDC_EDT_NAME, m_strName);
	DDX_Radio(pDX, IDC_RAD_ANALOGUE, m_iType);
	//}}AFX_DATA_MAP

  if(pDX->m_bSaveAndValidate)
    {
    if(m_iType == 0)
      m_type = CType::Analogue();
    else
      m_type = CType::Digital();
    }
}


BEGIN_MESSAGE_MAP(CNewGroupIODlg, CDialog)
	//{{AFX_MSG_MAP(CNewGroupIODlg)
	ON_EN_CHANGE(IDC_EDT_NAME, OnChangeEdtName)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CNewGroupIODlg::SetTitle(const CString& strTitle)
{
  assert(this);
  m_strTitle = strTitle;
}

CType CNewGroupIODlg::Type() const
{
  return m_type;
}


/////////////////////////////////////////////////////////////////////////////
// CNewGroupIODlg message handlers

void CNewGroupIODlg::OnChangeEdtName() 
{
  UpdateData();
  m_cmdOK.EnableWindow(!m_strName.IsEmpty());
}

BOOL CNewGroupIODlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
  SetWindowText(m_strTitle);
  CenterWindow();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
