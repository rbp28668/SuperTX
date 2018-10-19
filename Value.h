// Value.h: interface for the CValue class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VALUE_H__2744EDC1_3609_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_VALUE_H__2744EDC1_3609_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include <string>

/**********************************************************************
* Class: CValue
* Class for holding a data value - either boolean for digital signals
* or a fixed point number for analogue
**********************************************************************/
class CValue  
{
  short m_iVal;

  enum {MULT_VAL = 4096};

  static const std::string& convert(std::string& str,short iVal);

public:
  explicit CValue(bool blVal);
	explicit CValue(int iVal = 0);
           CValue(int iNum, int iDen);
  explicit CValue(const std::string& str);

	~CValue();

  CValue Set(bool blVal);
	CValue Set(int iVal);
  CValue Set(int iNum, int iDen);
  CValue Set(const std::string& str);

  const std::string& ToString(std::string& str) const;

  CValue operator *(CValue rhs) const;
  CValue operator +(CValue rhs) const;
  CValue operator -(CValue rhs) const;
  
  bool operator ==(CValue rhs) const;
  bool operator !=(CValue rhs) const;
  bool operator >(CValue rhs) const;
  bool operator <(CValue rhs) const;
  bool operator >=(CValue rhs) const;
  bool operator <=(CValue rhs) const;

  operator bool() const {return m_iVal != 0;}

  short Scale( int iScale) const;
  static int Precision();
};

#endif // !defined(AFX_VALUE_H__2744EDC1_3609_11D2_BB29_F5D419D58836__INCLUDED_)
