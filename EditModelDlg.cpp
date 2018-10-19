// EditModelDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SuperTX.h"
#include "EditModelDlg.h"
#include "Model.h"
#include "Error.h"
#include "Type.h"
#include "NewWidgetDlg.h"
#include "WindowsEditContext.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEditModelDlg dialog


CEditModelDlg::CEditModelDlg(CModel* pModel, CTemplateList* pTemplates, CWnd* pParent /*=NULL*/)
	: CDialog(CEditModelDlg::IDD, pParent)
  , m_pModel(pModel)
  , m_pTemplates(pTemplates)
{
	//{{AFX_DATA_INIT(CEditModelDlg)
	//}}AFX_DATA_INIT
}


void CEditModelDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEditModelDlg)
	DDX_Control(pDX, IDC_CMD_DELETE_WIDGET, m_cmdDeleteWidget);
	DDX_Control(pDX, IDC_CMD_EDIT_MIXER, m_cmdEditMixer);
	DDX_Control(pDX, IDC_CMD_ADD_WIDGET, m_cmdAddWidget);
	DDX_Control(pDX, IDC_LST_MODEL_WIDGETS, m_lstModelWidgets);
	DDX_Control(pDX, IDC_LST_WIDGETS, m_lstWidgets);
	DDX_Control(pDX, IDC_CMD_CONNECT, m_cmdConnect);
	DDX_Control(pDX, IDC_CMB_SOURCE_OUTPUT, m_cmbSourceOutput);
	DDX_Control(pDX, IDC_CMB_DEST_INPUT, m_cmbDestInput);
	DDX_Control(pDX, IDC_CMB_SOURCE_WIDGET, m_cmbSourceWidget);
	DDX_Control(pDX, IDC_CMB_DEST_WIDGET, m_cmbDestWidget);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEditModelDlg, CDialog)
	//{{AFX_MSG_MAP(CEditModelDlg)
	ON_CBN_SELCHANGE(IDC_CMB_DEST_WIDGET, OnSelchangeCmbDestWidget)
	ON_CBN_SELCHANGE(IDC_CMB_SOURCE_WIDGET, OnSelchangeCmbSourceWidget)
	ON_CBN_SELCHANGE(IDC_CMB_DEST_INPUT, OnSelchangeCmbDestInput)
	ON_CBN_SELCHANGE(IDC_CMB_SOURCE_OUTPUT, OnSelchangeCmbSourceOutput)
	ON_BN_CLICKED(IDC_CMD_CONNECT, OnCmdConnect)
	ON_LBN_SELCHANGE(IDC_LST_WIDGETS, OnSelchangeLstWidgets)
	ON_BN_CLICKED(IDC_CMD_ADD_WIDGET, OnCmdAddWidget)
	ON_BN_CLICKED(IDC_CMD_DELETE_WIDGET, OnCmdDeleteWidget)
	ON_BN_CLICKED(IDC_CMD_EDIT_MIXER, OnCmdEditMixer)
	ON_LBN_SELCHANGE(IDC_LST_MODEL_WIDGETS, OnSelchangeLstModelWidgets)
	ON_LBN_DBLCLK(IDC_LST_WIDGETS, OnDblclkLstWidgets)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEditModelDlg message handlers

BOOL CEditModelDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
  m_cmbSourceWidget.Update(m_pModel->Widgets());	
  m_cmbDestWidget.Update(m_pModel->Widgets());	
  m_lstWidgets.Update(*m_pTemplates);
  m_lstModelWidgets.Update(m_pModel->Widgets());

  return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CEditModelDlg::OnSelchangeCmbDestWidget() 
{
  CWidget* pWidget = m_cmbDestWidget.Selected();
  if(pWidget)
    {
    m_cmbDestInput.Update(*pWidget);
    m_cmdConnect.EnableWindow(false);

    if(m_cmbDestInput.GetCount() == 1)
      {
      m_cmbDestInput.SetCurSel(0);
      OnSelchangeCmbDestInput();
      }
    }
}

void CEditModelDlg::OnSelchangeCmbSourceWidget() 
{
  CWidget* pWidget = m_cmbSourceWidget.Selected();
  if(pWidget)
    {
    m_cmbSourceOutput.Update(*pWidget);
    m_cmdConnect.EnableWindow(false);

    if(m_cmbSourceOutput.GetCount() == 1)
      {
      m_cmbSourceOutput.SetCurSel(0);
      OnSelchangeCmbSourceOutput();
      }
    }
}

void CEditModelDlg::OnSelchangeCmbDestInput() 
{
  m_cmdConnect.EnableWindow(m_cmbSourceOutput.Selected() 
                          && m_cmbDestInput.Selected());
}

void CEditModelDlg::OnSelchangeCmbSourceOutput() 
{
  m_cmdConnect.EnableWindow(m_cmbSourceOutput.Selected() 
                          && m_cmbDestInput.Selected());
}

void CEditModelDlg::OnCmdConnect() 
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

void CEditModelDlg::OnSelchangeLstWidgets() 
{
  m_cmdAddWidget.EnableWindow(m_lstWidgets.Selected() != 0);
}

void CEditModelDlg::OnCmdAddWidget() 
{
	CWidgetTemplate* pTemplate = m_lstWidgets.Selected();
  assert(pTemplate);

	CNewWidgetDlg dlg;

  while(dlg.DoModal() == IDOK)
    {
    std::string strName = dlg.m_strName;
    
    CWidget* pWidget = 0;
    if(!m_pModel->Widgets().Find(strName,pWidget))
      {
      pWidget = pTemplate->Create(strName);
      m_lstModelWidgets.Add(pWidget);
      m_cmbSourceWidget.Add(pWidget);
      m_cmbDestWidget.Add(pWidget);

      m_pModel->Widgets().Add(pWidget);
      break;
      }
    else
      {
      CError(IDS_ERR_WIDGET_NAME_NOT_UNIQUE);
      }
    }
}

void CEditModelDlg::OnCmdDeleteWidget() 
{
  assert(this);
	CWidget* pWidget = m_lstModelWidgets.Selected();
  assert(pWidget);
  m_pModel->Widgets().Delete(pWidget->Name());
 
  // Make sure that both this list, & the source & destination
  // lists are updated
  m_lstModelWidgets.DeleteString(m_lstModelWidgets.GetCurSel());
  m_cmbSourceWidget.Update(m_pModel->Widgets());
  m_cmbSourceOutput.ResetContent(); // clear selection
  m_cmbDestWidget.Update(m_pModel->Widgets());	
  m_cmbDestInput.ResetContent(); // clear selection.
  m_cmdConnect.EnableWindow(false);
}

void CEditModelDlg::OnCmdEditMixer() 
{
  assert(this);
  assert(m_lstModelWidgets.Selected());
  CWindowsEditContext context;
  m_lstModelWidgets.Selected()->Edit(&context);
}

void CEditModelDlg::OnSelchangeLstModelWidgets() 
{
  assert(this);
	bool blSelected = m_lstModelWidgets.Selected() != 0;

  m_cmdDeleteWidget.EnableWindow(blSelected);
  if(blSelected)
    {
    m_cmdEditMixer.EnableWindow(m_lstModelWidgets.Selected()->CanEdit());
    }
}

void CEditModelDlg::OnDblclkLstWidgets() 
{
  OnCmdAddWidget();	
}
