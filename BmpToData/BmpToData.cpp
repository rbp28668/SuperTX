#include <windows.h>
#include <assert.h>
#include <iostream>
#include <fstream>
#include <iomanip>

class CBitmapFile
{
	BITMAPFILEHEADER Header;
	BITMAPINFOHEADER Info;
  std::ifstream m_ifs;
  unsigned char* m_pData;

  public:
    CBitmapFile(const char *fn);
    ~CBitmapFile();
    int Height() const;
    int Width() const;
    unsigned char* Line(int iy);
};

CBitmapFile::CBitmapFile(const char *fn)
: m_ifs(fn)
{
  assert(this);
  assert(fn);

  m_ifs.read(reinterpret_cast<char*>(&Header),sizeof(Header));
  m_ifs.read(reinterpret_cast<char*>(&Info), sizeof(Info));

  m_pData = new unsigned char[Width()];
}

CBitmapFile::~CBitmapFile()
{
  assert(this);
  delete [] m_pData;
  m_ifs.close();
}

int CBitmapFile::Height() const
{
  assert(this);
  return Info.biHeight;
}

int CBitmapFile::Width() const
{
  assert(this);
  return Info.biWidth;
}

unsigned char* CBitmapFile::Line(int iy)
{
  assert(this);
  assert(iy >= 0 && iy < Height());

  iy = Height() - iy - 1; // bitmaps stored inverted
  m_ifs.seekg(Header.bfOffBits + iy * Width());
  m_ifs.read(reinterpret_cast<char*>(m_pData),Width());
  return m_pData;
}



int Process(const char *fn)
{
	int y;

  CBitmapFile bitmap(fn);

  RECT rBoundary;
  rBoundary.left = bitmap.Width();
  rBoundary.top = bitmap.Height();
  rBoundary.right = 0;
  rBoundary.bottom = 0;

 	for (y=0; y<bitmap.Height(); ++y)
		{
		unsigned char* pData = bitmap.Line(y);

    for(int ix=0; ix < bitmap.Width(); ++ix)
      {
      if(pData[ix] != 0)
        {
        if(y < rBoundary.top)
          rBoundary.top = y;
        if(y > rBoundary.bottom)
          rBoundary.bottom = y;

        if(ix < rBoundary.left)
          rBoundary.left = ix;
        if(ix > rBoundary.right)
          rBoundary.right = ix;
        }
      }
    }

  ++rBoundary.bottom;
  ++rBoundary.right;

  assert(rBoundary.left <= rBoundary.right);
  assert(rBoundary.top <= rBoundary.bottom);

  std::cout << rBoundary.left 
        << "," 
        << rBoundary.top 
        << "," 
        << std::endl;

  std::cout  << rBoundary.right - rBoundary.left 
        << "," 
        << rBoundary.bottom - rBoundary.top
        << ","
        << std::endl;

  unsigned char uc = 0;
  int nBits = 0;
  bool blFirst = true;


	for (y=rBoundary.top; y<rBoundary.bottom;++y)
		{
    unsigned char* pData = bitmap.Line(y);
    unsigned char uc = 0;
    int nBits = 0;
    
    for(int ix=rBoundary.left; ix < rBoundary.right; ++ix)
      {
      unsigned char iBit = (pData[ix] == 0) ? 0 : 1;

      //std::cout << (iBit ? '*' : '+'); // debug
      uc |= (iBit << nBits);
      ++nBits;

      if(nBits == 8)
        {
        std::cout << int(uc) << ",";
        uc = 0;
        nBits = 0;
        }
      }

    if(nBits != 0)
      {
      std::cout << int(uc) << ","; 
      }
    std::cout << std::endl;
		}

  return 0;
}


int main(int argc, char* argv[])
{
  for(int i=1; i<argc; ++i)
    {
    Process(argv[i]);
    }
  return 0;
}