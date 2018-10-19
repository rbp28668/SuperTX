// SuperTX.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "SuperTX.h"
#include "SuperTXDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSuperTXApp

BEGIN_MESSAGE_MAP(CSuperTXApp, CWinApp)
	//{{AFX_MSG_MAP(CSuperTXApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSuperTXApp construction

CSuperTXApp::CSuperTXApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CSuperTXApp object

CSuperTXApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CSuperTXApp initialization

BOOL CSuperTXApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CSuperTXDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

// main running routine until receive WM_QUIT or *pblExit becomes true
bool CSuperTXApp::MessageLoop(bool* pblExit)
{
	ASSERT_VALID(this);

	// for tracking the idle time state
	BOOL bIdle = TRUE;
	LONG lIdleCount = 0;

	// acquire and dispatch messages until a WM_QUIT message is received.
	while (!*pblExit)
	{
		// phase1: check to see if we can do idle work
		while (bIdle &&
			!::PeekMessage(&m_msgCur, NULL, NULL, NULL, PM_NOREMOVE))
		{
			// call OnIdle while in bIdle state
			if (!OnIdle(lIdleCount++))
				bIdle = FALSE; // assume "no idle" state
		}

		// phase2: pump messages while available
		do
		{
			// pump message, but quit on WM_QUIT
			if (!PumpMessage())
        return false;

			// reset "no idle" state after pumping "normal" message
			if (IsIdleMessage(&m_msgCur))
			{
				bIdle = TRUE;
				lIdleCount = 0;
			}

		} while (::PeekMessage(&m_msgCur, NULL, NULL, NULL, PM_NOREMOVE));
	}

  return true; // normal exit
}

CSuperTXApp& App()
{
  return theApp;
}