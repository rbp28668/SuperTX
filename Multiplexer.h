// Multiplexer.h: interface for the CMultiplexer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MULTIPLEXER_H__B89E58E1_43C1_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_MULTIPLEXER_H__B89E58E1_43C1_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Widgets.hpp"
#include "Standard.h"

class CMultiplexerTemplate;

/**********************************************************************
* Class: CMultiplexer
* Primitive widget class for switching between 2 analogue channels
**********************************************************************/
class CMultiplexer : public CStandardWidget  
{

  class CMultiplexerOutput : public CAnalogueOutput
    {
    public:
    CMultiplexerOutput(CStandardWidget* pWidget);
    virtual CValue Value() const;
    };

	CAnalogueInput m_inputs[2];
  CDigitalInput m_switchInput;
  CMultiplexerOutput m_output;

  friend class CMultiplexerTemplate;
  CMultiplexer(const CWidgetTemplate* pTemplate, const std::string& strName);

public:
	virtual ~CMultiplexer();

  virtual COutput* Output(int idx);
  virtual const COutput& Output(int idx) const;

  virtual CInput* Input(int idx);
  virtual const CInput& Input(int idx) const;
};

/**********************************************************************
* Class: CMultiplexerTemplate
* Template class for producing CMultiplexers.
**********************************************************************/
class CMultiplexerTemplate : public CStandardWidgetTemplate
{
  CAnalogueConnectorDescription m_ainputDesc[2];
  CDigitalConnectorDescription m_switchedInputDesc;
  CAnalogueConnectorDescription m_outputDesc;

public:
  CMultiplexerTemplate();
  virtual ~CMultiplexerTemplate();

  virtual CWidget* Create(const std::string& strName) const;
  virtual const CConnectorDescription& Output(int idx) const;
  virtual int OutputCount() const;
  virtual const CConnectorDescription& Input(int idx) const;
  virtual int InputCount() const;
};

#endif // !defined(AFX_MULTIPLEXER_H__B89E58E1_43C1_11D2_BB29_F5D419D58836__INCLUDED_)
