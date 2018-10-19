// WidgetListBox.cpp : implementation file
//

#include "stdafx.h"
#include "WidgetListBox.h"
#include "Widgets.hpp"
#include "WidgetList.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWidgetListBox

CWidgetListBox::CWidgetListBox()
{
}

CWidgetListBox::~CWidgetListBox()
{
}


BEGIN_MESSAGE_MAP(CWidgetListBox, CListBox)
	//{{AFX_MSG_MAP(CWidgetListBox)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CWidgetListBox::Add(CWidget* pWidget)
{
  assert(this);
  assert(pWidget);
  std::string strName = pWidget->Name() + " (" + pWidget->TypeName() + ")";
  int idx = AddString(strName.c_str() );
  if(idx != LB_ERR && idx != LB_ERRSPACE)
    SetItemDataPtr(idx,pWidget);
}

void CWidgetListBox::Update(CWidgetList& list)
{
  assert(this);
  ResetContent();
  for(CWidgetList::iterator iter = list.Begin(); iter != list.End(); ++iter)
    Add(*iter);
}

void CWidgetListBox::UpdateEditable(CWidgetList& list)
{
  assert(this);
  ResetContent();
  for(CWidgetList::iterator iter = list.Begin(); iter != list.End(); ++iter)
    {
    if((*iter)->CanEdit())
      Add(*iter);
    }
}

CWidget* CWidgetListBox::Selected()
{
  assert(this);
  int idx = GetCurSel();
  if(idx != LB_ERR)
    return static_cast<CWidget*>(GetItemDataPtr(idx));
  else
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
// CWidgetListBox message handlers
