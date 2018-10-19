// Or.h: interface for the COr class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OR_H__2A267A84_5892_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_OR_H__2A267A84_5892_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Standard.h"


class COrTemplate;

/**********************************************************************
* Class: COr
* Primitive widget class for OR-ing 2 digital signals
**********************************************************************/
class COr : public CStandardWidget  
{

  class COrOutput : public CDigitalOutput
    {
    public:
    COrOutput(CStandardWidget* pWidget);
    virtual CValue Value() const;
    };

	CDigitalInput m_inputs[2];
  COrOutput m_output;

  friend class COrTemplate;
  COr(const CWidgetTemplate* pTemplate, const std::string& strName);

public:
	virtual ~COr();

  virtual COutput* Output(int idx);
  virtual const COutput& Output(int idx) const;

  virtual CInput* Input(int idx);
  virtual const CInput& Input(int idx) const;
};

/**********************************************************************
* Class: COrTemplate
* Template class for creating COr widgets
**********************************************************************/
class COrTemplate : public CStandardWidgetTemplate
{
  CDigitalConnectorDescription m_ainputDesc[2];
  CDigitalConnectorDescription m_outputDesc;

public:
  COrTemplate();
  virtual ~COrTemplate();

  virtual CWidget* Create(const std::string& strName) const;
  virtual const CConnectorDescription& Output(int idx) const;
  virtual int OutputCount() const;
  virtual const CConnectorDescription& Input(int idx) const;
  virtual int InputCount() const;
};

#endif // !defined(AFX_OR_H__2A267A84_5892_11D2_BB29_F5D419D58836__INCLUDED_)
