// And.h: interface for the CAnd class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AND_H__2A267A83_5892_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_AND_H__2A267A83_5892_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Standard.h"

class CAndTemplate;

/**********************************************************************
* Class: CAnd
* Primitive widget class which does a logical and between 2 digital
* inputs.
**********************************************************************/
class CAnd : public CStandardWidget  
{

  class CAndOutput : public CDigitalOutput
    {
    public:
    CAndOutput(CStandardWidget* pWidget);
    virtual CValue Value() const;
    };

	CDigitalInput m_inputs[2];
  CAndOutput m_output;

  friend class CAndTemplate;
  CAnd(const CWidgetTemplate* pTemplate, const std::string& strName);

public:
	virtual ~CAnd();

  virtual COutput* Output(int idx);
  virtual const COutput& Output(int idx) const;

  virtual CInput* Input(int idx);
  virtual const CInput& Input(int idx) const;
};

/**********************************************************************
* Class: CAndTemplate
* Template class to provide And widgets
**********************************************************************/
class CAndTemplate : public CStandardWidgetTemplate
{
  CDigitalConnectorDescription m_ainputDesc[2];
  CDigitalConnectorDescription m_outputDesc;

public:
  CAndTemplate();
  virtual ~CAndTemplate();

  virtual CWidget* Create(const std::string& strName) const;
  virtual const CConnectorDescription& Output(int idx) const;
  virtual int OutputCount() const;
  virtual const CConnectorDescription& Input(int idx) const;
  virtual int InputCount() const;
};

#endif // !defined(AFX_AND_H__2A267A83_5892_11D2_BB29_F5D419D58836__INCLUDED_)
