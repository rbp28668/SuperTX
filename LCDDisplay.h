#if !defined(AFX_LCDDISPLAY_H__F71B3A01_2D61_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_LCDDISPLAY_H__F71B3A01_2D61_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// LCDDisplay.h : header file
//

#include "BitmapDisplay.h"


/////////////////////////////////////////////////////////////////////////////
// CLCDDisplay window

/**********************************************************************
* Class: CLCDDisplay
* A windows control for simulating a Liquid Crystal Display
**********************************************************************/
class CLCDDisplay : public CButton, public CBitmapDisplay
{

	int m_nxSize;       // size of window
	int m_nySize;       // size of window
	int m_nxPadded;     // x size padded multiple of 4 bytes
	
	HGLOBAL m_hGlobal;  // for memory
  DWORD m_dwSize;     // size allocated for display
	BYTE* m_lpMem;// address of global memory block for DIB
	BYTE* m_lpBmp;// actual bitmap within DIB

// Construction
public:
	CLCDDisplay();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLCDDisplay)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	//}}AFX_VIRTUAL

  // CBitmapDisplay:
  virtual int Width() const;
  virtual int Height() const;
	virtual void Clear();
	virtual void WriteBit(int ix, int iy, bool blBit);
	virtual void Refresh();

// Implementation
public:
	virtual ~CLCDDisplay();

	// Generated message map functions
protected:
	//{{AFX_MSG(CLCDDisplay)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LCDDISPLAY_H__F71B3A01_2D61_11D2_BB29_F5D419D58836__INCLUDED_)
