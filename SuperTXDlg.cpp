// SuperTXDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SuperTX.h"
#include "SuperTXDlg.h"
#include "StartupForm.h"
#include "Transmitter.h"

#include "MainEditDlg.h" // for test editing

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

/**********************************************************************
* Class: CAboutDlg
* Displays an about dialog for the simulation
**********************************************************************/
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
// CSuperTXDlg dialog
#pragma warning(disable : 4355) // this used in base member initialiser list

CSuperTXDlg::CSuperTXDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSuperTXDlg::IDD, pParent)
  , m_display(&m_displayDevice)
  , m_formManager(&m_display)
{
	//{{AFX_DATA_INIT(CSuperTXDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

  // switches & encoder need to get input from this dlg.
  Tx().Switches().Tie(this);
  Tx().ADC().Tie(this);

  // once switches & adc set up:
  Tx().Encoder().Run(); // kick off the encoder.

}

CSuperTXDlg::~CSuperTXDlg()
{
  Tx().Encoder().Stop(); // stop encoder before we shutdown
}

void CSuperTXDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSuperTXDlg)
	DDX_Control(pDX, IDC_KNOB2, m_knob2);
	DDX_Control(pDX, IDC_KNOB1, m_knob1);
	DDX_Control(pDX, IDC_TOG_6, m_sw6);
	DDX_Control(pDX, IDC_TOG_5, m_sw5);
	DDX_Control(pDX, IDC_SLD_2, m_slider2);
	DDX_Control(pDX, IDC_SLD_1, m_slider1);
	DDX_Control(pDX, IDC_TOG_4, m_sw4);
	DDX_Control(pDX, IDC_TOG_3, m_sw3);
	DDX_Control(pDX, IDC_TOG_2, m_sw2);
	DDX_Control(pDX, IDC_TOG_1, m_sw1);
	DDX_Control(pDX, IDC_SCREEN, m_displayDevice);
	DDX_Control(pDX, IDC_STK_RIGHT, m_stkRight);
	DDX_Control(pDX, IDC_STK_LEFT, m_stkLeft);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSuperTXDlg, CDialog)
	//{{AFX_MSG_MAP(CSuperTXDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_CMD_EDIT, OnCmdEdit)
	ON_BN_CLICKED(IDC_CMD_MISC1, OnCmdMisc1)
	ON_BN_CLICKED(IDC_CMD_MISC2, OnCmdMisc2)
	ON_BN_CLICKED(IDC_CMD_MISC3, OnCmdMisc3)
	ON_BN_CLICKED(IDC_CMD_MISC4, OnCmdMisc4)
	ON_BN_CLICKED(IDC_CMD_MISC5, OnCmdMisc5)
	ON_BN_CLICKED(IDC_CMD_MISC6, OnCmdMisc6)
	ON_BN_CLICKED(IDC_CMD_MISC7, OnCmdMisc7)
	ON_BN_CLICKED(IDC_CMD_MISC8, OnCmdMisc8)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSuperTXDlg message handlers

BOOL CSuperTXDlg::OnInitDialog()
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
	
  m_formManager.ShowForm(new CStartupForm(&m_formManager));

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSuperTXDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSuperTXDlg::OnPaint() 
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
HCURSOR CSuperTXDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSuperTXDlg::OnDestroy() 
{
  Tx().Encoder().Stop();
	CDialog::OnDestroy();
}

void CSuperTXDlg::OnCmdEdit() 
{
  CMainEditDlg dlg(&Tx().Encoder()
                  ,&Tx().Models()
                  ,&Tx().Templates());
  dlg.DoModal();
}

void CSuperTXDlg::OnCmdMisc1() {m_formManager.OnCmd0();}
void CSuperTXDlg::OnCmdMisc2() {m_formManager.OnCmd1();}
void CSuperTXDlg::OnCmdMisc3() {m_formManager.OnCmd2();}
void CSuperTXDlg::OnCmdMisc4() {m_formManager.OnCmd3();}
void CSuperTXDlg::OnCmdMisc5() {m_formManager.OnCmd4();}
void CSuperTXDlg::OnCmdMisc6() {m_formManager.OnCmd5();}
void CSuperTXDlg::OnCmdMisc7() {m_formManager.OnCmd6();}
void CSuperTXDlg::OnCmdMisc8() {m_formManager.OnCmd7();}
