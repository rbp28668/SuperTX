#if !defined(AFX_SLIDER_H__D11B6062_3215_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_SLIDER_H__D11B6062_3215_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// Slider.h : header file
//


/////////////////////////////////////////////////////////////////////////////
// CSlider window

/**********************************************************************
* Class: CSlider
* Windows control for emulating a linear potentiometer
**********************************************************************/
class CSlider : public CButton
{
  int m_iPosition;  // current position of slider
  int m_iMin; // min pos of slider
  int m_iMax; // max pos of slider

  int m_iWidth; // of slider 
  int m_iLength;
  
  int m_cxSize;
  int m_cySize;

  bool m_blFirstPaint;
  bool m_blMouseCapture;

// Construction
public:
	CSlider();

// Attributes
public:

// Operations
public:
  short Position() const;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSlider)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSlider();

	// Generated message map functions
protected:
	//{{AFX_MSG(CSlider)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SLIDER_H__D11B6062_3215_11D2_BB29_F5D419D58836__INCLUDED_)
