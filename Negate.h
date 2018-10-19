// Negate.h: interface for the CNegate class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NEGATE_H__2A267A81_5892_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_NEGATE_H__2A267A81_5892_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Standard.h"

class CNegateTemplate;

/**********************************************************************
* Class: CNegate
* Primitive widget class for inverting an analogue signal
**********************************************************************/
class CNegate : public CStandardWidget  
{

  class CNegateOutput : public CAnalogueOutput
    {
    public:
    CNegateOutput(CStandardWidget* pWidget);
    virtual CValue Value() const;
    };

	CAnalogueInput m_input;
  CNegateOutput m_output;

  friend class CNegateTemplate;
  CNegate(const CWidgetTemplate* pTemplate, const std::string& strName);

public:
	virtual ~CNegate();

  virtual COutput* Output(int idx);
  virtual const COutput& Output(int idx) const;

  virtual CInput* Input(int idx);
  virtual const CInput& Input(int idx) const;
};

/**********************************************************************
* Class: CNegateTemplate
* Template class for producing CNegate widgets.
**********************************************************************/
class CNegateTemplate : public CStandardWidgetTemplate
{
  CAnalogueConnectorDescription m_inputDesc;
  CAnalogueConnectorDescription m_outputDesc;

public:
  CNegateTemplate();
  virtual ~CNegateTemplate();

  virtual CWidget* Create(const std::string& strName) const;
  virtual const CConnectorDescription& Output(int idx) const;
  virtual int OutputCount() const;
  virtual const CConnectorDescription& Input(int idx) const;
  virtual int InputCount() const;
};

#endif // !defined(AFX_NEGATE_H__2A267A81_5892_11D2_BB29_F5D419D58836__INCLUDED_)
