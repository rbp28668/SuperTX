// RXDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RX.h"
#include "RXDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRXDlg dialog

CRXDlg::CRXDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRXDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRXDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRXDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRXDlg)
	DDX_Control(pDX, IDC_PROGRESS_CH8, m_prgChan8);
	DDX_Control(pDX, IDC_PROGRESS_CH7, m_prgChan7);
	DDX_Control(pDX, IDC_PROGRESS_CH6, m_prgChan6);
	DDX_Control(pDX, IDC_PROGRESS_CH5, m_prgChan5);
	DDX_Control(pDX, IDC_PROGRESS_CH4, m_prgChan4);
	DDX_Control(pDX, IDC_PROGRESS_CH3, m_prgChan3);
	DDX_Control(pDX, IDC_PROGRESS_CH2, m_prgChan2);
	DDX_Control(pDX, IDC_PROGRESS_CH1, m_prgChan1);
	DDX_Control(pDX, IDC_LBL_STATE, m_lblState);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CRXDlg, CDialog)
	//{{AFX_MSG_MAP(CRXDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
  ON_MESSAGE(WM_RX_DATA,OnRXData)
  ON_MESSAGE(WM_RX_STATE_CHANGE,OnRXStateChanged)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRXDlg message handlers

BOOL CRXDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

  m_prgChan8.SetRange(0,4095);
  m_prgChan7.SetRange(0,4095);
  m_prgChan6.SetRange(0,4095);
  m_prgChan5.SetRange(0,4095);
  m_prgChan4.SetRange(0,4095);
  m_prgChan3.SetRange(0,4095);
  m_prgChan2.SetRange(0,4095);
  m_prgChan1.SetRange(0,4095);

  m_rx.SetNotify(m_hWnd);
  m_rx.Run();
  
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CRXDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CRXDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CRXDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CRXDlg::OnDestroy() 
{
  m_rx.Stop();
	CDialog::OnDestroy();
}

afx_msg LONG CRXDlg::OnRXData(WPARAM wParam, LPARAM lParam)
{
  //const CDataPacket* pPacket = static_cast<const CDataPacket*>(lParam);
  const CDataPacket* pPacket = (const CDataPacket*)(lParam);
  if(pPacket)
    {
    m_prgChan1.SetPos((*pPacket)[0]);
    m_prgChan2.SetPos((*pPacket)[1]);
    m_prgChan3.SetPos((*pPacket)[2]);
    m_prgChan4.SetPos((*pPacket)[3]);
    m_prgChan5.SetPos((*pPacket)[4]);
    m_prgChan6.SetPos((*pPacket)[5]);
    m_prgChan7.SetPos((*pPacket)[6]);
    m_prgChan8.SetPos((*pPacket)[7]);
    }
  return 0;
}

afx_msg LONG CRXDlg::OnRXStateChanged(WPARAM wParam, LPARAM lParam)
{
  RFReceiver::StateT state = static_cast<RFReceiver::StateT>(wParam);
  LPCSTR pszMsg = "UNKNOWN";

  switch(state)
    {
    case RFReceiver::IDLE:      pszMsg = "Idle";      break;
    case RFReceiver::LISTENING: pszMsg = "Listening"; break;
    case RFReceiver::RECEIVING: pszMsg = "Receiving"; break;
    case RFReceiver::FAILSAFE:  pszMsg = "Failsafe";  break;
    default:  break;
    }
  
  m_lblState.SetWindowText(pszMsg);
  return 0;  
}

