// ModelsForm.h: interface for the CModelsForm class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MODELSFORM_H__BA8537C2_6854_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_MODELSFORM_H__BA8537C2_6854_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "SelectionForm.h"
#include "Selection.h"
#include "Model.h"

class CModelList;
class CEncoder;

class CModelsForm : public CSelectionForm  
{
public:
	CModelsForm(CEncoder* pEncoder, CModelList* pModels, CTemplateList* pTemplates, CFormManager* pManager);
	virtual ~CModelsForm();

  virtual void OnCmd0();
  virtual void OnCmd1();
  virtual void OnCmd2();
  virtual void OnCmd3();
  // Cmd4 up arrow handled by base
  // Cmd5 down arrow handled by base
  virtual void OnCmd6();
  // Cmd7 Close handled by base

  virtual void Paint(CDisplay* pDisplay);

private:
  Selection<CModel> m_select;

  CModelList* m_pModels;
  CEncoder* m_pEncoder;
  CTemplateList* m_pTemplates;


};

#endif // !defined(AFX_MODELSFORM_H__BA8537C2_6854_11D2_BB29_F5D419D58836__INCLUDED_)
