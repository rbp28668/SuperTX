// ToggleSwitch.cpp : implementation file
//

#include "stdafx.h"
#include "ToggleSwitch.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CToggleSwitch

CToggleSwitch::CToggleSwitch()
{
  m_blOn = false;
}

CToggleSwitch::~CToggleSwitch()
{
}


BEGIN_MESSAGE_MAP(CToggleSwitch, CButton)
	//{{AFX_MSG_MAP(CToggleSwitch)
	ON_CONTROL_REFLECT(BN_CLICKED, OnClicked)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CToggleSwitch message handlers

void CToggleSwitch::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
  CDC* pDC = CDC::FromHandle(lpDrawItemStruct->hDC);
  
  CRect r(lpDrawItemStruct->rcItem);

  CBrush* pBrushOld = static_cast<CBrush*>(pDC->SelectStockObject(DKGRAY_BRUSH));
  CPen* pPenOld = static_cast<CPen*>(pDC->SelectStockObject(WHITE_PEN));

  // Erase background
  CBrush brBack;
  if(brBack.CreateStockObject(LTGRAY_BRUSH)) 
    pDC->FillRect(r,&brBack);


  // Centered circle for base, white on dark-grey
  pDC->SelectStockObject(DKGRAY_BRUSH);
  int ix = (r.right + r.left) / 2;
  int iy = (r.bottom + r.top) / 2;
  int nRadius = min(r.Width() / 2, r.Height() / 2);

  pDC->Ellipse(ix-nRadius,iy-nRadius
      ,ix+nRadius, iy+nRadius);

  nRadius /= 2;

  // Draw switch toggle with 2 ellipses & a filled rectangle
  pDC->SelectStockObject(WHITE_BRUSH);

  pDC->Ellipse(ix-nRadius,iy-nRadius/2
    ,ix+nRadius, iy+nRadius/2);

  int iyEnd = 0;

  if(m_blOn) // switch down
    {
    iyEnd = iy + (r.Height() - nRadius)/2;
    }
  else
    {
    iyEnd = iy - (r.Height() - nRadius)/2;
    }

  CRect rSwitch(ix - nRadius, iyEnd, ix + nRadius, iy);
  rSwitch. NormalizeRect( );
  pDC->FillSolidRect(&rSwitch,RGB(255,255,255));

  pDC->SelectStockObject(DKGRAY_BRUSH);
  pDC->Ellipse(ix-nRadius,iyEnd-nRadius/2
    ,ix+nRadius, iyEnd+nRadius/2);

  pDC->SelectObject(pPenOld);
  pDC->SelectObject(pBrushOld);
}

void CToggleSwitch::OnClicked() 
{
  m_blOn = !m_blOn;
  RedrawWindow();
}
