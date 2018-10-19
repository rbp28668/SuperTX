// WidgetComboBox.cpp : implementation file
//

#include "stdafx.h"
#include "WidgetComboBox.h"
#include "Widgets.hpp"
#include "WidgetList.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWidgetComboBox

CWidgetComboBox::CWidgetComboBox()
{
}

CWidgetComboBox::~CWidgetComboBox()
{
}


BEGIN_MESSAGE_MAP(CWidgetComboBox, CComboBox)
	//{{AFX_MSG_MAP(CWidgetComboBox)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CWidgetComboBox::Add(CWidget* pWidget)
{
  assert(this);
  assert(pWidget);
  std::string strName = pWidget->Name() + " (" + pWidget->TypeName() + ")";
  int idx = AddString(strName.c_str() );
  if(idx != CB_ERR && idx != CB_ERRSPACE)
    SetItemDataPtr(idx,pWidget);
}

void CWidgetComboBox::Update(CWidgetList& list)
{
  assert(this);
  ResetContent();
  for(CWidgetList::iterator iter = list.Begin(); iter != list.End(); ++iter)
    Add(*iter);
}

CWidget* CWidgetComboBox::Selected()
{
  assert(this);
  int idx = GetCurSel();
  if(idx != CB_ERR)
    return static_cast<CWidget*>(GetItemDataPtr(idx));
  else
    return 0;
}


/////////////////////////////////////////////////////////////////////////////
// CWidgetComboBox message handlers
