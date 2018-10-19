// SelectTemplateForm.cpp: implementation of the CSelectTemplateForm class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SuperTX.h"
#include "SelectTemplateForm.h"
#include "TemplateList.h"
#include "FormManager.h"
#include "Display.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSelectTemplateForm::CSelectTemplateForm(CTemplateList* pTemplates, CFormManager* pManager)
: CSelectionForm(pManager, &m_select)
, m_pTemplates(pTemplates)
{
  m_select.Title("Mixers");

  // Fill list with available mixers
  CTemplateList::const_iterator iter = m_pTemplates->Begin();
  while(iter != m_pTemplates->End())
    {
    m_select.Add((*iter)->Name(),*iter);
    ++iter;
    }

}

CSelectTemplateForm::~CSelectTemplateForm()
{

}

void CSelectTemplateForm::OnCmd6()
{
  assert(this);
  m_pSelected = 0;
  Manager()->EndModal(IDCANCEL);
}

void CSelectTemplateForm::OnCmd7()
{
  assert(this);
  m_pSelected = m_select.SelectedPtr();
  Manager()->EndModal(IDOK);
}

void CSelectTemplateForm::Paint(CDisplay* pDisplay)
{
  assert(this);
  assert(pDisplay);

  pDisplay->Clear();

  SetButton(6,"Cancel");
  SetButton(7,"Close");
  
  CSelectionForm::Paint(pDisplay);

}

CWidgetTemplate* CSelectTemplateForm::Selected()
{
  assert(this);
  return m_pSelected;
}
