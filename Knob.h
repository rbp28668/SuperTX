#if !defined(AFX_KNOB_H__D11B6063_3215_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_KNOB_H__D11B6063_3215_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// Knob.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CKnob window

/**********************************************************************
* Class: CKnob
* Windows graphics tool for simulating a rotary knob
**********************************************************************/
class CKnob : public CButton
{
  CPoint m_pos;
  CPoint m_ptCentre;

  float m_fAngle;
  
  int m_cxSize;
  int m_cySize;

  int m_iRadius;

  bool m_blFirstPaint;
  bool m_blMouseCapture;

  short m_iPos;

  void SetPosition(CPoint pos);
// Construction
public:
	CKnob();

// Attributes
public:

// Operations
public:

  short Position() const;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKnob)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CKnob();

	// Generated message map functions
protected:
	//{{AFX_MSG(CKnob)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KNOB_H__D11B6063_3215_11D2_BB29_F5D419D58836__INCLUDED_)
