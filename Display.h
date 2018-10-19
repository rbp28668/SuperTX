// Display.h: interface for the CDisplay class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DISPLAY_H__346444A3_4429_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_DISPLAY_H__346444A3_4429_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include <string>

#pragma warning(disable:4200) //nonstandard extension used : zero-sized array in struct/union

/**********************************************************************
* Struct: BitmapT
* data storeage for a single plane bitmap.
**********************************************************************/
struct BitmapT
{
	int m_ixOffset;
	int m_iyOffset;
	int m_iWidth;
	int m_iHeight;
	BYTE m_abData[];
};

/**********************************************************************
* Struct: FontHeaderT
* Layout of a font description in memory.
**********************************************************************/
struct FontHeaderT
{
	WORD m_iHeight;
	WORD m_iWidth;
	WORD m_iStart; 		/* ordinal of first character in font */
	WORD m_iFinish;		/* ordinal of last character in font */
};

/**********************************************************************
* Struct: FontT
* Data for a bitmapped font
**********************************************************************/
struct FontT
{
	WORD m_iHeight;
	WORD m_iWidth;
	WORD m_iStart; 		/* ordinal of first character in font */
	WORD m_iFinish;		/* ordinal of last character in font */
	BYTE m_abData[];
};

// 3 bitmap fonts available 8, 14 & 16 pixels high
extern FontT font8;
extern FontT font14;
extern FontT font16;

interface CBitmapDisplay;

/**********************************************************************
* Class: CDisplay
* A class which provides graphics services for a bitmap display.
**********************************************************************/
class CDisplay  
{
  CBitmapDisplay* m_pDisplaySurface;

public:
	CDisplay(CBitmapDisplay* pDisplaySurface);
	virtual ~CDisplay();

  void Clear();
  void Draw(const BitmapT& bmp, bool blPix = true, bool blEraseBack = false);
  void Draw(const BitmapT& bmp, int x, int y, bool blPix = true, bool blEraseBack = false);
  void Line(int x1,int y1, int x2, int y2,bool blPix = true);
  void Text(const std::string& str, int ix, int iy, const FontT& font, bool blPix = true);
  void TextBack(const std::string& str, int ix, int iy, const FontT& font, bool blPix = true);
  void TextExtent(const std::string& str, int& cx, int& cy, const FontT& font);
  void Rectangle(int x1,int y1, int x2, int y2, bool blPix = true);
  void FilledRectangle(int x1,int y1, int x2, int y2, bool blPix = true);

  int Height() const;
  int Width() const;

  void Update();
};

#endif // !defined(AFX_DISPLAY_H__346444A3_4429_11D2_BB29_F5D419D58836__INCLUDED_)
