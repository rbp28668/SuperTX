// WindowsTemplateEditContext.cpp: implementation of the CWindowsTemplateEditContext class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SuperTx.h" // needed for group edit dialog
#include "WindowsTemplateEditContext.h"
#include "Group.h"
#include "EditTemplateDlg.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CWindowsTemplateEditContext::CWindowsTemplateEditContext()
{

}

CWindowsTemplateEditContext::~CWindowsTemplateEditContext()
{

}

void CWindowsTemplateEditContext::EditGroupTemplate(CGroupTemplate* pTemplate, CTemplateList* pTemplates) const
{
  assert(this);
  assert(pTemplate);

  CEditTemplateDlg dlg(pTemplate, pTemplates);

  dlg.DoModal();

}