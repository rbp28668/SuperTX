// WindowsTemplateEditContext.h: interface for the CWindowsTemplateEditContext class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WINDOWSTEMPLATEEDITCONTEXT_H__B23BC922_55E5_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_WINDOWSTEMPLATEEDITCONTEXT_H__B23BC922_55E5_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "TemplateEditContext.h"

/**********************************************************************
* Class: CWindowsTemplateEditContext
* Concrete implemenation of CTemplateEditContext to allow editing
* of templates using windows dialogs.
**********************************************************************/
class CWindowsTemplateEditContext : public CTemplateEditContext  
{
public:
	CWindowsTemplateEditContext();
	virtual ~CWindowsTemplateEditContext();
  virtual void EditGroupTemplate(CGroupTemplate* pTemplate, CTemplateList* pTemplates) const;

};

#endif // !defined(AFX_WINDOWSTEMPLATEEDITCONTEXT_H__B23BC922_55E5_11D2_BB29_F5D419D58836__INCLUDED_)
