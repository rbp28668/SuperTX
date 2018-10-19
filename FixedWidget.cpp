// FixedWidget.cpp: implementation of the CFixedWidget class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "FixedWidget.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFixedWidget::CFixedWidget()
{

}

CFixedWidget::~CFixedWidget()
{

}


COutput* CFixedWidget::Output(int /*idx*/)
{
  assert(this);
  assert(false);
  return 0;
}

const COutput& CFixedWidget::Output(int /*idx*/) const 
{
  assert(this);
  assert(false);
  return *static_cast<COutput*>(0);
}

int CFixedWidget::OutputCount() const 
{
  assert(this);
  return 0;
}


// Inputs
CInput* CFixedWidget::Input(int /*idx*/) 
{
  assert(this);
  assert(false);
  return 0;
}

const CInput& CFixedWidget::Input(int /*idx*/) const 
{
  assert(this);
  assert(false);
  return *static_cast<CInput*>(0);
}

int CFixedWidget::InputCount() const 
{
  assert(this);
  return 0;
}



// Creation
CWidget* CFixedWidget::Clone(const std::string& /*strName*/) const 
{
  assert(this);
  assert(false);
  return 0;
}

bool CFixedWidget::CanDelete() const 
{
  assert(this);
  return false;
}


// Editing
bool CFixedWidget::CanEdit() const 
{
  assert(this);
  return false;
}

void CFixedWidget::Edit(const CEditContext* /*pContext*/) 
{
  assert(this);
  assert(false);
}

void CFixedWidget::Freeze()
{
  assert(this);
  assert(false);
}
