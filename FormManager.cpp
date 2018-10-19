// FormManager.cpp: implementation of the CFormManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SuperTX.h"
#include "FormManager.h"
#include "Form.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

CFormManagerItem::CFormManagerItem()
: m_pForm(0)
, m_blMarked(false)
{
}
    
CFormManagerItem::CFormManagerItem(CForm* pForm)
: m_pForm(pForm)
, m_blMarked(false)
{
  assert(this);
  assert(pForm);
}

bool CFormManagerItem::Marked() const
{
  assert(this);
  return m_blMarked;
}

void CFormManagerItem::Mark()
{
  assert(this);
  m_blMarked = true;
}

CForm* CFormManagerItem::Form()
{
  assert(this);
  return m_pForm;
}

bool CFormManagerItem::operator == (const CFormManagerItem& rhs) const {return m_pForm == rhs.m_pForm;}
bool CFormManagerItem::operator != (const CFormManagerItem& rhs) const {return m_pForm != rhs.m_pForm;}
bool CFormManagerItem::operator < (const CFormManagerItem& rhs) const {return m_pForm < rhs.m_pForm;}
bool CFormManagerItem::operator > (const CFormManagerItem& rhs) const {return m_pForm > rhs.m_pForm;}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFormManager::CFormManager(CDisplay* pDisplay)
: m_pDisplay(pDisplay)
{

}

CFormManager::~CFormManager()
{
  for(FormList::iterator iter = m_forms.begin();
      iter != m_forms.end();
      ++iter)
        {
        delete iter->Form();
        }
}

void CFormManager::ShowForm(CForm* pForm)
{
  assert(this);
  assert(pForm);

  CFormManagerItem item(pForm);
  m_forms.push_back(item);

  pForm->Paint(m_pDisplay);
}

int CFormManager::ShowFormModal(CForm* pForm)
{
  assert(this);
  assert(pForm);

  bool blOldModal = m_blExitModal;
  int iOldRet = m_iModalReturn;

  m_blExitModal = false;

  CFormManagerItem item(pForm);
  m_forms.push_back(item);

  pForm->Paint(m_pDisplay);
  
  App().MessageLoop(&m_blExitModal);

  m_forms.pop_back();
   
  if(!m_forms.empty())
    {
    CForm* pForm = m_forms.back().Form();
    pForm->Paint(m_pDisplay);
    }

  m_blExitModal = blOldModal;
  int iRet = m_iModalReturn;
  m_iModalReturn = iOldRet;

  return iRet;
}
  

void CFormManager::MarkCurrent()
{
  assert(this);
  m_forms.back().Mark();
}

void CFormManager::BackToMark()
{
  assert(this);
  assert(!m_forms.empty());

  // Always go back one form whether marked or not
  if(!m_forms.empty())
    {
    delete m_forms.back().Form();
    m_forms.pop_back();
    }

  // now look for the marked form
  while(!m_forms.empty() && !m_forms.back().Marked())
    {
    delete m_forms.back().Form();
    m_forms.pop_back();
    }

  if(!m_forms.empty())
    {
    m_forms.back().Form()->Paint(m_pDisplay);
    }
}

void CFormManager::EndModal(int iRet)
{
  assert(this);
  m_iModalReturn = iRet;
  m_blExitModal = true;
}

CDisplay& CFormManager::Display()
{
  assert(this);
  return *m_pDisplay;
}

void CFormManager::OnCmd0() 
{
  if(!m_forms.empty())
    m_forms.back().Form()->OnCmd0();
}

void CFormManager::OnCmd1()
{
  if(!m_forms.empty())
    m_forms.back().Form()->OnCmd1();
}

void CFormManager::OnCmd2()
{
  if(!m_forms.empty())
    m_forms.back().Form()->OnCmd2();
}

void CFormManager::OnCmd3()
{
  if(!m_forms.empty())
    m_forms.back().Form()->OnCmd3();
}

void CFormManager::OnCmd4()
{
  if(!m_forms.empty())
    m_forms.back().Form()->OnCmd4();
}

void CFormManager::OnCmd5()
{
  if(!m_forms.empty())
    m_forms.back().Form()->OnCmd5();
}

void CFormManager::OnCmd6()
{
  if(!m_forms.empty())
    m_forms.back().Form()->OnCmd6();
}

void CFormManager::OnCmd7()
{
  if(!m_forms.empty())
    m_forms.back().Form()->OnCmd7();
}
