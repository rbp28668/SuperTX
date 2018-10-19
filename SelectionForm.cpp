// SelectionForm.cpp: implementation of the CSelectionForm class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SuperTX.h"
#include "SelectionForm.h"
#include "Arrows.h"
#include "FormManager.h"
#include "Selection.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSelectionForm::CSelectionForm(CFormManager* pManager, CSelection* pSelection)
: CForm(pManager)
, m_pSelection(pSelection)
{
  assert(m_pSelection);
}

CSelectionForm::~CSelectionForm()
{

}

void CSelectionForm::OnCmd4()  // Up arrow
{
  assert(this);
  m_pSelection->Up();
  m_pSelection->Paint(&Manager()->Display());
  Manager()->Display().Update();
}

void CSelectionForm::OnCmd5()  // Down arrow
{
  assert(this);
  m_pSelection->Down();
  m_pSelection->Paint(&Manager()->Display());
  Manager()->Display().Update();
}

void CSelectionForm::OnCmd7()
{
  assert(this);
  Manager()->BackToMark();
}

void CSelectionForm::Paint(CDisplay* pDisplay)
{
  assert(this);
  assert(pDisplay);

  SetButton(4,&UpArrow);
  SetButton(5,&DownArrow);
  SetButton(7,"Close");

  m_pSelection->SetPosition(Client());
  m_pSelection->Paint(pDisplay);
  pDisplay->Update();
}
