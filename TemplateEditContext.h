// TemplateEditContext.h: interface for the CTemplateEditContext class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEMPLATEEDITCONTEXT_H__B23BC921_55E5_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_TEMPLATEEDITCONTEXT_H__B23BC921_55E5_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CGroupTemplate;
class CTemplateList;

/**********************************************************************
* Class: CTemplateEditContext
* An abstract base class which provides context to allow templates
* (or at least CGroupTempalates) to be edited
**********************************************************************/
class CTemplateEditContext  
{
public:
	CTemplateEditContext();
	virtual ~CTemplateEditContext();
  virtual void EditGroupTemplate(CGroupTemplate* pTemplate, CTemplateList* pTemplates) const = 0;
};

#endif // !defined(AFX_TEMPLATEEDITCONTEXT_H__B23BC921_55E5_11D2_BB29_F5D419D58836__INCLUDED_)
