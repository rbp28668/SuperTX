// EditAnalogueSettingDlg.cpp : implementation file
//

#include "stdafx.h"
#include <string>

#include "SuperTX.h"
#include "EditAnalogueSettingDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEditAnalogueSettingDlg dialog


CEditAnalogueSettingDlg::CEditAnalogueSettingDlg(CValue* pValue, CWnd* pParent /*=NULL*/)
	: CDialog(CEditAnalogueSettingDlg::IDD, pParent)
  , m_pValue(pValue)
{
	//{{AFX_DATA_INIT(CEditAnalogueSettingDlg)
	m_strValue = _T("");
	m_strTitle = _T("");
	//}}AFX_DATA_INIT

  m_valOriginal = *pValue;
}


void CEditAnalogueSettingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEditAnalogueSettingDlg)
	DDX_Control(pDX, IDC_SLD_VALUE, m_sliderValue);
	DDX_Text(pDX, IDC_EDT_VALUE, m_strValue);
	DDX_Text(pDX, IDC_LBL_TITLE, m_strTitle);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEditAnalogueSettingDlg, CDialog)
	//{{AFX_MSG_MAP(CEditAnalogueSettingDlg)
	ON_EN_CHANGE(IDC_EDT_VALUE, OnChangeEdtValue)
	ON_WM_HSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEditAnalogueSettingDlg message handlers

void CEditAnalogueSettingDlg::OnChangeEdtValue() 
{
}


BOOL CEditAnalogueSettingDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
  m_sliderValue.SetRange(0,CValue::Precision());
  m_sliderValue.SetLineSize(4);
  m_sliderValue.SetPageSize(CValue::Precision()/16);

  int iVal = m_pValue->Scale(CValue::Precision()/2) + CValue::Precision()/2;
  if(iVal < 0) iVal = 0;
  else if(iVal > CValue::Precision()) iVal = CValue::Precision();
  m_sliderValue.SetPos(iVal);

  std::string strValue;
  m_pValue->ToString(strValue);
  m_strValue = strValue.c_str();
  UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CEditAnalogueSettingDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
  // Slider sends WM_HSCROLL messages to dialog
  int iVal = m_sliderValue.GetPos();
  switch(nSBCode)
    {
    case TB_BOTTOM:
      iVal = m_sliderValue.GetRangeMin();
      break;

    case TB_ENDTRACK:
      break;
    case TB_LINEDOWN:
      break;
    case TB_LINEUP:
      break;
    case TB_PAGEDOWN:
      break;
    case TB_PAGEUP:
      break;

    case TB_THUMBPOSITION:
    case TB_THUMBTRACK:
      {
      iVal = nPos;
      break;
      }

    case TB_TOP:
      iVal = m_sliderValue.GetRangeMax();
      break;
    }

  iVal -= 2048;
  m_pValue->Set(iVal,2048);
  std::string strVal;
  m_pValue->ToString(strVal);
  m_strValue = strVal.c_str();
  UpdateData(FALSE);

}

void CEditAnalogueSettingDlg::OnCancel() 
{
  *m_pValue = m_valOriginal;	
	CDialog::OnCancel();
}
