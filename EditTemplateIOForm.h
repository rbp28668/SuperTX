// TemplateIOForm.h: interface for the CEditTemplateIOForm class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEMPLATEIOFORM_H__4E101AA3_8D3F_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_TEMPLATEIOFORM_H__4E101AA3_8D3F_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "SelectionForm.h"
#include "Selection.h"
#include "Type.h"

class CInput;
class COutput;
class CGroupTemplate;

/**********************************************************************
* Class: CTemplateIOSelect
* Selection class which can contain either CInputs or COutputs.
**********************************************************************/
class CTemplateIOSelect : public CSelection
{
  public:
  void Add(CInput* ptr, CDisplay* pDisplay = 0);
  CInput* SelectedInput();

  void Add(COutput* ptr, CDisplay* pDisplay = 0);
  COutput* SelectedOutput();

};



/**********************************************************************
* Class: CEditTemplateIOForm
* Form to allow the Inputs & Outputs of a template to be edited
**********************************************************************/
class CEditTemplateIOForm : public CSelectionForm  
{
public:
  enum DirT
    {
    INPUTS,
    OUTPUTS
    };

	CEditTemplateIOForm(CGroupTemplate* pTemplate, DirT dir, CFormManager* pManager);
	virtual ~CEditTemplateIOForm();

  virtual void Paint(CDisplay* pDisplay);

  virtual void OnCmd0(); // Analogue
  virtual void OnCmd1(); // Digital
  virtual void OnCmd2(); // Add
  virtual void OnCmd3(); // Delete

private:

  void FillList();

  CTemplateIOSelect m_select;
  CGroupTemplate* m_pTemplate;
  DirT m_direction;
  CType m_type;
};

#endif // !defined(AFX_TEMPLATEIOFORM_H__4E101AA3_8D3F_11D2_BB29_F5D419D58836__INCLUDED_)
