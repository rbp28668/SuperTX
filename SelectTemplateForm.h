// SelectTemplateForm.h: interface for the CSelectTemplateForm class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SELECTTEMPLATEFORM_H__ACFD9EC1_849D_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_SELECTTEMPLATEFORM_H__ACFD9EC1_849D_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "SelectionForm.h"
#include "Widgets.hpp"
#include "Selection.h"

class CSelectTemplateForm : public CSelectionForm  
{
public:
	CSelectTemplateForm(CTemplateList* pTemplates, CFormManager* pManager);
	virtual ~CSelectTemplateForm();

  virtual void OnCmd6();  // Cancel
  virtual void OnCmd7();  // Close

  virtual void Paint(CDisplay* pDisplay);

  CWidgetTemplate* Selected();

private:
  Selection<CWidgetTemplate> m_select;

  CWidgetTemplate* m_pSelected;
  CTemplateList* m_pTemplates;
};

#endif // !defined(AFX_SELECTTEMPLATEFORM_H__ACFD9EC1_849D_11D2_BB29_F5D419D58836__INCLUDED_)
