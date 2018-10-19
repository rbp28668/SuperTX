// ModelsForm.cpp: implementation of the CModelsForm class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SuperTX.h"
#include "ModelsForm.h"
#include "Display.h"
#include "StringEntryForm.h"
#include "EditModelForm.h"
#include "FormManager.h"
#include "Model.h"
#include "ModelList.h"
#include "Encoder.h"
#include "Error.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CModelsForm::CModelsForm(CEncoder* pEncoder, CModelList* pModels, CTemplateList* pTemplates, CFormManager* pManager)
: CSelectionForm(pManager, &m_select)
, m_pModels(pModels)
, m_pEncoder(pEncoder)
, m_pTemplates(pTemplates)
{
  m_select.Title("Models");

  // Fill list with existing models
  CModelList::const_iterator iter = pModels->Begin();
  while(iter != pModels->End())
    {
    m_select.Add((*iter)->Name(),*iter);
    ++iter;
    }
}

CModelsForm::~CModelsForm()
{

}

// Select
void CModelsForm::OnCmd0()
{
  assert(this);
}

// Edit
void CModelsForm::OnCmd1()
{
  assert(this);
  
  CModel* pModel = m_select.SelectedPtr();
  assert(pModel);

  Manager()->MarkCurrent(); // want to return to this form when models closes
  Manager()->ShowForm(new CEditModelForm(pModel, m_pTemplates, Manager()));
}

// New
void CModelsForm::OnCmd2()
{
  assert(this);

  CStringEntryForm sef(Manager());


  while(Manager()->ShowFormModal(&sef) == IDOK)
    {
    std::string strName = sef.Text();
    
    CModel* pModel = 0;
    if(!m_pModels->Find(strName,pModel))
      {
      pModel = m_pModels->NewModel(strName);
      m_select.Add(pModel->Name(),pModel, &Manager()->Display());

      m_pEncoder->Connect(pModel->Proxy());

      Manager()->MarkCurrent(); // want to return to this form when models closes
      Manager()->ShowForm(new CEditModelForm(pModel, m_pTemplates, Manager()));

      break;
      }
    else
      {
      CError(IDS_ERR_MODEL_NAME_NOT_UNIQUE);
      }
    }
}

// Delete
void CModelsForm::OnCmd3()
{
  assert(this);
}

void CModelsForm::OnCmd6()
{
  assert(this);
}


void CModelsForm::Paint(CDisplay* pDisplay)
{
  assert(this);
  assert(pDisplay);
  pDisplay->Clear();

  SetButton(0,"Select");
  SetButton(1,"Edit");
  SetButton(2,"New");
  SetButton(3,"Delete");
  
  CSelectionForm::Paint(pDisplay);
}

