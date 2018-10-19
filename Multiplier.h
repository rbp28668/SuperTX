// Multiplier.h: interface for the CMultiplier class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MULTIPLIER_H__F6E3EEE1_3DDF_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_MULTIPLIER_H__F6E3EEE1_3DDF_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Widgets.hpp"
#include "Standard.h"

class CMultiplierTemplate;

/**********************************************************************
* Class: CMultiplier
* Primitive widget class for multiplying 2 analogue signals
**********************************************************************/
class CMultiplier : public CStandardWidget  
{

  class CMultiplierOutput : public CAnalogueOutput
    {
    public:
    CMultiplierOutput(CStandardWidget* pWidget);
    virtual CValue Value() const;
    };

	CAnalogueInput m_inputs[2];
  CMultiplierOutput m_output;

  friend class CMultiplierTemplate;
  CMultiplier(const CWidgetTemplate* pTemplate, const std::string& strName);

public:
	virtual ~CMultiplier();

  virtual COutput* Output(int idx);
  virtual const COutput& Output(int idx) const;

  virtual CInput* Input(int idx);
  virtual const CInput& Input(int idx) const;
};

/**********************************************************************
* Class: CMultiplierTemplate
* Template class for producing CMultiplier widgets
**********************************************************************/
class CMultiplierTemplate : public CStandardWidgetTemplate
{
  CAnalogueConnectorDescription m_ainputDesc[2];
  CAnalogueConnectorDescription m_outputDesc;

public:
  CMultiplierTemplate();
  virtual ~CMultiplierTemplate();

  virtual CWidget* Create(const std::string& strName) const;
  virtual const CConnectorDescription& Output(int idx) const;
  virtual int OutputCount() const;
  virtual const CConnectorDescription& Input(int idx) const;
  virtual int InputCount() const;
};

#endif // !defined(AFX_MULTIPLIER_H__F6E3EEE1_3DDF_11D2_BB29_F5D419D58836__INCLUDED_)
