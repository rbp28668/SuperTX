// ConnectForm.cpp: implementation of the CConnectForm class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SuperTX.h"
#include "ConnectForm.h"
#include "Display.h"
#include "WidgetList.h"
#include "FormManager.h"
#include "Error.h"
#include "Widgets.hpp"
#include "Type.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


CConnectSelect::CConnectSelect()
: m_strDest("")
, m_strInput("")
, m_strSrc("")
, m_strOutput("")
, m_blPaintConnection(true)
{
}

void CConnectSelect::Add(const CWidget* ptr, CDisplay* pDisplay) 
{
  assert(this);
  assert(ptr);
  CSelection::Add(ptr->Name(), (void*)ptr, pDisplay);
  m_blPaintConnection = false;
}

CWidget* CConnectSelect::SelectedWidget() 
{
  assert(this);
  return static_cast<CWidget*>(CSelection::SelectedPtr());
}

void CConnectSelect::Add(const CInput* ptr, CDisplay* pDisplay) 
{
  assert(this);
  assert(ptr);
  CSelection::Add(ptr->Name(), (void*)ptr, pDisplay);
  m_blPaintConnection = false;
}

CInput* CConnectSelect::SelectedInput() 
{
  assert(this);
  return static_cast<CInput*>(CSelection::SelectedPtr());
}

void CConnectSelect::Add(const COutput* ptr, CDisplay* pDisplay)
{
  assert(this);
  assert(ptr);
  CSelection::Add(ptr->Name(), (void*)ptr, pDisplay);
  m_blPaintConnection = false;
}

COutput* CConnectSelect::SelectedOutput() 
{
  assert(this);
  return static_cast<COutput*>(CSelection::SelectedPtr());
}

void CConnectSelect::Paint(CDisplay* pDisplay)
{
  assert(this);
  assert(pDisplay);

  if(m_blPaintConnection)
    {
    CRect rPos = ScreenPosition();

    pDisplay->Rectangle (rPos.left, rPos.top, rPos.right, rPos.bottom);
  
    int cx = Font().m_iWidth;
    int cy = Font().m_iHeight;

    int ix = rPos.left + cx/2;
    int iy = rPos.top + 1;

    pDisplay->Text("Connect", ix,iy, Font());
    iy += cy;
    pDisplay->Text(m_strDest, ix,iy, Font());
    iy += cy;
    pDisplay->Text(m_strInput, ix,iy, Font());
    iy += cy;
    pDisplay->Text("To", ix,iy, Font());
    iy += cy;
    pDisplay->Text(m_strSrc, ix,iy, Font());
    iy += cy;
    pDisplay->Text(m_strOutput, ix,iy, Font());
    }
  else
    {
    CSelection::Paint(pDisplay);
    }

}

void CConnectSelect::PaintConnection()
{
  assert(this);
  m_blPaintConnection = true;
}

void CConnectSelect::Destination(const std::string& strName)
{
  assert(this);
  m_strDest = strName;
}

void CConnectSelect::Input(const std::string& strName)
{
  assert(this);
  m_strInput = strName;
}

void CConnectSelect::Source(const std::string& strName)
{
  assert(this);
  m_strSrc = strName;
}

void CConnectSelect::Output(const std::string& strName)
{
  assert(this);
  m_strOutput = strName;
}


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CConnectForm::CConnectForm(CWidgetList* pWidgets, CFormManager* pManager)
: CSelectionForm(pManager, &m_select)
, m_pWidgets(pWidgets)
, m_pSourceWidget(0)
, m_pDestWidget(0)
, m_pSourceOutput(0)
, m_pDestInput(0)
, m_mode(CONNECT)
{

}

CConnectForm::~CConnectForm()
{

}

void CConnectForm::OnCmd0() // Dest
{
  assert(this);
  DisplayInputWidgets();
  m_mode = DEST;
  Paint(&Manager()->Display());
}

void CConnectForm::OnCmd1() // Input
{
  assert(this);
  if(m_pDestWidget)
    {
    DisplayInputs(m_pDestWidget);
    m_mode = INPUT;
    Paint(&Manager()->Display());
    }
}

void CConnectForm::OnCmd2() // Source
{
  assert(this);
  DisplayOutputWidgets();
  m_mode = SOURCE;
  Paint(&Manager()->Display());
}

void CConnectForm::OnCmd3() // Output
{
  assert(this);
  if(m_pSourceWidget)
    {
    DisplayOutputs(m_pSourceWidget);
    m_mode = OUTPUT;
    Paint(&Manager()->Display());
    }
}

void CConnectForm::OnCmd6() // Connect
{
  assert(this);
  bool blSetConnect = false;

  switch(m_mode)
    {
    case CONNECT:
      // can we make a connection? - both input & output must be
      // defined & the types must be the same.
      if(m_pSourceOutput && m_pDestInput)
        {
        if(m_pDestInput->Type() == m_pSourceOutput->Type())
          {
          if(!m_pDestInput->Connect(m_pSourceOutput))
            CError(IDS_UNABLE_TO_CONNECT);
          }
        else
          {
          CError(IDS_CONNECT_DIFFERENT_TYPES);
          }
        }
      break;

    case SOURCE:
      m_pSourceWidget = m_select.SelectedWidget();
      if(m_pSourceWidget)
        m_select.Source(m_pSourceWidget->Name());
      m_mode = CONNECT;
      break;

    case OUTPUT:
      m_pSourceOutput = m_select.SelectedOutput();
      if(m_pSourceOutput)
        m_select.Output(m_pSourceOutput->Name());
      m_mode = CONNECT;
      break;

    case DEST:
      m_pDestWidget = m_select.SelectedWidget();
      if(m_pDestWidget)
        m_select.Destination(m_pDestWidget->Name());
      m_mode = CONNECT;
      break;

    case INPUT:
      m_pDestInput = m_select.SelectedInput();
      if(m_pDestInput)
        m_select.Input(m_pDestInput->Name());
      m_mode = CONNECT;
      break;

    }

  Paint(&Manager()->Display());
}


void CConnectForm::Paint(CDisplay* pDisplay)
{
  assert(this);
  assert(pDisplay);

  pDisplay->Clear();

  SetButton(0,"Dest");
  SetButton(1,"Input");
  SetButton(2,"Source");
  SetButton(3,"Output");

  if(m_mode == CONNECT)
    {
    SetButton(6,"Connect");
    m_select.PaintConnection();
    }
  else
    SetButton(6,"Set");

  CSelectionForm::Paint(pDisplay);
}

void CConnectForm::DisplayInputWidgets()
{
  assert(this);
  m_select.RemoveAll();
  m_select.Title("Dest");

  for(CWidgetList::const_iterator iter = m_pWidgets->Begin();
    iter != m_pWidgets->End();
    ++iter)
    {
    const CWidget* pWidget = *iter;
    if(pWidget->InputCount() > 0)
      m_select.Add(pWidget);
    }
  m_select.Paint(&Manager()->Display());
}

void CConnectForm::DisplayOutputWidgets()
{
  assert(this);
  m_select.RemoveAll();
  m_select.Title("Source");

  for(CWidgetList::iterator iter = m_pWidgets->Begin();
    iter != m_pWidgets->End();
    ++iter)
    {
    CWidget* pWidget = *iter;
    if(pWidget->OutputCount() > 0)
      m_select.Add(pWidget);
    }
  m_select.Paint(&Manager()->Display());
}

void CConnectForm::DisplayInputs(CWidget* pWidget)
{
  assert(this);
  m_select.RemoveAll();
  m_select.Title("Inputs");

  for(int i=0; i<pWidget->InputCount(); ++i)
    {
    m_select.Add(pWidget->Input(i));
    }
  m_select.Paint(&Manager()->Display());
}

void CConnectForm::DisplayOutputs(CWidget* pWidget)
{
  assert(this);
  m_select.RemoveAll();
  m_select.Title("Outputs");

  for(int i=0; i<pWidget->OutputCount(); ++i)
    {
    m_select.Add(pWidget->Output(i));
    }
  m_select.Paint(&Manager()->Display());
}


