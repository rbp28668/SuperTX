// EditModelForm.cpp: implementation of the CEditWidgetListForm class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SuperTX.h"
#include "EditWidgetListForm.h"
#include "Display.h"
#include "WidgetList.h"
#include "Model.h"
#include "SelectTemplateForm.h"
#include "StringEntryForm.h"
#include "ConnectForm.h"
#include "FormManager.h"
#include "Error.h"
#include "TXEditContext.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CEditWidgetListForm::CEditWidgetListForm(CWidgetList* pWidgets, CTemplateList* pTemplates, CFormManager* pManager)
: CSelectionForm(pManager, &m_select)
, m_pWidgetList(pWidgets)
, m_pTemplates(pTemplates)
{

  m_select.Title("Mixers");
  FillList();
}

CEditWidgetListForm::~CEditWidgetListForm()
{

}

// Add Mixer
void CEditWidgetListForm::OnCmd0()
{
  assert(this);

  CSelectTemplateForm stf(m_pTemplates,Manager());
  if(Manager()->ShowFormModal(&stf) == IDOK)
    {
    // now get the widget name & check it is unique
    // in the model
    CStringEntryForm sef(Manager());
    while(Manager()->ShowFormModal(&sef) == IDOK)
      {
      std::string strName = sef.Text();
    
      CWidget* pWidget = 0;
      if(!m_pWidgetList->Find(strName,pWidget))
        {
        // Create a new widget with the selected template
        pWidget = stf.Selected()->Create(strName);
        m_pWidgetList->Add(pWidget);
        m_select.Add(pWidget->Name(),pWidget,&Manager()->Display());
        break;
        }
      else
        {
        CError(IDS_ERR_TEMPLATE_NAME_NOT_UNIQUE);
        }
      }
    }
}

// Edit Mixer
void CEditWidgetListForm::OnCmd1()
{
  assert(this);
  if(m_select.SelectionValid())
    {
    CWidget* pWidget = m_select.SelectedPtr();
    if(pWidget->CanEdit())
      {
      CTXEditContext context(Manager());
      pWidget->Edit(&context);
      }
    }
}

// Delete Mixer
void CEditWidgetListForm::OnCmd2()
{
  assert(this);
  if(m_select.SelectionValid())
    {
 	  CWidget* pWidget = m_select.SelectedPtr();
    assert(pWidget);
    m_pWidgetList->Delete(pWidget->Name());
    FillList(); // with updated set of mixers
    }
}

// Freeze (mixer)
void CEditWidgetListForm::OnCmd3()
{
  assert(this);
  if(m_select.SelectionValid())
    {
    m_select.SelectedPtr()->Freeze();
    }
}

// Connections
void CEditWidgetListForm::OnCmd6()
{
  assert(this);
  Manager()->MarkCurrent();
  Manager()->ShowForm(new CConnectForm(m_pWidgetList, Manager()));
}


void CEditWidgetListForm::Paint(CDisplay* pDisplay)
{
  assert(this);
  assert(pDisplay);

  pDisplay->Clear();

  SetButton(0,"Add Mix");
  SetButton(1,"Edit Mix");
  SetButton(2,"Del Mix");
  SetButton(3,"Freeze");
  SetButton(6,"Connect");
  
  CSelectionForm::Paint(pDisplay);

}


void CEditWidgetListForm::FillList()
{
  assert(this);
  // Fill list with available mixers
  CWidgetList::const_iterator iter = m_pWidgetList->Begin();
  m_select.RemoveAll();
  while(iter != m_pWidgetList->End())
    {
    m_select.Add((*iter)->Name(),*iter);
    ++iter;
    }
}
