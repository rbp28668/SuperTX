// Form.cpp: implementation of the CForm class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SuperTX.h"
#include "Display.h"
#include "Form.h"
#include "FormManager.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CForm::CForm(CFormManager* pManager)
: m_pManager(pManager)
, m_rClient(0,0,pManager->Display().Width(), pManager->Display().Height())
{
  assert(pManager);

  // Allow for title bar in client area:
  // Get size of a space in ix & iy for scaling
  int iy = 0;
  int ix = 0;
  Manager()->Display().TextExtent(" ",ix,iy,Font());

  m_rClient.top += 2*iy;
}

CForm::~CForm()
{

}

CFormManager* CForm::Manager()
{
  assert(this);
  return m_pManager;
}

const CRect& CForm::Client() const
{
  assert(this);
  return m_rClient;
}

void CForm::SetButton(int idx, const std::string& strName)
{
  assert(this);

  const int iBorder = 4;  // allow 4 pixels to allow for border
                          // around text

  // Get size of a space in ix & iy for scaling
  int iy = 0;
  int ix = 0;
  Manager()->Display().TextExtent(" ",ix,iy,Font());
  iy = Manager()->Display().Height() / BUTTONS;

  // & size of the text string
  int cx,cy;
  Manager()->Display().TextExtent(strName,cx,cy,Font());

  if(idx < BUTTONS/2) // left side
    {
    ix = iBorder;  
    iy *= (1 + 2*idx);
    
    int iRight = cx + 2 * iBorder;
    if(iRight > m_rClient.left)
      m_rClient.left = iRight;
    }
  else // right side
    {
    iy *= (1 + 2*(idx-BUTTONS/2));
    int iLeft = Manager()->Display().Width() - cx - 2*iBorder;
    ix = iLeft + iBorder;
    if(iLeft < m_rClient.right)
      m_rClient.right = iLeft;
    }
  iy -= cy/2;

  // Draw a button border
  Manager()->Display().Rectangle(ix-1, iy-1, ix+cx, iy+cy);
  Manager()->Display().Line(ix-2, iy+cy+1, ix+cx+1, iy+cy+1);
  Manager()->Display().Line(ix+cx+1, iy+cy+1, ix+cx+1, iy-2);
  Manager()->Display().Rectangle(ix-3, iy-3, ix+cx+2, iy+cy+2);

  // and internal text
  Manager()->Display().TextBack(strName,ix,iy,Font(),false);
}

void CForm::SetButton(int idx, const BitmapT* pbmp)
{
  assert(this);

  int iy = 0;
  int ix = 0;
  Manager()->Display().TextExtent(" ",ix,iy,Font());
  iy = Manager()->Display().Height() / BUTTONS;

  int cx = pbmp->m_iWidth;
  int cy = pbmp->m_iHeight;
  
  if(idx < BUTTONS/2) // left side
    {
    iy *= (1 + 2*idx);
    if(ix + cx > m_rClient.left)
      m_rClient.left = ix + cx;
    }
  else // right side
    {
    iy *= (1 + 2*(idx-BUTTONS/2));
    ix = Manager()->Display().Width() - ix - cx;
    if(ix < m_rClient.right)
      m_rClient.right = ix;
    }
  iy -= cy/2;

  Manager()->Display().Draw(*pbmp, ix, iy);
}

const FontT& CForm::Font() const
{
  assert(this);
  return font8;
}

void CForm::SetCaption(const std::string& strCaption)
{
  assert(this);

  // Get size of a space in ix & iy for scaling
  int iy = 0;
  int ix = 0;
  Manager()->Display().TextExtent(" ",ix,iy,Font());
  
  // left justify text, 1/2 char in
  Manager()->Display().Text(strCaption, ix/2, iy/2, Font());
  
  Manager()->Display().Line(0,iy*2,Manager()->Display().Width(),0);
}

CRect CForm::GetDisplayArea(int ixPix, int iyPix)
{
  assert(this);
  return CRect(0,0,0,0);
}

