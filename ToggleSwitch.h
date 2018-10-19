#if !defined(AFX_TOGGLESWITCH_H__D11B6061_3215_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_TOGGLESWITCH_H__D11B6061_3215_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// ToggleSwitch.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CToggleSwitch window

/**********************************************************************
* Class: CToggleSwitch
* Windows control for simulating a 2 position toggle switch
**********************************************************************/
class CToggleSwitch : public CButton
{
  bool m_blOn;
// Construction
public:
	CToggleSwitch();

// Attributes
public:
  bool State() const {return m_blOn;}
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CToggleSwitch)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CToggleSwitch();

	// Generated message map functions
protected:
	//{{AFX_MSG(CToggleSwitch)
	afx_msg void OnClicked();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOGGLESWITCH_H__D11B6061_3215_11D2_BB29_F5D419D58836__INCLUDED_)
