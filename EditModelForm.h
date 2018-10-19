// EditModelForm.h: interface for the CEditModelForm class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EDITMODELFORM_H__431AB0E1_830A_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_EDITMODELFORM_H__431AB0E1_830A_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "EditWidgetListForm.h"

class CModel;

class CEditModelForm : public CEditWidgetListForm  
{
public:
	CEditModelForm(CModel* pModel, CTemplateList* pTemplates, CFormManager* pManager);
	virtual ~CEditModelForm();

  CModel* m_pModel;
};

#endif // !defined(AFX_EDITMODELFORM_H__431AB0E1_830A_11D2_BB29_F5D419D58836__INCLUDED_)
