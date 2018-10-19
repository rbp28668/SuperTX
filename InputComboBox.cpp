// InputComboBox.cpp : implementation file
//

#include "stdafx.h"
#include "InputComboBox.h"
#include "Widgets.hpp"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInputComboBox

CInputComboBox::CInputComboBox()
{
}

CInputComboBox::~CInputComboBox()
{
}


BEGIN_MESSAGE_MAP(CInputComboBox, CComboBox)
	//{{AFX_MSG_MAP(CInputComboBox)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CInputComboBox::Add(CInput* pInput)
{
  assert(this);
  int idx = AddString(pInput->Name().c_str());
  if(idx != CB_ERR && idx != CB_ERRSPACE)
    SetItemDataPtr(idx,pInput);
}

void CInputComboBox::Update(CWidget& widget)
{
  assert(this);
  ResetContent();
  for(int i=0; i<widget.InputCount(); ++i)
    Add(widget.Input(i));
}

CInput* CInputComboBox::Selected()
{
  assert(this);
  int idx = GetCurSel();
  if(idx != CB_ERR)
    return static_cast<CInput*>(GetItemDataPtr(idx));
  else
    return 0;
}


/////////////////////////////////////////////////////////////////////////////
// CInputComboBox message handlers
