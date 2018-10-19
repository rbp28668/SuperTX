// RateLimiter.h: interface for the CRateLimiter class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RATELIMITER_H__A3456E42_595E_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_RATELIMITER_H__A3456E42_595E_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Standard.h"
#include "Value.h"

class CRateLimiterTemplate;

/**********************************************************************
* Class: CRateLimiter
* Primitive widget which limits the slew-rate of an analogue 
* signal. 
**********************************************************************/
class CRateLimiter : public CStandardWidget  
{

  class CRateLimiterOutput : public CAnalogueOutput
    {
    public:
    CRateLimiterOutput(CStandardWidget* pWidget);
    virtual CValue Value() const;
    };

	CAnalogueInput m_input;
  CRateLimiterOutput m_output;
  mutable CValue m_valCurrent;
  CValue m_valDelta;
  bool m_blEditable;

  friend class CRateLimiterTemplate;
  CRateLimiter(const CWidgetTemplate* pTemplate, const std::string& strName);

public:
	virtual ~CRateLimiter();

  virtual COutput* Output(int idx);
  virtual const COutput& Output(int idx) const;

  virtual CInput* Input(int idx);
  virtual const CInput& Input(int idx) const;

  virtual CWidget* Clone(const std::string& strName) const;

  virtual bool CanEdit() const;
  virtual void Edit(const CEditContext* pContext);
  virtual void Freeze();

  CValue Value() const;
  CValue Delta() const;
  void Delta(CValue delta);
};

/**********************************************************************
* Class: CRateLimiterTemplate
* Template class for creating CRateLimiter widgets
**********************************************************************/
class CRateLimiterTemplate : public CStandardWidgetTemplate
{
  CAnalogueConnectorDescription m_inputDesc;
  CAnalogueConnectorDescription m_outputDesc;

public:
  CRateLimiterTemplate();
  virtual ~CRateLimiterTemplate();

  virtual CWidget* Create(const std::string& strName) const;
  virtual const CConnectorDescription& Output(int idx) const;
  virtual int OutputCount() const;
  virtual const CConnectorDescription& Input(int idx) const;
  virtual int InputCount() const;
};

#endif // !defined(AFX_RATELIMITER_H__A3456E42_595E_11D2_BB29_F5D419D58836__INCLUDED_)
