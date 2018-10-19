// EditTemplateMixersForm.cpp: implementation of the CEditTemplateMixersForm class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SuperTX.h"
#include "EditTemplateMixersForm.h"
#include "Group.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CEditTemplateMixersForm::CEditTemplateMixersForm(CGroupTemplate* pTemplate, CTemplateList* pTemplates, CFormManager* pManager)
: CEditWidgetListForm(&(pTemplate->Widgets()) ,pTemplates, pManager)
{

}

CEditTemplateMixersForm::~CEditTemplateMixersForm()
{

}
