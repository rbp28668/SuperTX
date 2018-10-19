// InputListBox.cpp : implementation file
//

#include "stdafx.h"
#include "InputListBox.h"
#include "Widgets.hpp"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInputListBox

CInputListBox::CInputListBox()
{
}

CInputListBox::~CInputListBox()
{
}


BEGIN_MESSAGE_MAP(CInputListBox, CListBox)
	//{{AFX_MSG_MAP(CInputListBox)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CInputListBox::Add(const CInput* pInput)
{
  assert(this);
  int idx = AddString(pInput->Name().c_str());
  if(idx != LB_ERR && idx != LB_ERRSPACE)
    SetItemDataPtr(idx,const_cast<CInput*>(pInput));
}


void CInputListBox::Update(const CWidget& widget)
{
  assert(this);
  ResetContent();
  for(int i=0; i<widget.InputCount(); ++i)
    Add(&widget.Input(i));
}
const CInput* CInputListBox::Selected()
{
  assert(this);
  int idx = GetCurSel();
  if(idx != LB_ERR)
    return static_cast<CInput*>(GetItemDataPtr(idx));
  else
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
// CInputListBox message handlers
