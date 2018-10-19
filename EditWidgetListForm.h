// EditWidgetListForm.h: interface for the CEditWidgetListForm class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EDITWIDGETLISTFORM_H__5573DD81_AD3E_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_EDITWIDGETLISTFORM_H__5573DD81_AD3E_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "SelectionForm.h"
#include "Selection.h"
#include "Widgets.hpp"

class CWidgetList;
class CTemplateList;

/**********************************************************************
* Class: CEditWidgetListForm
* Base class for both CEditModelForm & CEditTemplateMixersForm.
* This class handles editing a widget list & making the connections
* between the widgets in the list.
**********************************************************************/
class CEditWidgetListForm : public CSelectionForm  
{
public:
	CEditWidgetListForm(CWidgetList* pWidgets, CTemplateList* pTemplates, CFormManager* pManager);
	virtual ~CEditWidgetListForm();

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
  void FillList();

  Selection<CWidget> m_select;

  CWidgetList* m_pWidgetList;
  CTemplateList* m_pTemplates;
};

#endif // !defined(AFX_EDITWIDGETLISTFORM_H__5573DD81_AD3E_11D2_BB29_F5D419D58836__INCLUDED_)
