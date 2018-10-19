// Not.h: interface for the CNot class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NOT_H__2A267A82_5892_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_NOT_H__2A267A82_5892_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Standard.h"

class CNotTemplate;

/**********************************************************************
* Class: CNot
* Primitive widget class for inverting a digital signal
**********************************************************************/
class CNot : public CStandardWidget  
{

  class CNotOutput : public CDigitalOutput
    {
    public:
    CNotOutput(CStandardWidget* pWidget);
    virtual CValue Value() const;
    };

	CDigitalInput m_input;
  CNotOutput m_output;

  friend class CNotTemplate;
  CNot(const CWidgetTemplate* pTemplate, const std::string& strName);

public:
	virtual ~CNot();

  virtual COutput* Output(int idx);
  virtual const COutput& Output(int idx) const;

  virtual CInput* Input(int idx);
  virtual const CInput& Input(int idx) const;
};

/**********************************************************************
* Class: CNotTemplate
* Template class for creating CNot widgets
**********************************************************************/
class CNotTemplate : public CStandardWidgetTemplate
{
  CDigitalConnectorDescription m_inputDesc;
  CDigitalConnectorDescription m_outputDesc;

public:
  CNotTemplate();
  virtual ~CNotTemplate();

  virtual CWidget* Create(const std::string& strName) const;
  virtual const CConnectorDescription& Output(int idx) const;
  virtual int OutputCount() const;
  virtual const CConnectorDescription& Input(int idx) const;
  virtual int InputCount() const;
};

#endif // !defined(AFX_NOT_H__2A267A82_5892_11D2_BB29_F5D419D58836__INCLUDED_)
