// Error.h: interface for the CError class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ERROR_H__A8749021_5248_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_ERROR_H__A8749021_5248_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/**********************************************************************
* Class: CError
* Simple error handling class
**********************************************************************/
class CError  
{
public:
	CError(int idErr);
	virtual ~CError();

};

#endif // !defined(AFX_ERROR_H__A8749021_5248_11D2_BB29_F5D419D58836__INCLUDED_)
