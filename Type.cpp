// Type.cpp: implementation of the CType class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Type.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


CType::CType(short iType)
: m_iType(iType)
{
  assert(iType == ANALOGUE || iType == DIGITAL);
}

CType::~CType()
{
}

bool CType::operator ==(CType rhs) const
{
  assert(this);
  return m_iType == rhs.m_iType;
}

bool CType::operator !=(CType rhs) const
{
  assert(this);
  return m_iType != rhs.m_iType;
}

CType CType::Analogue()
{
  return CType(ANALOGUE);
}

CType CType::Digital()
{
  return CType(DIGITAL);
}