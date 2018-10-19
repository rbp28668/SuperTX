// Type.h: interface for the CType class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TYPE_H__2744EDC2_3609_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_TYPE_H__2744EDC2_3609_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/**********************************************************************
* Class: CType
* Typesafe wrapper class round an enumeration which describes the 
* type of a connection or input/output. The types are only accessible
* through the static members CType::Analogue() & CType::Digital().
**********************************************************************/
class CType  
{
  enum {ANALOGUE, DIGITAL};

  short m_iType;

	CType(short iType);

public:
	~CType();

  static CType Analogue();
  static CType Digital();

  bool operator ==(CType rhs) const;
  bool operator !=(CType rhs) const;
};

#endif // !defined(AFX_TYPE_H__2744EDC2_3609_11D2_BB29_F5D419D58836__INCLUDED_)
