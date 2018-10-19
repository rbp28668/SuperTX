// WidgetList.cpp: implementation of the CWidgetList class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "WidgetList.h"
#include "Widgets.hpp"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CWidgetList::CWidgetList()
{

}

CWidgetList::~CWidgetList()
{
  for(iterator iter = Begin(); iter != End(); ++iter)
    {
    if((*iter)->CanDelete())
      delete *iter;
    }
}

void CWidgetList::Add(CWidget* pWidget)
{
  assert(this);
  assert(pWidget);
  m_widgets.push_back(pWidget);
}

bool CWidgetList::Find(const std::string& strName, CWidget*& pWidget)
{
  assert(this);
  for(iterator iter = m_widgets.begin(); iter != m_widgets.end(); ++iter)
    {
    if( (*iter)->Name() == strName)
      {
      pWidget = *iter;
      return true;
      }
    }
  return false;
}

bool CWidgetList::Delete(const std::string& strName)
{
  assert(this);
  CWidget* pWidgetToDelete = 0;
  if(Find(strName,pWidgetToDelete))
    {
    assert(pWidgetToDelete);

    // Need to find all other widgets in collection
    // which use this widget as input & disconnect
    // this widget from them.
    // Search through all widgets
    for(iterator iter = Begin(); iter != End(); ++iter)
      {
      // for an input which uses this widget
      int nInputs = (*iter)->InputCount();
      for(int iInput = 0; iInput < nInputs; ++iInput)
        {
        CInput* pInput = (*iter)->Input(iInput);
        const COutput* pSource = pInput->Source();
        if(pSource && pSource->Parent() == pWidgetToDelete)
          pInput->Disconnect();
        }
      }

    // Now disconnect
    m_widgets.remove(pWidgetToDelete);
    if(pWidgetToDelete->CanDelete())
      delete pWidgetToDelete;

    return true;
    }
  return false;
}

CWidgetList::iterator CWidgetList::End() 
{
  assert(this);
  return m_widgets.end();
}

CWidgetList::iterator CWidgetList::Begin()
{
  assert(this);
  return m_widgets.begin();
}

const CWidgetList::const_iterator CWidgetList::Begin() const
{
  assert(this);
  return m_widgets.begin();
}

CWidgetList::const_iterator CWidgetList::End() const
{
  assert(this);
  return m_widgets.end();
}

int CWidgetList::Size() const
{
  assert(this);
  return m_widgets.size();
}

