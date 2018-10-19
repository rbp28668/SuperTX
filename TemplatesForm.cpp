// TemplatesForm.cpp: implementation of the CTemplatesForm class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SuperTX.h"
#include "TemplatesForm.h"
#include "TXTemplateEditContext.h"
#include "StringEntryForm.h"
#include "FormManager.h"
#include "TemplateList.h"
#include "Group.h"
#include "Error.h"
#include "Display.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTemplatesForm::CTemplatesForm(CTemplateList* pTemplates, CFormManager* pManager)
: CSelectionForm(pManager, &m_select)
, m_pTemplates(pTemplates)
{
  FillSelection();
}

CTemplatesForm::~CTemplatesForm()
{

}

void CTemplatesForm::OnCmd0()  // New
{
  assert(this);

  CStringEntryForm sef(Manager());

	while(Manager()->ShowFormModal(&sef) == IDOK)
    {
    std::string strName = sef.Text();

    CWidgetTemplate* pTemplate = 0;
    if(!m_pTemplates->Find(strName, pTemplate))
      {
      pTemplate = new CGroupTemplate(strName);
      m_pTemplates->Add(pTemplate);
      m_select.Add(pTemplate->Name(), pTemplate);

      // Straight into edit.
      CTXTemplateEditContext context(Manager()); // marks form context
      pTemplate->Edit(&context, m_pTemplates);
      break;
      }
    else
      {
      CError(IDS_ERR_TEMPLATE_NAME_NOT_UNIQUE);
      }
    }
}

void CTemplatesForm::OnCmd1()  // Edit
{
  assert(this);
  if(m_select.SelectionValid())
    {
    CWidgetTemplate* pTemplate = m_select.SelectedPtr();
    assert(pTemplate);

    CTXTemplateEditContext context(Manager());
    pTemplate->Edit(&context, m_pTemplates);
    }
}

void CTemplatesForm::OnCmd2()  // Delete
{
  assert(this);
  if(m_select.SelectionValid())
    {
    CWidgetTemplate* pTemplate = m_select.SelectedPtr();
    assert(pTemplate);

    m_pTemplates->Delete(pTemplate->Name());
    FillSelection();
    }

}


void CTemplatesForm::Paint(CDisplay* pDisplay)
{
  assert(this);
  assert(pDisplay);
  
  pDisplay->Clear();

  SetButton(0,"New");
  SetButton(1,"Edit");
  SetButton(2,"Delete");

  CSelectionForm::Paint(pDisplay); // updates display
}

void CTemplatesForm::FillSelection()
{
  assert(this);
  m_select.RemoveAll();

  for(CTemplateList::const_iterator iter = m_pTemplates->Begin();
      iter != m_pTemplates->End();
      ++iter)
    {
    const CWidgetTemplate* pTemplate = *iter;
    m_select.Add(pTemplate->Name(), pTemplate);
    }
}
