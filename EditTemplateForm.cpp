// EditTemplateForm.cpp: implementation of the CEditTemplateForm class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SuperTX.h"
#include "EditTemplateForm.h"
#include "EditTemplateMixersForm.h"
#include "EditTemplateIOForm.h"
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

CEditTemplateForm::CEditTemplateForm(CGroupTemplate* pTemplate, CTemplateList* pTemplates, CFormManager* pManager)
: CForm(pManager)
, m_pTemplate(pTemplate)
, m_pTemplates(pTemplates)
{

}

CEditTemplateForm::~CEditTemplateForm()
{

}

// Mixers
void CEditTemplateForm::OnCmd0()
{
  assert(this);
  Manager()->MarkCurrent();
  Manager()->ShowForm(new CEditTemplateMixersForm(m_pTemplate, m_pTemplates, Manager()));
}

// Inputs
void CEditTemplateForm::OnCmd1()
{
  assert(this);
  Manager()->MarkCurrent();
  Manager()->ShowForm(new CEditTemplateIOForm(m_pTemplate
    ,CEditTemplateIOForm::INPUTS,  Manager()));
}

// Outputs
void CEditTemplateForm::OnCmd2()
{
  assert(this);
  Manager()->MarkCurrent();
  Manager()->ShowForm(new CEditTemplateIOForm(m_pTemplate
    ,CEditTemplateIOForm::OUTPUTS,  Manager()));
}

// Freeze All
void CEditTemplateForm::OnCmd3()
{
  assert(this);
}

// Close
void CEditTemplateForm::OnCmd7()
{
  assert(this);
  Manager()->BackToMark();
}


void CEditTemplateForm::Paint(CDisplay* pDisplay)
{
  assert(this);
  assert(pDisplay);

  pDisplay->Clear();

  SetButton(0,"Mixers");
  SetButton(1,"Inputs");
  SetButton(2,"Outputs");
  SetButton(3,"FreezeAll");
  SetButton(7,"Close");

  pDisplay->Update();
}

