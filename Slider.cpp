// Slider.cpp : implementation file
//

#include "stdafx.h"
#include "Slider.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSlider

CSlider::CSlider()
: m_blFirstPaint(true)
, m_blMouseCapture(false)
, m_iMax(2)
, m_iMin(0)
, m_iPosition(1)
{
}

CSlider::~CSlider()
{
}

short CSlider::Position() const
{
  return short(4096L * long(m_iPosition - m_iMin) / long(m_iMax - m_iMin));
}

BEGIN_MESSAGE_MAP(CSlider, CButton)
	//{{AFX_MSG_MAP(CSlider)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSlider message handlers

void CSlider::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
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

    m_iPosition = max(m_cxSize, m_cySize) / 2;

    m_iWidth = min(m_cxSize,m_cySize);
    m_iLength = max(m_cxSize,m_cySize);

    if(m_cxSize > m_cySize) // horizontal
      {
      m_iMin = r.left + m_iWidth/4 ;
      m_iMax = r.right - m_iWidth/4;
      }
    else
      {
      m_iMin = r.top + m_iWidth/4;
      m_iMax = r.bottom - m_iWidth/4;
      }

    m_blFirstPaint = false;
    }

  CBrush brBack;
  if(brBack.CreateStockObject(LTGRAY_BRUSH)) // dark grey
    {
    pDC->FillRect(r,&brBack);
    }

  int ix = (r.right + r.left) / 2;
  int iy = (r.bottom + r.top) / 2;


  CBrush brFore;
  if(brFore.CreateStockObject(DKGRAY_BRUSH))
    {
    int iw8 = m_iWidth/8;
    int il2 = m_iLength/2;

    if(m_cxSize > m_cySize) // horizontal slider
      {
      CRect rSlide(ix - il2, iy - iw8, ix + il2, iy + iw8);
      pDC->FillRect(&rSlide, &brFore);
      }
    else // vertical slider
      {
      CRect rSlide(ix - iw8, iy - il2, ix + iw8, iy + il2);
      pDC->FillRect(&rSlide,&brFore);
      }
    }

  pDC->SelectStockObject(BLACK_PEN);
  pDC->SelectStockObject(WHITE_BRUSH);
  int iw4 = m_iWidth/4;
  int iw2 = m_iWidth/2;
  if(m_cxSize > m_cySize) // horizontal slider
    {
    CRect rThumb(m_iPosition - iw4, iy - iw2, m_iPosition + iw4, iy + iw2);
    pDC->Rectangle(&rThumb);
    }
  else // vertical slider
    {
    CRect rThumb(ix - iw2, m_iPosition - iw4, ix + iw2, m_iPosition + iw4);
    pDC->Rectangle(&rThumb);
    }


  pDC->SelectObject(pPenOld);
  pDC->SelectObject(pBrushOld);
}

void CSlider::OnLButtonDown(UINT nFlags, CPoint point) 
{
  if(m_cxSize > m_cySize) // horizontal slider
    m_iPosition = point.x;
  else
    m_iPosition = point.y;

  m_iPosition = max(m_iMin, m_iPosition);
  m_iPosition = min(m_iMax, m_iPosition);

  SetCapture();
  m_blMouseCapture = true;
  RedrawWindow(NULL,NULL,RDW_NOERASE | RDW_INVALIDATE);
}

void CSlider::OnLButtonUp(UINT nFlags, CPoint point) 
{
  if(m_cxSize > m_cySize) // horizontal slider
    m_iPosition = point.x;
  else
    m_iPosition = point.y;

  m_iPosition = max(m_iMin, m_iPosition);
  m_iPosition = min(m_iMax, m_iPosition);

  ReleaseCapture();
  m_blMouseCapture = false;
  RedrawWindow(NULL,NULL,RDW_NOERASE | RDW_INVALIDATE);
}

void CSlider::OnMouseMove(UINT nFlags, CPoint point) 
{
  if(m_blMouseCapture)
    {
    if(m_cxSize > m_cySize) // horizontal slider
      m_iPosition = point.x;
    else
      m_iPosition = point.y;

    m_iPosition = max(m_iMin, m_iPosition);
    m_iPosition = min(m_iMax, m_iPosition);
    }
 RedrawWindow(NULL,NULL,RDW_NOERASE | RDW_INVALIDATE);
}
