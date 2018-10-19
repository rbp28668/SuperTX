// LCDDisplay.cpp : implementation file
//

#include "stdafx.h"
#include "LCDDisplay.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define DIB_COLOURS 2 // Foreground and background
#define DIB_BACKGROUND 0
#define DIB_FOREGROUND 1

/////////////////////////////////////////////////////////////////////////////
// CLCDDisplay

CLCDDisplay::CLCDDisplay()
{
  BOOL blOK = TRUE;

//	m_nxSize = 320;
//	m_nySize = 240;
	m_nxSize = 240;
	m_nySize = 128;

  m_nxPadded = (m_nxSize + 31) & ~31;

	m_dwSize = m_nxPadded/8; // bytes per scan line for single plane bitmap
  m_dwSize *= m_nySize ; 

	// Allocate memory for the BITMAPINFO and pallette
  m_hGlobal =	::GlobalAlloc(GMEM_MOVEABLE | GMEM_ZEROINIT,
										sizeof(BITMAPINFOHEADER)+
										sizeof(RGBQUAD) * DIB_COLOURS
										+m_dwSize);
  m_lpMem = (BYTE*)::GlobalLock(m_hGlobal);
										
	// Set up the header                    
	PBITMAPINFO pbmi = (PBITMAPINFO) m_lpMem;

	if (pbmi == NULL)
		{
		blOK = FALSE;
		}
	else
		{
		pbmi->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		pbmi->bmiHeader.biWidth = m_nxPadded;
		pbmi->bmiHeader.biHeight = m_nySize;
		pbmi->bmiHeader.biPlanes = 1;
		pbmi->bmiHeader.biBitCount = 1;
		pbmi->bmiHeader.biCompression = BI_RGB;
		pbmi->bmiHeader.biSizeImage = m_dwSize;
		pbmi->bmiHeader.biXPelsPerMeter = 1000;
		pbmi->bmiHeader.biYPelsPerMeter = 1000;
		pbmi->bmiHeader.biClrUsed = DIB_COLOURS;
		pbmi->bmiHeader.biClrImportant = DIB_COLOURS;

		// Background
		pbmi->bmiColors[DIB_BACKGROUND].rgbRed =   240;
		pbmi->bmiColors[DIB_BACKGROUND].rgbGreen = 240;
		pbmi->bmiColors[DIB_BACKGROUND].rgbBlue =  240;
		pbmi->bmiColors[DIB_BACKGROUND].rgbReserved = 0;

		// Foreground
		pbmi->bmiColors[DIB_FOREGROUND].rgbRed =  0;
		pbmi->bmiColors[DIB_FOREGROUND].rgbGreen = 0;
		pbmi->bmiColors[DIB_FOREGROUND].rgbBlue = 0;
		pbmi->bmiColors[DIB_FOREGROUND].rgbReserved = 0;
		}

	 if (blOK)
		{
		// Now allocate memory for the bitmap data
		m_lpBmp = m_lpMem + (sizeof(BITMAPINFOHEADER)+
																	sizeof(RGBQUAD) * DIB_COLOURS);

    Clear();

#if 0 // debug pattern
    int ix,iy;
    for(ix = 0; ix < m_nxSize; ix += 20)
      for(iy = 0; iy < m_nySize; ++iy)
        WriteBit(ix,iy,true);

    for(iy = 0; iy < m_nySize; iy += 20)
      for(ix=0; ix < m_nxSize; ++ix)
        WriteBit(ix,iy,true);

    for(iy=0; iy<m_nySize; ++iy)
      WriteBit(iy,iy,true);
#endif
		}

}

CLCDDisplay::~CLCDDisplay()
{
  ::GlobalUnlock(m_hGlobal);
  ::GlobalFree(m_hGlobal);
  m_lpMem = m_lpBmp = 0;
}


BEGIN_MESSAGE_MAP(CLCDDisplay, CButton)
	//{{AFX_MSG_MAP(CLCDDisplay)
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLCDDisplay message handlers

void CLCDDisplay::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
  CDC* pDC = CDC::FromHandle(lpDrawItemStruct->hDC);

#if 1
  CRect rClient(lpDrawItemStruct->rcItem);

  //pDC->SetStretchBltMode(WHITEONBLACK);
  pDC->SetStretchBltMode(BLACKONWHITE);

  ::StretchDIBits(
    pDC->m_hDC
    ,0	// x-coordinate of upper-left corner of dest. rect. 
    ,0	// y-coordinate of upper-left corner of dest. rect. 
    ,rClient.Width()	// width of destination rectangle 
    ,rClient.Height()	// height of destination rectangle 
    ,0	// x-coordinate of upper-left corner of source rect. 
    ,m_nySize+1	// y-coordinate of upper-left corner of source rect. 
    ,m_nxSize	// width of source rectangle 
    ,-m_nySize	// height of source rectangle
    ,m_lpBmp	// address of bitmap bits 
    ,LPBITMAPINFO(m_lpMem)	// address of bitmap data 
    ,DIB_RGB_COLORS	// usage 
    ,SRCCOPY 	// raster operation code 
   );	

#else
  ::SetDIBitsToDevice(pDC->m_hDC
    ,0 ,0
    ,m_nxPadded, m_nySize
    ,0 ,0
    ,0 ,m_nySize
    ,(LPSTR) m_lpBmp
    ,(LPBITMAPINFO)m_lpMem
    ,DIB_RGB_COLORS);
#endif
}

int CLCDDisplay::Width() const
{
  assert(this);
  return m_nxSize;
}

int CLCDDisplay::Height() const
{
  assert(this);
  return m_nySize;
}

void CLCDDisplay::Clear()
{
  assert(this);
  memset(m_lpBmp,0,m_dwSize);
}

void CLCDDisplay::WriteBit(int ix, int iy, bool blBit)
{
  assert(this);

  int iBit = 7-ix % 8;
  BYTE* pb = static_cast<BYTE*>(m_lpBmp);
  pb += ix / 8;
  pb += iy * (m_nxPadded / 8);
  *pb &= ~(1 << iBit);
  *pb |= ((blBit?1:0) << iBit);
}

void CLCDDisplay::Refresh()
{
  assert(this);
  RedrawWindow();
}


BOOL CLCDDisplay::OnEraseBkgnd(CDC* /*pDC*/) 
{
  return TRUE;  // signal erased 
}
