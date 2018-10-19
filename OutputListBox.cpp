// OutputListBox.cpp : implementation file
//

#include "stdafx.h"
#include "OutputListBox.h"
#include "Widgets.hpp"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COutputListBox

COutputListBox::COutputListBox()
{
}

COutputListBox::~COutputListBox()
{
}


BEGIN_MESSAGE_MAP(COutputListBox, CListBox)
	//{{AFX_MSG_MAP(COutputListBox)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void COutputListBox::Add(const COutput* pOutput)
{
  assert(this);
  int idx = AddString(pOutput->Name().c_str());
  if(idx != LB_ERR && idx != LB_ERRSPACE)
    SetItemDataPtr(idx,const_cast<COutput*>(pOutput));
}

void COutputListBox::Update(const CWidget& widget)
{
  assert(this);
  ResetContent();
  for(int i=0; i<widget.OutputCount(); ++i)
    Add(&widget.Output(i));
}

const COutput* COutputListBox::Selected()
{
  assert(this);
  int idx = GetCurSel();
  if(idx != LB_ERR)
    return static_cast<const COutput*>(GetItemDataPtr(idx));
  else
    return 0;
}



/////////////////////////////////////////////////////////////////////////////
// COutputListBox message handlers
