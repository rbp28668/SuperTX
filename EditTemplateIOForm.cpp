// TemplateIOForm.cpp: implementation of the CEditTemplateIOForm class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SuperTX.h"
#include "EditTemplateIOForm.h"
#include "Widgets.hpp"
#include "Group.h"
#include "Display.h"
#include "StringEntryForm.h"
#include "FormManager.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

void CTemplateIOSelect::Add(CInput* ptr, CDisplay* pDisplay)
{
  assert(this);
  assert(ptr);
  CSelection::Add(ptr->Name(), ptr, pDisplay);
}

CInput* CTemplateIOSelect::SelectedInput()
{
  assert(this);
  return static_cast<CInput*>(CSelection::SelectedPtr());
}


void CTemplateIOSelect::Add(COutput* ptr, CDisplay* pDisplay)
{
  assert(this);
  assert(ptr);
  CSelection::Add(ptr->Name(), ptr, pDisplay);
}

COutput* CTemplateIOSelect::SelectedOutput()
{
  assert(this);
  return static_cast<COutput*>(CSelection::SelectedPtr());
}


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CEditTemplateIOForm::CEditTemplateIOForm(CGroupTemplate* pTemplate, DirT dir, CFormManager* pManager )
: CSelectionForm(pManager, &m_select)
, m_pTemplate(pTemplate)
, m_direction(dir)
, m_type(CType::Analogue())
{
  assert(pTemplate);

  if(dir == INPUTS)
    m_select.Title("Mixer Inputs");
  else
    m_select.Title("Mixer Outputs");

  FillList();
}

CEditTemplateIOForm::~CEditTemplateIOForm()
{

}

void CEditTemplateIOForm::FillList()
{
  assert(this);

  CConnectorWidget& con = (m_direction == INPUTS)
                            ? m_pTemplate->Inputs()
                            : m_pTemplate->Outputs();


  if(m_direction == INPUTS)
    {
    CConnectorWidget& con = m_pTemplate->Inputs();
    for(int i=0; i<con.InputCount(); ++i)
      m_select.Add(con.Input(i));
    }
  else
    {
    CConnectorWidget& con = m_pTemplate->Outputs();
    for(int i=0; i<con.OutputCount(); ++i)
      m_select.Add(con.Output(i));
    }

}

void CEditTemplateIOForm::OnCmd0() // Analogue
{
  assert(this);
  m_type = CType::Analogue();
}

void CEditTemplateIOForm::OnCmd1() // Digital
{
  assert(this);
  m_type = CType::Digital();
}

void CEditTemplateIOForm::OnCmd2() // Add
{
  assert(this);

  CStringEntryForm sef(Manager());

  while(Manager()->ShowFormModal(&sef) == IDOK)
    {
    std::string strName = sef.Text();

    if(m_direction == INPUTS)
      {
      if(m_pTemplate->AddInput(strName, m_type))
        break;
      }
    else
      {
      if(m_pTemplate->AddOutput(strName,m_type))
        break;
      }
    }
}

void CEditTemplateIOForm::OnCmd3() // Delete
{
  assert(this);
  if(m_select.SelectionValid())
    {
    if(m_direction == INPUTS)
      {
      CInput* pInput = m_select.SelectedInput();
      m_pTemplate->DeleteInput(pInput->Name());
      }
    else
      {
      COutput* pOutput = m_select.SelectedOutput();
      m_pTemplate->DeleteOutput(pOutput->Name());
      }
    }
}


void CEditTemplateIOForm::Paint(CDisplay* pDisplay)
{
  assert(this);
  assert(pDisplay);

  pDisplay->Clear();

  SetButton(0, "Analogue");
  SetButton(1, "Digital");
  SetButton(2, "Add");
  SetButton(3, "Delete");
  
  CSelectionForm::Paint(pDisplay);
}
