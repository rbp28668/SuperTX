// TXTemplateEditContext.h: interface for the CTXTemplateEditContext class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TXTEMPLATEEDITCONTEXT_H__29312401_8E06_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_TXTEMPLATEEDITCONTEXT_H__29312401_8E06_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "TemplateEditContext.h"
class CFormManager;

/**********************************************************************
* Class: CTXTemplateEditContext
* Concrete class to allow templates
* (or at least CGroupTempalates) to be edited
**********************************************************************/
class CTXTemplateEditContext : public CTemplateEditContext  
{
public:
	CTXTemplateEditContext(CFormManager* pManager);
	virtual ~CTXTemplateEditContext();
  virtual void EditGroupTemplate(CGroupTemplate* pTemplate, CTemplateList* pTemplates) const;

private:
  CFormManager* m_pManager;
};

#endif // !defined(AFX_TXTEMPLATEEDITCONTEXT_H__29312401_8E06_11D2_BB29_F5D419D58836__INCLUDED_)
