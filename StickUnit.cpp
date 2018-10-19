// StickUnit.cpp : implementation file
//

#include "stdafx.h"
#include "StickUnit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStickUnit

CStickUnit::CStickUnit()
: m_blFirstPaint(true)
, m_blMouseCapture(false)
, m_ptStick(1,1)
, m_rectBounds(0,0,2,2)
{
}

CStickUnit::~CStickUnit()
{
}

short CStickUnit::XPosition() const
{
  assert(this);
  return short(4096l * long(m_ptStick.x - m_rectBounds.left)/m_rectBounds.Width());
}

short CStickUnit::YPosition() const
{
  assert(this);
  return short(4096l * long(m_ptStick.y - m_rectBounds.top)/m_rectBounds.Height());
}




BEGIN_MESSAGE_MAP(CStickUnit, CButton)
	//{{AFX_MSG_MAP(CStickUnit)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CStickUnit::CheckBounds(CPoint& pt)
{
  assert(this);
  pt.x = max(m_rectBounds.left, pt.x);
  pt.x = min(m_rectBounds.right, pt.x);
  pt.y = max(m_rectBounds.top, pt.y);
  pt.y = min(m_rectBounds.bottom, pt.y);
}


/////////////////////////////////////////////////////////////////////////////
// CStickUnit message handlers

void CStickUnit::OnLButtonDown(UINT nFlags, CPoint point) 
{
  CheckBounds(point);
  m_ptStick = point;

  SetCapture();
  m_blMouseCapture = true;

  RedrawWindow();
}

void CStickUnit::OnLButtonUp(UINT nFlags, CPoint point) 
{
  CheckBounds(point);
  m_ptStick = point;

  ReleaseCapture();
  m_blMouseCapture = false;

  RedrawWindow();
}

void CStickUnit::OnMouseMove(UINT nFlags, CPoint point) 
{
  if(m_blMouseCapture)
    {
    CheckBounds(point);
    m_ptStick = point;

    RedrawWindow();
    }
}

void CStickUnit::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
  CDC* pDC = CDC::FromHandle(lpDrawItemStruct->hDC);
  
  CBrush* pBrushOld = static_cast<CBrush*>(pDC->SelectStockObject(DKGRAY_BRUSH));
  CPen* pPenOld = static_cast<CPen*>(pDC->SelectStockObject(WHITE_PEN));

  CRect r(lpDrawItemStruct->rcItem);

  // First time we paint, note the size for later & center stick
  if(m_blFirstPaint)
    {
    m_cxSize = r.Width();
    m_cySize = r.Height();

    m_nRadiusOuter = min(m_cxSize / 2, m_cySize / 2);
    m_nRadiusInner = m_nRadiusOuter/10;
    m_rectBounds = r;
    m_rectBounds.InflateRect(-m_nRadiusInner, -m_nRadiusInner);

    m_ptStick.x = m_cxSize / 2;
    m_ptStick.y = m_cySize / 2;

    m_blFirstPaint = false;
    }

  CBrush brBack;
  if(brBack.CreateStockObject(DKGRAY_BRUSH)) // dark grey
    {
    pDC->FillRect(r,&brBack);
    }


  int ix = (r.right + r.left) / 2;
  int iy = (r.bottom + r.top) / 2;

  pDC->Ellipse(ix-m_nRadiusOuter,iy-m_nRadiusOuter
      ,ix+m_nRadiusOuter, iy+m_nRadiusOuter);

  // White dot at current stick pos.
  pDC->SelectStockObject(WHITE_BRUSH);
  pDC->Ellipse(m_ptStick.x - m_nRadiusInner, m_ptStick.y - m_nRadiusInner
      ,m_ptStick.x + m_nRadiusInner, m_ptStick.y + m_nRadiusInner);

  pDC->SelectObject(pPenOld);
  pDC->SelectObject(pBrushOld);
}


BOOL CStickUnit::OnEraseBkgnd(CDC* pDC) 
{
  return TRUE;	// NOP to avoid flicker when redrawing.
}
