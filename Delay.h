// Delay.h: interface for the CDelay class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DELAY_H__A3456E41_595E_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_DELAY_H__A3456E41_595E_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Standard.h"

class CDelayTemplate;

/**********************************************************************
* Class: CDelay
* A primitive widget which allows the user to insert an adjustable
* delay on signal transitions of a digital signal
**********************************************************************/
class CDelay : public CStandardWidget
{

  class CDelayOutput : public CDigitalOutput
    {
    public:
    CDelayOutput(CStandardWidget* pWidget);
    virtual CValue Value() const;
    };

	CDigitalInput m_input;
  CDelayOutput m_output;

  bool m_blEditable;
  int  m_nDelay;
  
  // track change of state & delay
  mutable int  m_nTickCount;
  mutable bool m_blPreviousState;
  mutable bool m_blCurrentState;

  friend class CDelayTemplate;
  CDelay(const CWidgetTemplate* pTemplate, const std::string& strName);

public:
	virtual ~CDelay();

  virtual COutput* Output(int idx);
  virtual const COutput& Output(int idx) const;

  virtual CInput* Input(int idx);
  virtual const CInput& Input(int idx) const;

  virtual CWidget* Clone(const std::string& strName) const;

  virtual bool CanEdit() const;
  virtual void Edit(const CEditContext* pContext);
  virtual void Freeze();

  CValue Value() const;
  int& Delay();
};

/**********************************************************************
* Class: CDelayTemplate
* A template class to create delays.
**********************************************************************/
class CDelayTemplate : public CStandardWidgetTemplate
{
  CDigitalConnectorDescription m_inputDesc;
  CDigitalConnectorDescription m_outputDesc;

public:
  CDelayTemplate();
  virtual ~CDelayTemplate();

  virtual CWidget* Create(const std::string& strName) const;
  virtual const CConnectorDescription& Output(int idx) const;
  virtual int OutputCount() const;
  virtual const CConnectorDescription& Input(int idx) const;
  virtual int InputCount() const;
};

#endif // !defined(AFX_DELAY_H__A3456E41_595E_11D2_BB29_F5D419D58836__INCLUDED_)
