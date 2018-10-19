// Knob.cpp : implementation file
//

#include "stdafx.h"
#include "math.h"
#include "Knob.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CKnob

CKnob::CKnob()
: m_blFirstPaint(true)
, m_blMouseCapture(false)
, m_fAngle(0.0f)
, m_cxSize(1)
, m_cySize(1)
, m_iRadius(1)
, m_iPos(2048)
{
}

CKnob::~CKnob()
{
}

short CKnob::Position() const
{
  return m_iPos;
}


BEGIN_MESSAGE_MAP(CKnob, CButton)
	//{{AFX_MSG_MAP(CKnob)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CKnob::SetPosition(CPoint pos)
{
  m_pos = pos;

  const float PI = 3.1415926536f;
  const float fMax = 120 * PI / 180;
  const float fMin = 60 * PI / 180;

  int dx = m_pos.x - m_ptCentre.x;
  int dy = m_pos.y - m_ptCentre.y;

  m_fAngle = float(atan2(dy,dx));
  if(m_fAngle > fMin && m_fAngle < fMax)
    {
    if(m_fAngle > (fMin + fMax)/2)
      m_fAngle = fMax;
    else
      m_fAngle = fMin;
    }

  // Offset to set 0 point 
  float fPos = m_fAngle + 2*PI - fMax;
  if(fPos >= 2*PI)
    fPos -= 2*PI;

  fPos /= (2*PI - (fMax - fMin));

  m_iPos = short(4096 * fPos);
}

/////////////////////////////////////////////////////////////////////////////
// CKnob message handlers

void CKnob::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
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

    m_iRadius = min(m_cxSize, m_cySize) /2;
    m_ptCentre = r.CenterPoint();

    SetPosition(CPoint(m_ptCentre.x, r.top));
    
    m_blFirstPaint = false;
    }

  CBrush brBack;
  if(brBack.CreateStockObject(LTGRAY_BRUSH))
    {
    pDC->FillRect(r,&brBack);
    }

  pDC->Ellipse(m_ptCentre.x-m_iRadius, m_ptCentre.y-m_iRadius
            , m_ptCentre.x+m_iRadius, m_ptCentre.y+m_iRadius);

  pDC->MoveTo(m_ptCentre);


  CPoint ptEnd;
  ptEnd.x = m_ptCentre.x + long(m_iRadius * cos(m_fAngle));
  ptEnd.y = m_ptCentre.y + long(m_iRadius * sin(m_fAngle));

  pDC->LineTo(ptEnd);

  pDC->SelectObject(pPenOld);
  pDC->SelectObject(pBrushOld);
}

void CKnob::OnLButtonDown(UINT nFlags, CPoint point) 
{
  SetPosition(point);
  SetCapture();
  m_blMouseCapture = true;
  RedrawWindow(NULL,NULL,RDW_NOERASE | RDW_INVALIDATE);
}

void CKnob::OnLButtonUp(UINT nFlags, CPoint point) 
{
  if(m_blMouseCapture)
    {
    SetPosition(point);
    ReleaseCapture();
    m_blMouseCapture = false;
    RedrawWindow(NULL,NULL,RDW_NOERASE | RDW_INVALIDATE);
    }
}

void CKnob::OnMouseMove(UINT nFlags, CPoint point) 
{
  if(m_blMouseCapture)
    {
    SetPosition(point);
    RedrawWindow(NULL,NULL,RDW_NOERASE | RDW_INVALIDATE);
    }
}
