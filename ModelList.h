// ModelList.h: interface for the CModelList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MODELLIST_H__219CA362_4F2A_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_MODELLIST_H__219CA362_4F2A_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include <list>
#include "Model.h"

class CAnalogueConverter;
class CSwitches;

/**********************************************************************
* Class: CModelList
* Collection class which provides a list of models
**********************************************************************/
class CModelList  
{
  CAnalogueConverter* m_pADC;
  CSwitches* m_pSwitches;
  std::list<CModel*> m_models;
  
public:

  typedef std::list<CModel*>::iterator iterator;
  typedef std::list<CModel*>::const_iterator const_iterator;

	CModelList(CAnalogueConverter* pADC, CSwitches* pSwitches);
	virtual ~CModelList();

  CModel* NewModel(const std::string& strName);
  bool Find(const std::string& strName, CModel*& pModel);
  bool Delete(const std::string& strName);

  iterator Begin();
  const const_iterator Begin() const;
  const_iterator End() const;


};

#endif // !defined(AFX_MODELLIST_H__219CA362_4F2A_11D2_BB29_F5D419D58836__INCLUDED_)
