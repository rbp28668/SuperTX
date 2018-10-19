// Adder.h: interface for the CAdder class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADDER_H__AC4FDE81_42F2_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_ADDER_H__AC4FDE81_42F2_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


#include "Widgets.hpp"
#include "Standard.h"

class CAdderTemplate;

/**********************************************************************
* Class: CAdder
* A widget class which adds 2 channels together
**********************************************************************/
class CAdder : public CStandardWidget  
{

  class CAdderOutput : public CAnalogueOutput
    {
    public:
    CAdderOutput(CStandardWidget* pWidget);
    virtual CValue Value() const;
    };

	CAnalogueInput m_inputs[2];
  CAdderOutput m_output;

  friend class CAdderTemplate;
  CAdder(const CWidgetTemplate* pTemplate, const std::string& strName);

public:
	virtual ~CAdder();

  virtual COutput* Output(int idx);
  virtual const COutput& Output(int idx) const;

  virtual CInput* Input(int idx);
  virtual const CInput& Input(int idx) const;
};

/**********************************************************************
* Class: CAdderTemplate
* A widget template class which produces adders.
**********************************************************************/
class CAdderTemplate : public CStandardWidgetTemplate
{
  CAnalogueConnectorDescription m_ainputDesc[2];
  CAnalogueConnectorDescription m_outputDesc;

public:
  CAdderTemplate();
  virtual ~CAdderTemplate();

  virtual CWidget* Create(const std::string& strName) const;
  virtual const CConnectorDescription& Output(int idx) const;
  virtual int OutputCount() const;
  virtual const CConnectorDescription& Input(int idx) const;
  virtual int InputCount() const;
};


#endif // !defined(AFX_ADDER_H__AC4FDE81_42F2_11D2_BB29_F5D419D58836__INCLUDED_)
