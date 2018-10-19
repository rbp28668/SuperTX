// Model.h: interface for the CModel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MODEL_H__219CA363_4F2A_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_MODEL_H__219CA363_4F2A_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "EncoderProxy.h"
#include "WidgetList.h"

class CWidget;
class CAnalogueConverter;
class CSwitches;

/**********************************************************************
* Class: CModel
* class which encapsulates the information for one model.
**********************************************************************/
class CModel  
{
  std::string m_strName;
  CEncoderProxy m_EncoderProxy;
  CWidgetList m_widgets;

public:
	CModel(const std::string& strName, CAnalogueConverter* pADC, CSwitches* pSwitches);
	virtual ~CModel();
  
  const CEncoderProxy* Proxy() const;
  const std::string& Name() const;

  CWidgetList& Widgets();
};

#endif // !defined(AFX_MODEL_H__219CA363_4F2A_11D2_BB29_F5D419D58836__INCLUDED_)
