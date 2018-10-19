// OutputComboBox.cpp : implementation file
//

#include "stdafx.h"
#include "OutputComboBox.h"
#include "Widgets.hpp"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COutputComboBox

COutputComboBox::COutputComboBox()
{
}

COutputComboBox::~COutputComboBox()
{
}


BEGIN_MESSAGE_MAP(COutputComboBox, CComboBox)
	//{{AFX_MSG_MAP(COutputComboBox)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void COutputComboBox::Add(COutput* pOutput)
{
  assert(this);
  int idx = AddString(pOutput->Name().c_str());
  if(idx != CB_ERR && idx != CB_ERRSPACE)
    SetItemDataPtr(idx,pOutput);
}

void COutputComboBox::Update(CWidget& widget)
{
  assert(this);
  ResetContent();
  for(int i=0; i<widget.OutputCount(); ++i)
    Add(widget.Output(i));
}

COutput* COutputComboBox::Selected()
{
  assert(this);
  int idx = GetCurSel();
  if(idx != CB_ERR)
    return static_cast<COutput*>(GetItemDataPtr(idx));
  else
    return 0;
}



/////////////////////////////////////////////////////////////////////////////
// COutputComboBox message handlers
