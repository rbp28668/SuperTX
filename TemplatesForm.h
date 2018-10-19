// TemplatesForm.h: interface for the CTemplatesForm class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEMPLATESFORM_H__4E101AA1_8D3F_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_TEMPLATESFORM_H__4E101AA1_8D3F_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "SelectionForm.h"
#include "Widgets.hpp"
#include "Selection.h"

class CTemplateList;
class CFormManager;

class CTemplatesForm : public CSelectionForm  
{
public:
	CTemplatesForm(CTemplateList* pTemplates, CFormManager* pManager);
	virtual ~CTemplatesForm();

  virtual void OnCmd0();  // New
  virtual void OnCmd1();  // Edit
  virtual void OnCmd2();  // Delete

  virtual void Paint(CDisplay* pDisplay);

private:
  void FillSelection();

  Selection<CWidgetTemplate> m_select;
  CTemplateList* m_pTemplates;
};

#endif // !defined(AFX_TEMPLATESFORM_H__4E101AA1_8D3F_11D2_BB29_F5D419D58836__INCLUDED_)
