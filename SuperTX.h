// SuperTX.h : main header file for the SUPERTX application
//

#if !defined(AFX_SUPERTX_H__1B7F50E5_2B12_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_SUPERTX_H__1B7F50E5_2B12_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols


/////////////////////////////////////////////////////////////////////////////
// CSuperTXApp:
// See SuperTX.cpp for the implementation of this class
//

/**********************************************************************
* Class: CSuperTXApp
* Tramsmitter simulation application class
**********************************************************************/
class CSuperTXApp : public CWinApp
{
public:
	CSuperTXApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSuperTXApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
  bool MessageLoop(bool* pblExit);
	//{{AFX_MSG(CSuperTXApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


CSuperTXApp& App();

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.


#endif // !defined(AFX_SUPERTX_H__1B7F50E5_2B12_11D2_BB29_F5D419D58836__INCLUDED_)
