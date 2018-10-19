// TXTemplateEditContext.cpp: implementation of the CTXTemplateEditContext class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SuperTX.h"
#include "TXTemplateEditContext.h"
#include "EditTemplateForm.h"
#include "FormManager.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTXTemplateEditContext::CTXTemplateEditContext(CFormManager* pManager)
: m_pManager(pManager)
{
  assert(pManager);
  pManager->MarkCurrent(); // always return to current form
                            // note - implies the edit context
                            // is created just in time
}

CTXTemplateEditContext::~CTXTemplateEditContext()
{

}

void CTXTemplateEditContext::EditGroupTemplate(CGroupTemplate* pTemplate, CTemplateList* pTemplates) const
{
  assert(this);
  assert(pTemplate);
  assert(pTemplates);

  // Previous form will have been marked when this edit context
  // was constructed.  Hence when edit finished it should return
  // to previous form.
  m_pManager->ShowForm(new CEditTemplateForm(pTemplate, pTemplates, m_pManager));
}
