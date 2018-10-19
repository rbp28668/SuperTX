// ModelListBox.cpp : implementation file
//

#include "stdafx.h"
#include "ModelListBox.h"
#include "Model.h"
#include "ModelList.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CModelListBox

CModelListBox::CModelListBox()
{
}

CModelListBox::~CModelListBox()
{
}


BEGIN_MESSAGE_MAP(CModelListBox, CListBox)
	//{{AFX_MSG_MAP(CModelListBox)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CModelListBox::Update(CModelList* pList)
{
  assert(this);
  assert(pList);

	ResetContent();
  CModelList::const_iterator iter = pList->Begin();
  while(iter != pList->End())
    {
    Add(*iter);
    ++iter;
    }
}

void CModelListBox::Add(CModel* pModel)
{
  assert(this);
  int idx = AddString(pModel->Name().c_str());
  if(idx != LB_ERR && idx != LB_ERRSPACE)
    SetItemDataPtr(idx,pModel);
}

CModel* CModelListBox::Selected()
{
  assert(this);
  int idx = GetCurSel();
  if(idx == LB_ERR)
    return 0;
  else
    return static_cast<CModel*>(GetItemDataPtr(idx));
}


/////////////////////////////////////////////////////////////////////////////
// CModelListBox message handlers
