// TemplateList.h: interface for the CTemplateList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEMPLATELIST_H__219CA361_4F2A_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_TEMPLATELIST_H__219CA361_4F2A_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include <list>
class CWidgetTemplate;

/**********************************************************************
* Class: CTemplateList
* Collection class for storing a list of widget templates
**********************************************************************/
class CTemplateList  
{
  std::list<CWidgetTemplate*> m_templates;

public:
  typedef std::list<CWidgetTemplate*>::iterator iterator;
  typedef std::list<CWidgetTemplate*>::const_iterator const_iterator;

  CTemplateList();
	virtual ~CTemplateList();

  void Add(CWidgetTemplate* pTemplate);
  bool Find(const std::string& strName, CWidgetTemplate*& pTemplate);
  bool Delete(const std::string& strName);

  iterator Begin();
  iterator End();
  const_iterator Begin() const;
  const_iterator End() const;

};

#endif // !defined(AFX_TEMPLATELIST_H__219CA361_4F2A_11D2_BB29_F5D419D58836__INCLUDED_)
