// SuperTXDlg.h : header file
//

#if !defined(AFX_SUPERTXDLG_H__1B7F50E7_2B12_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_SUPERTXDLG_H__1B7F50E7_2B12_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CSuperTXDlg dialog


// User interface bits
#include "StickUnit.h"
#include "LCDDisplay.h"
#include "ToggleSwitch.h"
#include "Slider.h"
#include "Knob.h"
#include "Display.h"

#include "Form.h"
#include "FormManager.h"



/**********************************************************************
* Class: CSuperTXDlg
* Main dialog for simulating a transmitter
**********************************************************************/
class CSuperTXDlg : public CDialog
{
  CDisplay m_display;
  
  CFormManager m_formManager;

// Construction
public:
	CSuperTXDlg(CWnd* pParent = NULL);	// standard constructor
  ~CSuperTXDlg();

// Dialog Data
	//{{AFX_DATA(CSuperTXDlg)
	enum { IDD = IDD_SUPERTX_DIALOG };
	CKnob	m_knob2;
	CKnob	m_knob1;
	CToggleSwitch	m_sw6;
	CToggleSwitch	m_sw5;
	CSlider	m_slider2;
	CSlider	m_slider1;
	CToggleSwitch	m_sw4;
	CToggleSwitch	m_sw3;
	CToggleSwitch	m_sw2;
	CToggleSwitch	m_sw1;
	CLCDDisplay	m_displayDevice;
	CStickUnit	m_stkRight;
	CStickUnit	m_stkLeft;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSuperTXDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSuperTXDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDestroy();
	afx_msg void OnCmdEdit();
	afx_msg void OnCmdMisc1();
	afx_msg void OnCmdMisc2();
	afx_msg void OnCmdMisc3();
	afx_msg void OnCmdMisc4();
	afx_msg void OnCmdMisc5();
	afx_msg void OnCmdMisc6();
	afx_msg void OnCmdMisc7();
	afx_msg void OnCmdMisc8();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:

  // Get at all the controls:
  const CStickUnit&	LeftStick() const {return m_stkLeft;}
  const CStickUnit&	RightStick() const {return m_stkRight;}

  const CSlider& Aux1() const	{return m_slider1;}
  const CSlider& Aux2() const {return m_slider2;}
  const CKnob& Aux3() const {return	m_knob1;}
  const CKnob& Aux4() const {return m_knob2;}
	
  const CToggleSwitch& Sw1() const {return m_sw1;}
  const CToggleSwitch& Sw2() const {return m_sw2;}
  const CToggleSwitch& Sw3() const {return m_sw3;}
  const CToggleSwitch& Sw4() const {return m_sw4;}
  const CToggleSwitch& Sw5() const {return m_sw5;}
  const CToggleSwitch& Sw6() const {return m_sw6;}

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUPERTXDLG_H__1B7F50E7_2B12_11D2_BB29_F5D419D58836__INCLUDED_)
