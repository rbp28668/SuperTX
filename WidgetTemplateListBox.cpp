// WidgetTemplateListBox.cpp : implementation file
//

#include "stdafx.h"
#include "WidgetTemplateListBox.h"
#include "Widgets.hpp"
#include "TemplateList.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWidgetTemplateListBox

CWidgetTemplateListBox::CWidgetTemplateListBox()
{
}

CWidgetTemplateListBox::~CWidgetTemplateListBox()
{
}


BEGIN_MESSAGE_MAP(CWidgetTemplateListBox, CListBox)
	//{{AFX_MSG_MAP(CWidgetTemplateListBox)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CWidgetTemplateListBox::Add(CWidgetTemplate* pWidgetTemplate)
{
  assert(this);
  int idx = AddString(pWidgetTemplate->Name().c_str());
  if(idx != LB_ERR && idx != LB_ERRSPACE)
    SetItemDataPtr(idx,pWidgetTemplate);
}

void CWidgetTemplateListBox::Update(CTemplateList& list)
{
  assert(this);
  ResetContent();
  for(CTemplateList::iterator iter = list.Begin(); iter != list.End(); ++iter)
    Add(*iter);
}

CWidgetTemplate* CWidgetTemplateListBox::Selected()
{
  assert(this);
  int idx = GetCurSel();
  if(idx != LB_ERR)
    return static_cast<CWidgetTemplate*>(GetItemDataPtr(idx));
  else
    return 0;
}


/////////////////////////////////////////////////////////////////////////////
// CWidgetTemplateListBox message handlers
