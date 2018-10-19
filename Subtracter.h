// Subtracter.h: interface for the CSubtracter class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SUBTRACTER_H__AC4FDE82_42F2_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_SUBTRACTER_H__AC4FDE82_42F2_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


#include "Widgets.hpp"
#include "Standard.h"

class CSubtracterTemplate;

/**********************************************************************
* Class: CSubtracter
* Primitive widget which subtracts one analogue channel from another
**********************************************************************/
class CSubtracter : public CStandardWidget  
{

  class CSubtracterOutput : public CAnalogueOutput
    {
    public:
    CSubtracterOutput(CStandardWidget* pWidget);
    virtual CValue Value() const;
    };

	CAnalogueInput m_inputs[2];
  CSubtracterOutput m_output;

  friend class CSubtracterTemplate;
  CSubtracter(const CWidgetTemplate* pTemplate, const std::string& strName);

public:
	virtual ~CSubtracter();

  virtual COutput* Output(int idx);
  virtual const COutput& Output(int idx) const;

  virtual CInput* Input(int idx);
  virtual const CInput& Input(int idx) const;
};

/**********************************************************************
* Class: CSubtracterTemplate
* Template class for creating CSubtracter widgets.
**********************************************************************/
class CSubtracterTemplate : public CStandardWidgetTemplate
{
  CAnalogueConnectorDescription m_ainputDesc[2];
  CAnalogueConnectorDescription m_outputDesc;

public:
  CSubtracterTemplate();
  virtual ~CSubtracterTemplate();

  virtual CWidget* Create(const std::string& strName) const;
  virtual const CConnectorDescription& Output(int idx) const;
  virtual int OutputCount() const;
  virtual const CConnectorDescription& Input(int idx) const;
  virtual int InputCount() const;
};


#endif // !defined(AFX_SUBTRACTER_H__AC4FDE82_42F2_11D2_BB29_F5D419D58836__INCLUDED_)
