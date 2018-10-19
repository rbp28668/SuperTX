// ModelList.cpp: implementation of the CModelList class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ModelList.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CModelList::CModelList(CAnalogueConverter* pADC, CSwitches* pSwitches)
: m_pADC(pADC)
, m_pSwitches(pSwitches)
{

}

CModelList::~CModelList()
{
  for(iterator iter = m_models.begin(); iter != m_models.end(); ++iter)
    {
    delete *iter;
    }
}

CModel* CModelList::NewModel(const std::string& strName)
{
  CModel* pModel = new CModel(strName, m_pADC, m_pSwitches);
  m_models.push_back(pModel);
  return pModel;
}

bool CModelList::Find(const std::string& strName, CModel*& pModel)
{
  assert(this);
  for(iterator iter = m_models.begin(); iter != m_models.end(); ++iter)
    {
    if( (*iter)->Name() == strName)
      {
      pModel = *iter;
      return true;
      }
    }
  return false;
}

bool CModelList::Delete(const std::string& strName)
{
  assert(this);
  CModel* pModelToDelete = 0;
  if(Find(strName,pModelToDelete))
    {
    assert(pModelToDelete);

    m_models.remove(pModelToDelete);
    delete pModelToDelete;

    return true;
    }
  return false;
}

CModelList::iterator CModelList::Begin()
{
  assert(this);
  return m_models.begin();
}

const CModelList::const_iterator CModelList::Begin() const
{
  assert(this);
  return m_models.begin();
}

CModelList::const_iterator CModelList::End() const
{
  assert(this);
  return m_models.end();
}

