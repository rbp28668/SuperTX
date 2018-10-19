// EditTemplateDlg.cpp : implementation file
//

#include "stdafx.h"
#include <string>
#include "SuperTX.h"
#include "EditTemplateDlg.h"
#include "NewWidgetDlg.h"
#include "Group.h"
#include "Error.h"
#include "NewGroupIODlg.h"
#include "WindowsEditContext.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEditTemplateDlg dialog


CEditTemplateDlg::CEditTemplateDlg(CGroupTemplate* pTemplate, CTemplateList* pTemplates, CWnd* pParent /*=NULL*/)
	: CDialog(CEditTemplateDlg::IDD, pParent)
  , m_pTemplate(pTemplate)
  , m_pTemplates(pTemplates)
{
  assert(pTemplate);
  assert(pTemplates);
	//{{AFX_DATA_INIT(CEditTemplateDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CEditTemplateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEditTemplateDlg)
	DDX_Control(pDX, IDC_CMD_FREEZE, m_cmdFreeze);
	DDX_Control(pDX, IDC_LST_OUTPUTS, m_lstOutputs);
	DDX_Control(pDX, IDC_LST_INPUTS, m_lstInputs);
	DDX_Control(pDX, IDC_LST_TEMPLATE_WIDGETS, m_lstTemplateWidgets);
	DDX_Control(pDX, IDC_CMD_ADD_WIDGET, m_cmdAddWidget);
	DDX_Control(pDX, IDC_LST_WIDGETS, m_lstTemplates);
	DDX_Control(pDX, IDC_CMD_EDIT_MIXER, m_cmdEditMixer);
	DDX_Control(pDX, IDC_CMD_DELETE_WIDGET, m_cmdDeleteMixer);
	DDX_Control(pDX, IDC_CMD_DELETE_OUTPUT, m_cmdDeleteOutput);
	DDX_Control(pDX, IDC_CMD_DELETE_INPUT, m_cmdDeleteInput);
	DDX_Control(pDX, IDC_CMD_CONNECT, m_cmdConnect);
	DDX_Control(pDX, IDC_CMB_SOURCE_WIDGET, m_cmbSourceWidget);
	DDX_Control(pDX, IDC_CMB_SOURCE_OUTPUT, m_cmbSourceOutput);
	DDX_Control(pDX, IDC_CMB_DEST_WIDGET, m_cmbDestWidget);
	DDX_Control(pDX, IDC_CMB_DEST_INPUT, m_cmbDestInput);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEditTemplateDlg, CDialog)
	//{{AFX_MSG_MAP(CEditTemplateDlg)
	ON_LBN_DBLCLK(IDC_LST_WIDGETS, OnDblclkLstWidgets)
	ON_LBN_SELCHANGE(IDC_LST_WIDGETS, OnSelchangeLstWidgets)
	ON_CBN_SELCHANGE(IDC_CMB_DEST_INPUT, OnSelchangeCmbDestInput)
	ON_CBN_SELCHANGE(IDC_CMB_DEST_WIDGET, OnSelchangeCmbDestWidget)
	ON_CBN_SELCHANGE(IDC_CMB_SOURCE_OUTPUT, OnSelchangeCmbSourceOutput)
	ON_CBN_SELCHANGE(IDC_CMB_SOURCE_WIDGET, OnSelchangeCmbSourceWidget)
	ON_BN_CLICKED(IDC_CMD_ADD_INPUT, OnCmdAddInput)
	ON_BN_CLICKED(IDC_CMD_ADD_OUTPUT, OnCmdAddOutput)
	ON_BN_CLICKED(IDC_CMD_ADD_WIDGET, OnCmdAddWidget)
	ON_BN_CLICKED(IDC_CMD_CONNECT, OnCmdConnect)
	ON_BN_CLICKED(IDC_CMD_DELETE_INPUT, OnCmdDeleteInput)
	ON_BN_CLICKED(IDC_CMD_DELETE_OUTPUT, OnCmdDeleteOutput)
	ON_BN_CLICKED(IDC_CMD_DELETE_WIDGET, OnCmdDeleteWidget)
	ON_BN_CLICKED(IDC_CMD_EDIT_MIXER, OnCmdEditMixer)
	ON_LBN_SELCHANGE(IDC_LST_INPUTS, OnSelchangeLstInputs)
	ON_LBN_SELCHANGE(IDC_LST_OUTPUTS, OnSelchangeLstOutputs)
	ON_BN_CLICKED(IDC_CMD_FREEZE, OnCmdFreeze)
	ON_LBN_SELCHANGE(IDC_LST_TEMPLATE_WIDGETS, OnSelchangeLstTemplateWidgets)
	ON_LBN_DBLCLK(IDC_LST_TEMPLATE_WIDGETS, OnDblclkLstTemplateWidgets)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEditTemplateDlg message handlers






void CEditTemplateDlg::OnDblclkLstWidgets() 
{
  OnCmdAddWidget();
}

void CEditTemplateDlg::OnSelchangeLstWidgets() 
{
  m_cmdAddWidget.EnableWindow(m_lstTemplates.Selected() != 0);
}

void CEditTemplateDlg::OnSelchangeCmbDestInput() 
{
  m_cmdConnect.EnableWindow(m_cmbSourceOutput.Selected() 
                          && m_cmbDestInput.Selected());
}

void CEditTemplateDlg::OnSelchangeCmbDestWidget() 
{
  CWidget* pWidget = m_cmbDestWidget.Selected();
  if(pWidget)
    {
    m_cmbDestInput.Update(*pWidget);
    m_cmdConnect.EnableWindow(false);
    }
}

void CEditTemplateDlg::OnSelchangeCmbSourceOutput() 
{
  m_cmdConnect.EnableWindow(m_cmbSourceOutput.Selected() 
                          && m_cmbDestInput.Selected());
}

void CEditTemplateDlg::OnSelchangeCmbSourceWidget() 
{
  CWidget* pWidget = m_cmbSourceWidget.Selected();
  if(pWidget)
    {
    m_cmbSourceOutput.Update(*pWidget);
    m_cmdConnect.EnableWindow(false);
    }
}

void CEditTemplateDlg::OnCmdAddInput() 
{
	CNewGroupIODlg dlg;
  dlg.SetTitle("New Input");


  while(dlg.DoModal() == IDOK)
    {
    std::string strName = dlg.m_strName;
    const CConnectorWidget& inputs = m_pTemplate->Inputs();
    bool blUnique = true;
    
    for(int i=0; i<inputs.InputCount(); ++i)
      {
      if(inputs.Input(i).Name() == strName)
        {
        blUnique = false;
        break;
        }
      }

    if(blUnique)
      {
      CInput* pInput = m_pTemplate->AddInput(strName,dlg.Type());
      m_lstInputs.Add(pInput);
      break;
      }
    else
      CError(IDS_ERR_INPUT_NAME_NOT_UNIQUE);
    }
	
}

void CEditTemplateDlg::OnCmdAddOutput() 
{
	CNewGroupIODlg dlg;
  dlg.SetTitle("New Output");


  while(dlg.DoModal() == IDOK)
    {
    std::string strName = dlg.m_strName;
    const CConnectorWidget& outputs = m_pTemplate->Outputs();
    bool blUnique = true;
    
    for(int i=0; i<outputs.OutputCount(); ++i)
      {
      if(outputs.Output(i).Name() == strName)
        {
        blUnique = false;
        break;
        }
      }

    if(blUnique)
      {
      COutput* pOutput = m_pTemplate->AddOutput(strName,dlg.Type());
      m_lstOutputs.Add(pOutput);
      break;
      }
    else
      CError(IDS_ERR_OUTPUT_NAME_NOT_UNIQUE);
    }
}

void CEditTemplateDlg::OnCmdAddWidget() 
{
	CWidgetTemplate* pTemplate = m_lstTemplates.Selected();
  assert(pTemplate);

	CNewWidgetDlg dlg;

  while(dlg.DoModal() == IDOK)
    {
    std::string strName = dlg.m_strName;
    
    CWidget* pWidget = 0;
    if(!m_pTemplate->Widgets().Find(strName,pWidget))
      {
      pWidget = pTemplate->Create(strName);
      m_lstTemplateWidgets.Add(pWidget);
      m_cmbSourceWidget.Add(pWidget);
      m_cmbDestWidget.Add(pWidget);

      m_pTemplate->Widgets().Add(pWidget);
      break;
      }
    else
      {
      CError(IDS_ERR_WIDGET_NAME_NOT_UNIQUE);
      }
    }
}


void CEditTemplateDlg::OnCmdConnect() 
{
  assert(m_cmbSourceOutput.Selected());
  assert(m_cmbDestInput.Selected());

  if(m_cmbDestInput.Selected()->Type() == m_cmbSourceOutput.Selected()->Type())
    {
    if(!m_cmbDestInput.Selected()->Connect(m_cmbSourceOutput.Selected()))
      CError(IDS_UNABLE_TO_CONNECT);
    }
  else
    CError(IDS_CONNECT_DIFFERENT_TYPES);
}

void CEditTemplateDlg::OnCmdDeleteInput() 
{
	const CInput* pInput = m_lstInputs.Selected();
  assert(pInput);
  m_pTemplate->DeleteInput(pInput->Name());
  m_lstInputs.Update(m_pTemplate->Inputs());
  m_cmbSourceOutput.ResetContent();
}

void CEditTemplateDlg::OnCmdDeleteOutput() 
{
	const COutput* pOutput = m_lstOutputs.Selected();
  assert(pOutput);
  m_pTemplate->DeleteOutput(pOutput->Name());
  m_lstOutputs.Update(m_pTemplate->Outputs());
  m_cmbDestInput.ResetContent();
}

void CEditTemplateDlg::OnCmdDeleteWidget() 
{
	const CWidget* pWidget = m_lstTemplateWidgets.Selected();
  assert(pWidget);
  m_pTemplate->Widgets().Delete(pWidget->Name());
  m_cmbSourceWidget.Update(m_pTemplate->Widgets());
  m_cmbSourceOutput.ResetContent();
  m_cmbDestWidget.Update(m_pTemplate->Widgets());
  m_cmbDestInput.ResetContent();
  m_cmdConnect.EnableWindow(false);

  m_lstTemplateWidgets.Update(m_pTemplate->Widgets());
}

void CEditTemplateDlg::OnCmdEditMixer() 
{
  assert(this);
  CWidget* pWidget = m_lstTemplateWidgets.Selected();
  assert(pWidget);
  assert(pWidget->CanEdit());

  CWindowsEditContext context;
  pWidget->Edit(&context);
}

void CEditTemplateDlg::OnSelchangeLstInputs() 
{
  m_cmdDeleteInput.EnableWindow(m_lstInputs.Selected() != 0);
}

void CEditTemplateDlg::OnSelchangeLstOutputs() 
{
  m_cmdDeleteOutput.EnableWindow(m_lstOutputs.Selected() != 0);
}

void CEditTemplateDlg::OnSelchangeLstTemplateWidgets() 
{
  assert(this);
  CWidget* pWidget = m_lstTemplateWidgets.Selected();
  bool blCanEdit = pWidget && pWidget->CanEdit();
  m_cmdEditMixer.EnableWindow(blCanEdit);
  m_cmdFreeze.EnableWindow(blCanEdit);
  m_cmdDeleteMixer.EnableWindow(pWidget && pWidget->CanDelete());
}

void CEditTemplateDlg::OnDblclkLstTemplateWidgets() 
{
  CWidget* pWidget = m_lstTemplateWidgets.Selected();
  bool blCanEdit = pWidget && pWidget->CanEdit();
  if(blCanEdit)
    OnCmdEditMixer();
}


BOOL CEditTemplateDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
  m_cmbSourceWidget.Update(m_pTemplate->Widgets());
  m_cmbDestWidget.Update(m_pTemplate->Widgets());
  m_lstTemplateWidgets.Update(m_pTemplate->Widgets());
  m_lstTemplates.Update(*m_pTemplates);
  m_lstInputs.Update(m_pTemplate->Inputs());
  m_lstOutputs.Update(m_pTemplate->Outputs());
	return TRUE;  
}

void CEditTemplateDlg::OnCmdFreeze() 
{
  CWidget* pWidget = m_lstTemplateWidgets.Selected();
  assert(pWidget);
  pWidget->Freeze();
  m_cmdEditMixer.EnableWindow(false);
  m_cmdFreeze.EnableWindow(false);
}

