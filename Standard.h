// StandardInput.h: interface for the CStandardInput class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STANDARDINPUT_H__F6E3EEE2_3DDF_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_STANDARDINPUT_H__F6E3EEE2_3DDF_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Widgets.hpp"

/**********************************************************************
* Class: CStandardWidget
* This abstract base class forms a base for all the "standard" widgets
* which can have multiple instances in a model or group.  
* CStandardWidget provides default behaviour for the commonest set
* of primitive widgets - by default
* standard widgets are not editable, are deletable & get their 
* input/output names from the template.
**********************************************************************/
class CStandardWidget : public CWidget
{
  std::string m_strName;
  const CWidgetTemplate* m_pTemplate;
  
  public:
  CStandardWidget(const CWidgetTemplate* pTemplate, const std::string& strName);
  virtual ~CStandardWidget();

  const CConnectorDescription& GetInputDesc(const CInput* pInput) const;
  const CConnectorDescription& GetOutputDesc(const COutput* pOutput) const;

  virtual int OutputCount() const;
  virtual int InputCount() const; 
  virtual const std::string& Name() const;
  virtual const std::string& TypeName() const;
  virtual CWidget* Clone(const std::string& strName) const;
  virtual bool CanDelete() const;
  virtual bool CanEdit() const;
  virtual void Edit(const CEditContext* pContext);
  virtual void Freeze();
};


/**********************************************************************
* Class: CStandardInput
* This provides a standard implementation of an input for a 
* standard widget
**********************************************************************/
class CStandardInput : public CInput  
{
  const CStandardWidget* m_pWidget;     // which this belongs to.
  const COutput* m_pOutput;             // the input this is connected to
  public:

  CStandardInput();
	virtual ~CStandardInput();

  void Parent(const CStandardWidget* pWidget);

  // CWidgetInput:
  virtual const std::string& Name() const;
  virtual bool Connect(const COutput* pOutput);
  virtual void Disconnect();
  virtual const COutput* Source() const;
  virtual CValue Value() const;
};

/**********************************************************************
* Class: CAnalogueInput
* An analogue input for a standard widget
**********************************************************************/
class CAnalogueInput : public CStandardInput  
{
  public:
	CAnalogueInput();
	virtual ~CAnalogueInput();

  virtual CType Type() const;
};

/**********************************************************************
* Class: CDigitalInput
* A digital input for a standard widget
**********************************************************************/
class CDigitalInput : public CStandardInput  
{
  public:
	CDigitalInput();
	virtual ~CDigitalInput();

  virtual CType Type() const;
};

/**********************************************************************
* Class: CStandardOutput
* An abstract base class for an output of a standard widget. Normally
* not used directly but provides a common base for CAnalogueOutput
* and CDigitalOutput. 
**********************************************************************/
class CStandardOutput : public COutput
  {
  const CStandardWidget* m_pWidget;     // which this belongs to.

  public:
  CStandardOutput(const CStandardWidget* pWidget);
  virtual const std::string& Name() const;
  const CWidget* Parent() const;
  void Parent(const CStandardWidget* pWidget);
  };

/**********************************************************************
* Class: CDigitalOutput
* A digital output for a standard widget
**********************************************************************/
class CDigitalOutput : public CStandardOutput
{
  public:
  CDigitalOutput(const CStandardWidget* pWidget);
  virtual CType Type() const;
};

/**********************************************************************
* Class: CAnalogueOutput
* An analogue output for a standard widget
**********************************************************************/
class CAnalogueOutput : public CStandardOutput
{
  public:
  CAnalogueOutput(const CStandardWidget* pWidget);
  virtual CType Type() const;
};

/**********************************************************************
* Class: CStandardConnectorDescription
* Abstract base class for a connector description for a standard
* widget template.  Not normally used directly but forms the base
* for CAnalogueConnectorDescription and CDigitalConnectorDescription.
**********************************************************************/
class CStandardConnectorDescription : public CConnectorDescription
{
  std::string m_strName;

  public:
    CStandardConnectorDescription();
    CStandardConnectorDescription(const std::string& strName);
    virtual ~CStandardConnectorDescription();

    void Name(const std::string& strName);

    virtual const std::string& Name() const;
};

/**********************************************************************
* Class: CAnalogueConnectorDescription
* A connector description for a standard widget template's analogue
* input
**********************************************************************/
class CAnalogueConnectorDescription : public CStandardConnectorDescription
{
  public:
  CAnalogueConnectorDescription();
  CAnalogueConnectorDescription(const std::string& strName);
  virtual ~CAnalogueConnectorDescription();

  virtual CType Type() const;
};

/**********************************************************************
* Class: CDigitalConnectorDescription
* A connector description for a standard widget template's digital
* input
**********************************************************************/
class CDigitalConnectorDescription : public CStandardConnectorDescription
{
  public:
  CDigitalConnectorDescription();
  CDigitalConnectorDescription(const std::string& strName);
  virtual ~CDigitalConnectorDescription();

  virtual CType Type() const;
};

/**********************************************************************
* Class: CStandardWidgetTemplate
* Base class to provide an implementation for a normal widget 
* template.
**********************************************************************/
class CStandardWidgetTemplate : public CWidgetTemplate
{
  std::string m_strName;
  public:
    CStandardWidgetTemplate(const std::string& strName);
    virtual const std::string& Name() const;
    virtual bool CanEdit() const;
    virtual void Edit(CTemplateEditContext* pContext, CTemplateList* pTemplates);
};


#endif // !defined(AFX_STANDARDINPUT_H__F6E3EEE2_3DDF_11D2_BB29_F5D419D58836__INCLUDED_)
