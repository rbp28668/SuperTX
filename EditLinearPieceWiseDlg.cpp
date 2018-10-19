// EditLinearPieceWiseDlg.cpp : implementation file
//

#include "stdafx.h"
#include <limits.h>
#include "SuperTX.h"
#include "EditLinearPieceWiseDlg.h"
#include "LinearPieceWise.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEditLinearPieceWiseDlg dialog


CEditLinearPieceWiseDlg::CEditLinearPieceWiseDlg(CLinearPieceWise* plpw, CWnd* pParent /*=NULL*/)
	: CDialog(CEditLinearPieceWiseDlg::IDD, pParent)
  , m_plpw(plpw)
  , m_blHavePositions(false)
  , m_blDraggingPoint(false)
{
	//{{AFX_DATA_INIT(CEditLinearPieceWiseDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

  // copy the list so we can undo the editing on cancel.
  CLinearPieceWise::SegmentList::const_iterator iter = m_plpw->Points();
  CValue x;
  CValue y;
  while(m_plpw->NextPoint(iter,x,y))
    {
    CSegment segment;
    segment.x = x;
    segment.y = y;
    m_segments.push_back(segment);
    }
}


void CEditLinearPieceWiseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEditLinearPieceWiseDlg)
	DDX_Control(pDX, IDOK, m_cmdOK);
	DDX_Control(pDX, IDCANCEL, m_cmdCancel);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEditLinearPieceWiseDlg, CDialog)
	//{{AFX_MSG_MAP(CEditLinearPieceWiseDlg)
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CEditLinearPieceWiseDlg::CalcGraphRect()
{
  int cBorder = m_rOK.top;
	m_rPaint = CRect(cBorder
              ,m_rOK.bottom + cBorder
              ,m_cxClient - cBorder
              ,m_cyClient - cBorder);

  m_ptCentre = m_rPaint.CenterPoint();

  m_ixScale = m_ptCentre.x - m_rPaint.left;
  m_iyScale = m_ptCentre.y - m_rPaint.top;
}

/////////////////////////////////////////////////////////////////////////////
// CEditLinearPieceWiseDlg message handlers

void CEditLinearPieceWiseDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
  CPen* ppenOld = static_cast<CPen*>(dc.SelectStockObject(BLACK_PEN));
  
  // Axes
  CBrush brBlack;
  brBlack.CreateStockObject(BLACK_BRUSH);
  dc.FrameRect(m_rPaint,&brBlack);

  dc.MoveTo(m_ptCentre.x, m_rPaint.top);
  dc.LineTo(m_ptCentre.x, m_rPaint.bottom);
  dc.MoveTo(m_rPaint.left, m_ptCentre.y);
  dc.LineTo(m_rPaint.right, m_ptCentre.y);
  

  // draw underlying line
  CLinearPieceWise::SegmentList::const_iterator iter = m_plpw->Points();
  dc.SelectStockObject(WHITE_PEN);
  CValue x;
  CValue y;
  if(m_plpw->NextPoint(iter,x,y))
    {
    int ix = m_ptCentre.x + x.Scale(m_ixScale);
    int iy = m_ptCentre.y - y.Scale(m_iyScale);
    dc.MoveTo(ix,iy);
    }
  while(m_plpw->NextPoint(iter,x,y))
    {
    int ix = m_ptCentre.x + x.Scale(m_ixScale);
    int iy = m_ptCentre.y - y.Scale(m_iyScale);
    dc.LineTo(ix,iy);
    }

  // and individual points
  dc.SelectStockObject(BLACK_PEN);
  iter = m_plpw->Points();
  while(m_plpw->NextPoint(iter,x,y))
    {
    const int iTickSize = 5;

    int ix = m_ptCentre.x + x.Scale(m_ixScale);
    int iy = m_ptCentre.y - y.Scale(m_iyScale);

    dc.MoveTo(ix, iy-iTickSize);
    dc.LineTo(ix, iy+iTickSize);
    dc.MoveTo(ix-iTickSize, iy);
    dc.LineTo(ix+iTickSize, iy);
    }

  dc.SelectObject(ppenOld);
}

void CEditLinearPieceWiseDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
  if(m_blDraggingPoint)
    {
    int ix = point.x - m_ptCentre.x;
    int iy = m_ptCentre.y - point.y;

    m_iterNearest->x.Set(ix, m_ixScale);
    m_iterNearest->y.Set(iy, m_iyScale);

    InvalidateRect(&m_rPaint);
    }
	
	CDialog::OnMouseMove(nFlags, point);
}

void CEditLinearPieceWiseDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
  CLinearPieceWise::SegmentList::iterator iter = m_plpw->Points();
  CLinearPieceWise::SegmentList::iterator iterThis = iter;

  CValue x;
  CValue y;
  int iNearestDist = INT_MAX;
  bool blFound = false;
  
  while(m_plpw->NextPoint(iter,x,y))
    {
    int ix = m_ptCentre.x + x.Scale(m_ixScale);
    int iy = m_ptCentre.y - y.Scale(m_iyScale);

    int dx = point.x - ix;
    int dy = point.y - iy;
    int iDist =  dx * dx + dy * dy;
    if(iDist < iNearestDist)
      {
      iNearestDist = iDist;
      m_iterNearest = iterThis;
      blFound = true;
      }
    iterThis = iter;
    }

  // if we found a "nearest" point see if it's nearest enough
  // to capture
  if(blFound)
    {
    if(iNearestDist < 25) // 5 pixels
      {
      m_blDraggingPoint = true;
      }
    }
	CDialog::OnLButtonDown(nFlags, point);
}

void CEditLinearPieceWiseDlg::OnLButtonUp(UINT nFlags, CPoint point) 
{
  int ix = point.x - m_ptCentre.x;
  int iy = m_ptCentre.y - point.y;

  if(m_blDraggingPoint)
    {
    if(m_rPaint.PtInRect(point))
      {
      m_iterNearest->x.Set(ix, m_ixScale);
      m_iterNearest->y.Set(iy, m_iyScale);
      m_plpw->Update();    
      }
    else // not in rect so delete it
      {
      m_plpw->DeletePoint(m_iterNearest);
      }
    }
  else // not dragging so create a new point
    {
    CValue x(ix, m_ixScale);
    CValue y(iy, m_iyScale);

    m_plpw->AddPoint(x,y);
    }

  m_blDraggingPoint = false; // finished with drag

	CDialog::OnLButtonUp(nFlags, point);

  Invalidate(); // force repaint.
}

BOOL CEditLinearPieceWiseDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_cmdOK.GetWindowRect(&m_rOK);
  ScreenToClient(&m_rOK);

  m_cmdCancel.GetWindowRect(&m_rCancel);
  ScreenToClient(&m_rCancel);

  GetClientRect(&m_rClient);
  m_cxClient = m_rClient.Width();
  m_cyClient = m_rClient.Height();

  CalcGraphRect();

  m_blHavePositions = true;

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CEditLinearPieceWiseDlg::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
  m_cxClient = cx;
  m_cyClient = cy;

  if(m_blHavePositions)
    {
    int dx = cx - m_rClient.Width();

    CRect rButton = m_rOK;
    rButton.OffsetRect(dx,0);
    m_cmdOK.MoveWindow(rButton);

    rButton = m_rCancel;
    rButton.OffsetRect(dx,0);
    m_cmdCancel.MoveWindow(rButton);

    CalcGraphRect();

    Invalidate();
    }
}

void CEditLinearPieceWiseDlg::OnCancel() 
{
	// restore the original list
  m_plpw->Clear();
  for(SegmentList::iterator iter = m_segments.begin()
    ; iter != m_segments.end()
    ; ++iter)
    {
    m_plpw->AddPoint(iter->x,iter->y);
    }

	CDialog::OnCancel();
}
