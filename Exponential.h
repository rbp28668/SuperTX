// Exponential.h: interface for the CExponential class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXPONENTIAL_H__E6C2BC61_6014_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_EXPONENTIAL_H__E6C2BC61_6014_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Standard.h"

class CExponentialTemplate;

/**********************************************************************
* Class: CExponential
* Primitive widget class for exponential response. This primitive 
* has 2 inputs a signal and a control.  As the control varies from
* -1 to +1 the signal response is varied from linear to cubic.
**********************************************************************/
class CExponential : public CStandardWidget  
{

  class CExponentialOutput : public CAnalogueOutput
    {
    public:
    CExponentialOutput(CStandardWidget* pWidget);
    virtual CValue Value() const;
    };

	CAnalogueInput m_inputs[2];
  CExponentialOutput m_output;

  friend class CExponentialTemplate;
  CExponential(const CWidgetTemplate* pTemplate, const std::string& strName);

public:
	virtual ~CExponential();

  virtual COutput* Output(int idx);
  virtual const COutput& Output(int idx) const;

  virtual CInput* Input(int idx);
  virtual const CInput& Input(int idx) const;
};

/**********************************************************************
* Class: CExponentialTemplate
* Template class for CExponential widget
**********************************************************************/
class CExponentialTemplate : public CStandardWidgetTemplate
{
  CAnalogueConnectorDescription m_ainputDesc[2];
  CAnalogueConnectorDescription m_outputDesc;

public:
  CExponentialTemplate();
  virtual ~CExponentialTemplate();

  virtual CWidget* Create(const std::string& strName) const;
  virtual const CConnectorDescription& Output(int idx) const;
  virtual int OutputCount() const;
  virtual const CConnectorDescription& Input(int idx) const;
  virtual int InputCount() const;
};
#endif // !defined(AFX_EXPONENTIAL_H__E6C2BC61_6014_11D2_BB29_F5D419D58836__INCLUDED_)
