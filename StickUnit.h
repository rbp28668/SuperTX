#if !defined(AFX_STICKUNIT_H__1B7F50EF_2B12_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_STICKUNIT_H__1B7F50EF_2B12_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// StickUnit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStickUnit window

/**********************************************************************
* Class: CStickUnit
* Windows control to simulate a stick unit on a tramsmitter
**********************************************************************/
class CStickUnit : public CButton
{
  CPoint m_ptStick;
  CRect m_rectBounds;

  int m_cxSize;
  int m_cySize;

  int m_nRadiusOuter;
  int m_nRadiusInner;

  bool m_blFirstPaint;
  bool m_blMouseCapture;

  void CheckBounds(CPoint& pt);

// Construction
public:
	CStickUnit();

// Attributes
public:

// Operations
  short XPosition() const;
  short YPosition() const;

public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStickUnit)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CStickUnit();

	// Generated message map functions
protected:
	//{{AFX_MSG(CStickUnit)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STICKUNIT_H__1B7F50EF_2B12_11D2_BB29_F5D419D58836__INCLUDED_)
