// WindowsEditContext.cpp: implementation of the CWindowsEditContext class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SuperTx.h" // needed for edit dialogs
#include <string>
#include "WindowsEditContext.h"
#include "EditAnalogueSettingDlg.h"
#include "EditDigitalSettingDlg.h"
#include "EditGroupDlg.h"
#include "EditDelayDlg.h"
#include "EditRateLimiterDlg.h"
#include "EditLinearPieceWiseDlg.h"
#include "AnalogueSetting.h"
#include "DigitalSetting.h"
#include "WidgetList.h"
#include "Group.h"
#include "Delay.h"
#include "RateLimiter.h"



#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CWindowsEditContext::CWindowsEditContext()
{

}

CWindowsEditContext::~CWindowsEditContext()
{

}

void CWindowsEditContext::EditCAnalogueSetting(CAnalogueSetting* pWidget) const
{
  assert(this);
  assert(pWidget);

  CEditAnalogueSettingDlg dlg(&(pWidget->Value()));

  dlg.m_strTitle = pWidget->Name().c_str();

  dlg.DoModal();
}

void CWindowsEditContext::EditCDigitalSetting(CDigitalSetting* pWidget) const
{
  assert(this);
  assert(pWidget);

  CEditDigitalSettingDlg dlg;
  dlg.m_blVal = pWidget->Value();
  dlg.m_strTitle = pWidget->Name().c_str();
  if(dlg.DoModal())
    {
    pWidget->Value(dlg.m_blVal);
    }
}

void CWindowsEditContext::EditCGroup(CGroup* pWidget) const
{
  assert(this);
  assert(pWidget);

  // Check to see if only one editable sub-widget - if
  // so then edit it directly, otherwise put up dialog
  // so user can edit sub-widgets individually.
  CWidgetList& widgets = pWidget->Widgets();
  CWidgetList::iterator iter;
  CWidgetList::iterator iterToEdit;
  int nToEdit = 0;
  for(iter = widgets.Begin(); iter != widgets.End(); ++iter)
    {
    if((*iter)->CanEdit())
      {
      ++nToEdit;
      iterToEdit = iter;
      }
    }

  if(nToEdit == 1)
    (*iterToEdit)->Edit(this);
  else
    {
    CEditGroupDlg dlg(&widgets, this);
    dlg.DoModal();
    }
}

void CWindowsEditContext::EditCDelay(CDelay* pWidget) const
{
  assert(this);
  assert(pWidget);

  CEditDelayDlg dlg;
  dlg.m_iDelay = pWidget->Delay();
  if(dlg.DoModal() == IDOK)
    pWidget->Delay() = dlg.m_iDelay;
}

void CWindowsEditContext::EditCRateLimiter(CRateLimiter* pWidget) const
{
  assert(this);
  assert(pWidget);

  CEditRateLimiterDlg dlg;
  CValue delta = pWidget->Delta();

  // Given this delta, how long would it take (in ticks) to 
  // move the servo from one end of its travel to the other?
  int idelta = delta.Scale(CValue::Precision());
  dlg.m_iTransitTime = 2*CValue::Precision() / idelta;
  if(dlg.DoModal() == IDOK)
    {
    idelta = 2*CValue::Precision() / dlg.m_iTransitTime;
    if(idelta <= 0)
      idelta = 1;
    delta.Set(idelta,CValue::Precision());
    pWidget->Delta(delta);
    }
}

void CWindowsEditContext::EditCLinearPieceWise(CLinearPieceWise* pWidget) const
{
  assert(this);
  assert(pWidget);

  CEditLinearPieceWiseDlg dlg(pWidget);
  dlg.DoModal();
}



