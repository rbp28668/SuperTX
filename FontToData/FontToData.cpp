#include <windows.h>
#include <assert.h>
#include <iostream>
#include <fstream>
#include <iomanip>

#pragma pack(1)

struct FontHeaderT
{
	WORD m_iHeight;
	WORD m_iWidth;
	WORD m_iStart; 		/* ordinal of first character in font */
	WORD m_iFinish;		/* ordinal of last character in font */
};

int Process(const char *fn)
{
 
  HANDLE hFile = ::CreateFile(fn
                             ,GENERIC_READ
                             ,FILE_SHARE_READ 
                             ,0
                             ,OPEN_EXISTING
                             ,FILE_ATTRIBUTE_NORMAL
                             ,0
                             );

  
  FontHeaderT header;

  DWORD dwRead = 0;
  ::ReadFile(hFile
              ,&header
              ,sizeof(header)
              ,&dwRead
              ,0
              );

  //ifs.read(reinterpret_cast<char*>(&header), sizeof(header));

  std::cout << header.m_iHeight
            << ","
            << header.m_iWidth
            << ","
            << header.m_iStart
            << ","
            << header.m_iFinish
            << std::endl;

  assert(header.m_iWidth == 8); // as rest of code assumes this

  int nBytes = header.m_iHeight * (header.m_iFinish - header.m_iStart + 1);
  unsigned char* pData = new unsigned char[nBytes];

  ::ReadFile(hFile
              ,pData
              ,nBytes
              ,&dwRead
              ,0
              );
  //ifs.read(reinterpret_cast<char*>(pData),nBytes);

  int idx = 0;
  for(int iChar = header.m_iStart; iChar <= header.m_iFinish; ++iChar)
    {
    for(int i=0; i<header.m_iHeight; ++i)
      {
      std::cout << int(pData[idx++]) << ",";
      }
    std::cout << std::endl;
    }

  delete [] pData;
  ::CloseHandle(hFile);
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