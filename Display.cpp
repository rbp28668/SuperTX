// Display.cpp: implementation of the CDisplay class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Display.h"
#include "BitmapDisplay.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDisplay::CDisplay(CBitmapDisplay* pDisplaySurface)
: m_pDisplaySurface(pDisplaySurface)
{

}

CDisplay::~CDisplay()
{

}

void CDisplay::Clear()
{
  m_pDisplaySurface->Clear();
}

void CDisplay::Draw(const BitmapT& bmp, int x, int y, bool blPix, bool blEraseBack)
{
  int iyBottom = bmp.m_iyOffset + bmp.m_iHeight;
  int ixRight = bmp.m_ixOffset + bmp.m_iWidth;
  const unsigned char* pData = bmp.m_abData;
  unsigned char ch = *pData;

  for(int iy = bmp.m_iyOffset; iy<iyBottom; ++iy)
    {
    int iBit = 0;
    for(int ix = bmp.m_ixOffset; ix<ixRight; ++ix)
      {
      if((ch & (1<<iBit)) != 0)
        {
        m_pDisplaySurface->WriteBit(x + ix, y + iy,blPix);
        }
      else if(blEraseBack)
        {
        m_pDisplaySurface->WriteBit(x + ix, y + iy,!blPix);
        }

      ++iBit;
      if(iBit == 8)
        {
        ch = *(++pData);
        iBit = 0;
        }
      }
    // If we've just written a complete byte's worth then
    // iBit will be 0 - if not, then we need to discard the
    // rest of the byte (off rhs of image) & reload for the 
    // next line
    if(iBit != 0)
      {
      ch = *(++pData);
      iBit = 0;
      }
    }
}

void CDisplay::Draw(const BitmapT& bmp, bool blPix, bool blEraseBack)
{
  int iyBottom = bmp.m_iyOffset + bmp.m_iHeight;
  int ixRight = bmp.m_ixOffset + bmp.m_iWidth;
  const unsigned char* pData = bmp.m_abData;
  unsigned char ch = *pData;

  for(int iy = bmp.m_iyOffset; iy<iyBottom; ++iy)
    {
    int iBit = 0;
    for(int ix = bmp.m_ixOffset; ix<ixRight; ++ix)
      {
      if((ch & (1<<iBit)) != 0)
        {
        m_pDisplaySurface->WriteBit(ix,iy,blPix);
        }
      else if(blEraseBack)
        {
        m_pDisplaySurface->WriteBit(ix,iy,!blPix);
        }

      ++iBit;
      if(iBit == 8)
        {
        ch = *(++pData);
        iBit = 0;
        }
      }
    // If we've just written a complete byte's worth then
    // iBit will be 0 - if not, then we need to discard the
    // rest of the byte (off rhs of image) & reload for the 
    // next line
    if(iBit != 0)
      {
      ch = *(++pData);
      iBit = 0;
      }
    }
}

void CDisplay::Line(int x1,int y1, int x2, int y2,bool blPix)
{

	int dx = x2-x1;
	int dy = y2-y1;

	int s1 = 1;
  int s2 = 1;
  int s3 = 1;
  int s4 = 1;

	/** First of all, set up the steps for all possible quadrants **/
	if(dx < 0)
		{
		s1 = s3 = -1;
		dx = -dx;
		}

	if (dy < 0)
		{
		s2 = s4 = -1;
		dy = -dy;
		}

	/* Now sort out steps so that algorithm effectively runs */
	/* in 1st octant (dy < dx)					     */

	if(dx >= dy)
		{
		s2=0;
		}
	else
		{
		s1 = 0;
    int temp = dx;
    dx = dy;
    dy = temp;
		}

	/* Ok so we now have s1 to s4 set up to produce a line in the */
	/* correct octant and dy <= dx */
	/* Plot.... */
	
	int x = x1; 
  int y = y1;
	int error =  -dx;

	dx *= 2;
	dy *= 2;

	m_pDisplaySurface->WriteBit(x,y,blPix);	/* plot first pixel */

	while (x != x2  ||  y != y2)
		{
		error += dy;

		if(error <=0)
			{
			x+=s1;
			y+=s2;
			}
		else
			{
			x+=s3;
			y+=s4;
			error -= dx;
			}
		m_pDisplaySurface->WriteBit(x,y,blPix);
		}
}


void CDisplay::Text(const std::string& str, int ix, int iy, const FontT& font, bool blPix)
{
  assert(this);

  std::string::const_iterator i = str.begin();

  while(i != str.end())
    {
    unsigned char ch = *i++;
    
    const unsigned char* pData = font.m_abData;
    pData += ch * font.m_iHeight;

    for (int iiy = 0; iiy < font.m_iHeight; ++iiy)
      {
      ch = pData[iiy];
      for (int iix = 0; iix<font.m_iWidth; ++iix)
        {
        if ((ch & (0x80 >> iix)) != 0)
          m_pDisplaySurface->WriteBit(ix + iix, iy + iiy, blPix);
        }
      }

    ix += font.m_iWidth;
    }
}

void CDisplay::TextBack(const std::string& str, int ix, int iy, const FontT& font, bool blPix)
{
  assert(this);

  std::string::const_iterator i = str.begin();

  bool blBack = !blPix;
  while(i != str.end())
    {
    unsigned char ch = *i++;
    
    const unsigned char* pData = font.m_abData;
    pData += ch * font.m_iHeight;

    for (int iiy = 0; iiy < font.m_iHeight; ++iiy)
      {
      ch = pData[iiy];
      for (int iix = 0; iix<font.m_iWidth; ++iix)
        {
        if ((ch & (0x80 >> iix)) != 0)
          m_pDisplaySurface->WriteBit(ix + iix, iy + iiy, blPix);
        else
          m_pDisplaySurface->WriteBit(ix + iix, iy + iiy, blBack);
        }
      }

    ix += font.m_iWidth;
    }
}

void CDisplay::TextExtent(const std::string& str, int& cx, int& cy, const FontT& font)
{
  assert(this);
  if(str.length() == 0)
    {
    cx = cy = 0;
    return;
    }

  cx = font.m_iWidth * str.length();
  cy = font.m_iHeight;
}

void CDisplay::Rectangle(int x1,int y1, int x2, int y2, bool blPix)
{
  assert(this);
  Line(x1,y1,x2,y1,blPix);
  Line(x2,y1,x2,y2,blPix);
  Line(x2,y2,x1,y2,blPix);
  Line(x1,y2,x1,y1,blPix);
}

void CDisplay::FilledRectangle(int x1,int y1, int x2, int y2, bool blPix)
{
  assert(this);
  
  if(x1 > x2)
    {
    int temp = x1;
    x1 = x2;
    x2 = temp;
    }

  if(y1 > y2)
    {
    int temp = y1;
    y1 = y2;
    y2 = temp;
    }

  for(int iy=y1; iy<y2; ++iy)
    {
    for(int ix=x1; ix<x2; ++ix)
      {
      m_pDisplaySurface->WriteBit(ix,iy,blPix);
      }
    }

  return;
}

void CDisplay::Update()
{
  assert(this);
  m_pDisplaySurface->Refresh();
}

int CDisplay::Height() const
{
  assert(this);
  return m_pDisplaySurface->Height();
}

int CDisplay::Width() const
{
  assert(this);
  return m_pDisplaySurface->Width();
}
