// MainEditDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SuperTX.h"
#include "MainEditDlg.h"
#include "ModelList.h"
#include "Encoder.h"
#include "NewModelDlg.h"
#include "NewWidgetDlg.h"
#include "TemplateList.h"
#include "Error.h"
#include "Group.h"
#include "WindowsTemplateEditContext.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainEditDlg dialog


CMainEditDlg::CMainEditDlg(CEncoder* pEncoder, CModelList* pModels, CTemplateList* pTemplates, CWnd* pParent /*=NULL*/)
	: CDialog(CMainEditDlg::IDD, pParent)
  , m_pModels(pModels)
  , m_pEncoder(pEncoder)
  , m_pTemplates(pTemplates)
{
	//{{AFX_DATA_INIT(CMainEditDlg)
	//}}AFX_DATA_INIT
}


void CMainEditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMainEditDlg)
	DDX_Control(pDX, IDC_LST_WIDGETS, m_lstTemplates);
	DDX_Control(pDX, IDC_CMD_WIDGETS_EDIT, m_cmdTemplateEdit);
	DDX_Control(pDX, IDC_CMD_MODEL_SELECT, m_cmdModelSelect);
	DDX_Control(pDX, IDC_CMD_MODEL_EDIT, m_cmdModelEdit);
	DDX_Control(pDX, IDC_LST_MODEL_SELECT, m_lstModels);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMainEditDlg, CDialog)
	//{{AFX_MSG_MAP(CMainEditDlg)
	ON_BN_CLICKED(IDC_CMD_MODEL_EDIT, OnCmdModelEdit)
	ON_BN_CLICKED(IDC_CMD_MODEL_NEW, OnCmdModelNew)
	ON_BN_CLICKED(IDC_CMD_MODEL_SELECT, OnCmdModelSelect)
	ON_BN_CLICKED(IDC_CMD_WIDGETS_EDIT, OnCmdTemplateEdit)
	ON_BN_CLICKED(IDC_CMD_WIDGETS_NEW, OnCmdTemplatesNew)
	ON_LBN_SELCHANGE(IDC_LST_MODEL_SELECT, OnSelchangeLstModelSelect)
	ON_LBN_DBLCLK(IDC_LST_MODEL_SELECT, OnDblclkLstModelSelect)
	ON_LBN_DBLCLK(IDC_LST_WIDGETS, OnDblclkLstTemplates)
	ON_LBN_SELCHANGE(IDC_LST_WIDGETS, OnSelchangeLstTemplates)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainEditDlg message handlers

void CMainEditDlg::OnCmdModelEdit() 
{
  CModel* pModel = m_lstModels.Selected();
  assert(pModel); // button disabled if none selected (we hope)
  CEditModelDlg dlg(pModel, m_pTemplates);
  dlg.DoModal();
}

void CMainEditDlg::OnCmdModelNew() 
{
	CNewModelDlg dlg;

  while(dlg.DoModal() == IDOK)
    {
    std::string strName = dlg.m_strName;
    
    CModel* pModel = 0;
    if(!m_pModels->Find(strName,pModel))
      {
      pModel = m_pModels->NewModel(strName);
      m_lstModels.Add(pModel);
      m_pEncoder->Connect(pModel->Proxy());
      break;
      }
    else
      {
      CError(IDS_ERR_MODEL_NAME_NOT_UNIQUE);
      }
    }
	
}

void CMainEditDlg::OnCmdModelSelect() 
{
  CModel* pModel = m_lstModels.Selected();
  if(pModel)
    m_pEncoder->Connect(pModel->Proxy());
}

void CMainEditDlg::OnCmdTemplateEdit() 
{
  CWindowsTemplateEditContext context;
  CWidgetTemplate* pTemplate = m_lstTemplates.Selected();
  assert(pTemplate);
  pTemplate->Edit(&context, m_pTemplates);
}

void CMainEditDlg::OnCmdTemplatesNew() 
{
  CNewWidgetDlg dlg;

	while(dlg.DoModal() == IDOK)
    {
    std::string strName = dlg.m_strName;

    CWidgetTemplate* pTemplate = 0;
    if(!m_pTemplates->Find(strName, pTemplate))
      {
      pTemplate = new CGroupTemplate(strName);
      m_pTemplates->Add(pTemplate);
      m_lstTemplates.Add(pTemplate);

      // Straight into edit.
      CWindowsTemplateEditContext context;
      pTemplate->Edit(&context, m_pTemplates);
      break;
      }
    else
      {
      CError(IDS_ERR_TEMPLATE_NAME_NOT_UNIQUE);
      }
    }
	
}

void CMainEditDlg::OnSelchangeLstModelSelect() 
{
  BOOL blEnable = m_lstModels.GetCurSel() != LB_ERR;
  m_cmdModelSelect.EnableWindow(blEnable);
  m_cmdModelEdit.EnableWindow(blEnable);
}

void CMainEditDlg::OnDblclkLstModelSelect() 
{
	OnCmdModelSelect();
}

void CMainEditDlg::OnDblclkLstTemplates() 
{
  if(m_lstTemplates.Selected())
	  OnCmdTemplateEdit();
}

void CMainEditDlg::OnSelchangeLstTemplates() 
{
  bool blEnable = false;
  CWidgetTemplate* pTemplate = m_lstTemplates.Selected();
  if(pTemplate && pTemplate->CanEdit())
    blEnable = true;
	m_cmdTemplateEdit.EnableWindow(blEnable);
}

BOOL CMainEditDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

  m_lstModels.Update(m_pModels);
  m_lstTemplates.Update(*m_pTemplates);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
