// StartupForm.cpp: implementation of the CStartupForm class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SuperTX.h"
#include "StartupForm.h"
#include "Display.h"
#include "FormManager.h"
#include "MainForm.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


extern BitmapT logo;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CStartupForm::CStartupForm(CFormManager* pManager)
: CForm(pManager)
{

}

CStartupForm::~CStartupForm()
{

}

void CStartupForm::OnButton()
{
  Manager()->ShowForm(new CMainForm(Manager()));
}

void CStartupForm::OnCmd0() {OnButton();}
void CStartupForm::OnCmd1() {OnButton();}
void CStartupForm::OnCmd2() {OnButton();}
void CStartupForm::OnCmd3() {OnButton();}
void CStartupForm::OnCmd4() {OnButton();}
void CStartupForm::OnCmd5() {OnButton();}
void CStartupForm::OnCmd6() {OnButton();}
void CStartupForm::OnCmd7() {OnButton();}

void CStartupForm::Paint(CDisplay* pDisplay)
{
  assert(this);
  assert(pDisplay);
  pDisplay->Draw(logo);
}

