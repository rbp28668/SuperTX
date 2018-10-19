// WidgetList.h: interface for the CWidgetList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WIDGETLIST_H__A8749024_5248_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_WIDGETLIST_H__A8749024_5248_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include <list>
class CWidget;

/**********************************************************************
* Class: CWidgetList
* A collection class for holding a list of widgets
**********************************************************************/
class CWidgetList  
{
  std::list<CWidget*> m_widgets;
  
  public:

  typedef std::list<CWidget*>::iterator iterator;
  typedef std::list<CWidget*>::const_iterator const_iterator;

  CWidgetList();
	virtual ~CWidgetList();

  void Add(CWidget* pWidget);
  bool Find(const std::string& strName, CWidget*& pWidget);
  bool Delete(const std::string& strName);

  iterator Begin();
  iterator End();

  const const_iterator Begin() const;
  const_iterator End() const;

  int Size() const;
};

#endif // !defined(AFX_WIDGETLIST_H__A8749024_5248_11D2_BB29_F5D419D58836__INCLUDED_)
