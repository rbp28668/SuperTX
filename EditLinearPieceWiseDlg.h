#if !defined(AFX_EDITLINEARPIECEWISEDLG_H__831D71E2_5B97_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_EDITLINEARPIECEWISEDLG_H__831D71E2_5B97_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// EditLinearPieceWiseDlg.h : header file
//

#include "LinearPieceWise.h"

/////////////////////////////////////////////////////////////////////////////
// CEditLinearPieceWiseDlg dialog

/**********************************************************************
* Class: CEditLinearPieceWiseDlg
* Dialog class for editing a CLinearPieceWise widget
**********************************************************************/
class CEditLinearPieceWiseDlg : public CDialog
{
  typedef std::list<CSegment> SegmentList;

  bool m_blHavePositions; // false if positions not init
  CRect m_rOK;      // initial position of OK button
  CRect m_rCancel;  // initial position of cancel button
  CRect m_rClient;  // initial size of client rect.

  int m_cxClient;   // current size of client
  int m_cyClient;

  CRect m_rPaint;   // graphing area
  CPoint m_ptCentre; // and its centre
  int m_ixScale;    // dist from left margin to centre
  int m_iyScale;    // dist from top margin to centre

  CLinearPieceWise* m_plpw;
  SegmentList m_segments;

  CLinearPieceWise::SegmentList::iterator m_iterNearest;
  bool m_blDraggingPoint;

// Construction
public:
	CEditLinearPieceWiseDlg(CLinearPieceWise* plpw, CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEditLinearPieceWiseDlg)
	enum { IDD = IDD_EDIT_LPW };
	CButton	m_cmdOK;
	CButton	m_cmdCancel;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditLinearPieceWiseDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
  void CalcGraphRect();

	// Generated message map functions
	//{{AFX_MSG(CEditLinearPieceWiseDlg)
	afx_msg void OnPaint();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDITLINEARPIECEWISEDLG_H__831D71E2_5B97_11D2_BB29_F5D419D58836__INCLUDED_)
