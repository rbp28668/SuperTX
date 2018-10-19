// EditModelForm.cpp: implementation of the CEditModelForm class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SuperTX.h"
#include "EditModelForm.h"
#include "Display.h"
#include "WidgetList.h"
#include "Model.h"
#include "SelectTemplateForm.h"
#include "StringEntryForm.h"
#include "ConnectForm.h"
#include "FormManager.h"
#include "Error.h"
#include "TXEditContext.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CEditModelForm::CEditModelForm(CModel* pModel, CTemplateList* pTemplates, CFormManager* pManager)
: CEditWidgetListForm(&(pModel->Widgets()), pTemplates, pManager)
, m_pModel(pModel)
{
}

CEditModelForm::~CEditModelForm()
{

}

