// Threshold.h: interface for the CThreshold class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_THRESHOLD_H__2A267A86_5892_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_THRESHOLD_H__2A267A86_5892_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Standard.h"

class CThresholdTemplate;

/**********************************************************************
* Class: CThreshold
* Primitive widget which thresholds one analogue input by another
* giving a digital output.
**********************************************************************/
class CThreshold : public CStandardWidget  
{

  class CThresholdOutput : public CDigitalOutput
    {
    public:
    CThresholdOutput(CStandardWidget* pWidget);
    virtual CValue Value() const;
    };

	CAnalogueInput m_inputs[2];
  CThresholdOutput m_output;

  friend class CThresholdTemplate;
  CThreshold(const CWidgetTemplate* pTemplate, const std::string& strName);

public:
	virtual ~CThreshold();

  virtual COutput* Output(int idx);
  virtual const COutput& Output(int idx) const;

  virtual CInput* Input(int idx);
  virtual const CInput& Input(int idx) const;
};

/**********************************************************************
* Class: CThresholdTemplate
* Template class for creating CThreshold widgets
**********************************************************************/
class CThresholdTemplate : public CStandardWidgetTemplate
{
  CAnalogueConnectorDescription m_ainputDesc[2];
  CDigitalConnectorDescription m_outputDesc;

public:
  CThresholdTemplate();
  virtual ~CThresholdTemplate();

  virtual CWidget* Create(const std::string& strName) const;
  virtual const CConnectorDescription& Output(int idx) const;
  virtual int OutputCount() const;
  virtual const CConnectorDescription& Input(int idx) const;
  virtual int InputCount() const;
};

#endif // !defined(AFX_THRESHOLD_H__2A267A86_5892_11D2_BB29_F5D419D58836__INCLUDED_)
