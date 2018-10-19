// EditTemplateForm.h: interface for the CEditTemplateForm class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EDITTEMPLATEFORM_H__4E101AA2_8D3F_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_EDITTEMPLATEFORM_H__4E101AA2_8D3F_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Form.h"
#include "Widgets.hpp"

class CGroupTemplate;
class CTemplateList;

class CEditTemplateForm : public CForm  
{
public:
	CEditTemplateForm(CGroupTemplate* pTemplate, CTemplateList* pTemplates, CFormManager* pManager);
	virtual ~CEditTemplateForm();

  virtual void OnCmd0();
  virtual void OnCmd1();
  virtual void OnCmd2();
  virtual void OnCmd3();
  virtual void OnCmd7();

  virtual void Paint(CDisplay* pDisplay);


private:
  CGroupTemplate* m_pTemplate;
  CTemplateList* m_pTemplates;
};

#endif // !defined(AFX_EDITTEMPLATEFORM_H__4E101AA2_8D3F_11D2_BB29_F5D419D58836__INCLUDED_)
