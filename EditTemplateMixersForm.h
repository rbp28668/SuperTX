// EditTemplateMixersForm.h: interface for the CEditTemplateMixersForm class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EDITTEMPLATEMIXERSFORM_H__BD68EDE2_ADFC_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_EDITTEMPLATEMIXERSFORM_H__BD68EDE2_ADFC_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "EditWidgetListForm.h"
class CGroupTemplate;
class CTemplateList;
class CFormManager;

class CEditTemplateMixersForm : public CEditWidgetListForm  
{
public:
	CEditTemplateMixersForm(CGroupTemplate* pTemplate, CTemplateList* pTemplates, CFormManager* pManager);
	virtual ~CEditTemplateMixersForm();

};

#endif // !defined(AFX_EDITTEMPLATEMIXERSFORM_H__BD68EDE2_ADFC_11D2_BB29_F5D419D58836__INCLUDED_)
