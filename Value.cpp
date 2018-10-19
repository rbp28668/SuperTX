// Value.cpp: implementation of the CValue class.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include <assert.h>
#include "Value.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


CValue::CValue(bool blVal)
: m_iVal(blVal ? 1 : 0)
{
}

CValue::CValue(int iVal)
{
  Set(iVal);
}

CValue::CValue(int iNum, int iDen)
{
  Set(iNum,iDen);
}

CValue::CValue(const std::string& str)
{
  Set(str);
}


CValue::~CValue()
{
}

CValue CValue::Set(bool blVal)
{ 
  assert(this);
  m_iVal = (blVal ? 1 : 0);
  return *this;
}

CValue CValue::Set(int iVal)
{ 
  assert(this);
  
  if(iVal > 7) iVal = 7;
  if(iVal < -7) iVal = -7;
  iVal *= MULT_VAL;
  m_iVal = iVal;
  return *this;
}

CValue CValue::Set(int iNum, int iDen)
{ 
  assert(this);

  if(iDen != 0)
    {
    long lVal = iNum * long(MULT_VAL);
    lVal /= iDen;
    if(lVal > long(7 * MULT_VAL)) lVal = 7 * MULT_VAL;
    if(lVal < long(-7 * MULT_VAL)) lVal = -7 * MULT_VAL;

    m_iVal = short(lVal);
    }
  else
    m_iVal = 0;
  return *this;
}

CValue CValue::Set(const std::string& str)
{ 
  assert(this);

  int iPos = 0;
  int iLen = str.length();
  char ch = 0;

  // Optional +- signs
  bool blNegative = false;
  for(iPos = 0; iPos < iLen; ++iPos)
    {
    ch = str[iPos];
    if(ch == '-')
      {
      blNegative = !blNegative;
      }
    else if(ch == '+')
      {
      // NOP
      }
    else
      break;
    }

  // Integer part
  long lAcc = 0;
  for(; iPos < iLen; ++iPos)
    {
    ch = str[iPos];
    if(isdigit(ch))
      {
      lAcc *= 10;
      lAcc += ch - '0';
      }
    else
      break;
    }

  // Fractional part
  long lDiv = 1;
  long lFrac = 0;
  if(ch == '.') 
    {
    ++iPos; // skip decimal point
    for(; iPos < iLen; ++iPos)
      {
      ch = str[iPos];
      if(isdigit(ch))
        {
        lFrac *= 10;
        lDiv *= 10;
        lFrac += ch - '0';
        }
      else
        break;
      }
    }

  // Ok, so now the number is lAcc + lFrac/lDiv
  // if negative blNegative will be true
  long lVal = lFrac * long(MULT_VAL);
  lVal /= lDiv;
  lVal += (lAcc * MULT_VAL);

  if(blNegative)
    lVal = -lVal;

  if(lVal > long(7 * MULT_VAL)) lVal = 7 * MULT_VAL;
  if(lVal < long(-7 * MULT_VAL)) lVal = -7 * MULT_VAL;

  m_iVal = short(lVal);

  return *this;
}


const std::string& CValue::convert(std::string& str,short iVal)
{
  char ch = char(iVal % 10 + '0');
  iVal /= 10;
  if(iVal != 0)
    convert(str, iVal);
  str += ch;

  return str;
}

const std::string& CValue::ToString(std::string& str) const
{ 
  assert(this);

  str.erase();

  short iVal = m_iVal;
  if(m_iVal < 0)
    {
    str += '-';
    iVal = 0-m_iVal;
    }

  short iNatural = iVal / MULT_VAL;
  unsigned short iFract = iVal % MULT_VAL;

  convert(str,iNatural);
  if(iFract != 0)
    {
    str += '.';
    }

  int nDigits = 4; //
  while(iFract > 0 && nDigits-- > 0)
    {
    iFract *= 10;
    str += char('0' + iFract / MULT_VAL);

    iFract %= MULT_VAL;
    }
  return str;
}


CValue CValue::operator *(CValue rhs) const
{ 
  assert(this);
  long lVal = long(m_iVal) * long(rhs.m_iVal);
  lVal /= MULT_VAL;

  if(lVal > long(7 * MULT_VAL)) lVal = 7 * MULT_VAL;
  if(lVal < long(-7 * MULT_VAL)) lVal = -7 * MULT_VAL;
  
  CValue result;
  result.m_iVal = short(lVal);

  return result;
}

CValue CValue::operator +(CValue rhs) const
{ 
  assert(this);
  long lVal = long(m_iVal) + long(rhs.m_iVal);

  if(lVal > long(7 * MULT_VAL)) lVal = 7 * MULT_VAL;
  if(lVal < long(-7 * MULT_VAL)) lVal = -7 * MULT_VAL;

  CValue result;
  result.m_iVal = short(lVal);

  return result;
}

CValue CValue::operator -(CValue rhs) const
{ 
  assert(this);
  long lVal = long(m_iVal) - long(rhs.m_iVal);

  if(lVal > long(7 * MULT_VAL)) lVal = 7 * MULT_VAL;
  if(lVal < long(-7 * MULT_VAL)) lVal = -7 * MULT_VAL;

  CValue result;
  result.m_iVal = short(lVal);

  return result;
}

bool CValue::operator ==(CValue rhs) const
{ 
  return m_iVal == rhs.m_iVal;
}

bool CValue::operator !=(CValue rhs) const
{ 
  return m_iVal != rhs.m_iVal;
}

 
bool CValue::operator >(CValue rhs) const
{ 
  return m_iVal > rhs.m_iVal;
}

bool CValue::operator <(CValue rhs) const
{ 
  return m_iVal < rhs.m_iVal;
}

bool CValue::operator >=(CValue rhs) const
{ 
  return m_iVal >= rhs.m_iVal;
}

bool CValue::operator <=(CValue rhs) const
{ 
  return m_iVal <= rhs.m_iVal;
}


short CValue::Scale( int iScale) const
{
  assert(this);
  long lVal = (long(m_iVal) * long(iScale)) / MULT_VAL;
  return(short) lVal;
}

int CValue::Precision()
{
  return MULT_VAL;
}