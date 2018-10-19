// MainForm.cpp: implementation of the CMainForm class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SuperTX.h"
#include "MainForm.h"
#include "FormManager.h"
#include "Transmitter.h"
#include "Display.h"

// Forms called from this one.
#include "ModelsForm.h"
#include "TemplatesForm.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMainForm::CMainForm(CFormManager* pManager)
: CForm(pManager)
, m_pModels(&Tx().Models())
, m_pEncoder(&Tx().Encoder())
, m_pTemplates(&Tx().Templates())
{

}

CMainForm::~CMainForm()
{

}

// NOP
void CMainForm::OnCmd0()
{
}

// Timer 1
void CMainForm::OnCmd1()
{
}

// Timer 2
void CMainForm::OnCmd2()
{
}

// NOP
void CMainForm::OnCmd3()
{
}

// Models
void CMainForm::OnCmd4()
{
  Manager()->MarkCurrent(); // want to return to this form when models closes
  Manager()->ShowForm(new CModelsForm(m_pEncoder, m_pModels, m_pTemplates, Manager()));
}

// Templates
void CMainForm::OnCmd5()
{
  Manager()->MarkCurrent(); // want to return to this form when models closes
  Manager()->ShowForm(new CTemplatesForm(m_pTemplates, Manager()));
}

// Timers
void CMainForm::OnCmd6()
{
}

// Buddy box
void CMainForm::OnCmd7()
{
}


void CMainForm::Paint(CDisplay* pDisplay) 
{
  pDisplay->Clear();

  SetButton(1,"Start");
  SetButton(2,"Start");
  SetButton(3,"Misc");
  SetButton(4,"Models");
  SetButton(5,"Templates");
  SetButton(6,"Timers");
  SetButton(7,"Buddy Box");

  CRect rClient = Client();
  int ixOffset = Font().m_iWidth/2;
  int iLeft = rClient.left + ixOffset;
  int iRight = rClient.right - 1 - ixOffset;

  pDisplay->Rectangle(iLeft, rClient.top, iRight, rClient.bottom-1);

  // 4 blocks in client area
  for(int i=0; i<PANELS; ++i)
    {
    int iy = (i+1) * rClient.Height() / PANELS;
    pDisplay->Line(iLeft, iy, iRight, iy);
    
    m_arPanels[i].left = iLeft;
    m_arPanels[i].top = i *rClient.Height() / PANELS;
    m_arPanels[i].right = iRight;
    m_arPanels[i].bottom = iy;
    }

  // vertical space assuming 2 lines of text
  int iySpace = (m_arPanels[MODEL].Height() - 2*Font().m_iHeight)/3;

  int ix = m_arPanels[MODEL].left + ixOffset;
  int iy = m_arPanels[MODEL].top + iySpace;
  pDisplay->Text("Model", ix, iy, Font());

  iy += Font().m_iHeight + iySpace;
  m_ptModelName.x = ix;
  m_ptModelName.y = iy;
  pDisplay->Text("Default", ix, iy, Font());

  ix = m_arPanels[TIMER1].left + ixOffset;
  iy = m_arPanels[TIMER1].top + iySpace;
  pDisplay->Text("Timer1", ix, iy, Font());
  iy += Font().m_iHeight + iySpace;
  m_ptTimer1.x = ix;
  m_ptTimer1.y = iy;
  pDisplay->Text("0:00", ix, iy, Font());

  ix = m_arPanels[TIMER2].left + ixOffset;
  iy = m_arPanels[TIMER2].top + iySpace;
  pDisplay->Text("Timer2", ix, iy, Font());
  iy += Font().m_iHeight + iySpace;
  m_ptTimer2.x = ix;
  m_ptTimer2.y = iy;
  pDisplay->Text("0:00", ix, iy, Font());

  ix = m_arPanels[VOLTS].left + ixOffset;
  iy = m_arPanels[VOLTS].top + iySpace;
  pDisplay->Text("TX Volts", ix, iy, Font());
  iy += Font().m_iHeight + iySpace;
  m_ptVolts.x = ix;
  m_ptVolts.y = iy;
  pDisplay->Text("9.6V", ix, iy, Font());

  pDisplay->Update();
}
