

#ifndef _WIDGETS_H
#define _WIDGETS_H

#include <string>

class CInput;
class COutput;
class CWidget;
class CValue;
class CType;
class CConnectorDescription;
class CWidgetTemplate;

class CEditContext;
class CTemplateEditContext;
class CTemplateList;

/**********************************************************************
* Class: CWidget
* Abstract base class for any type of mixer.
**********************************************************************/
class CWidget
{
  public:

    // Outputs
    virtual COutput* Output(int idx) = 0;
    virtual const COutput& Output(int idx) const = 0;
    virtual int OutputCount() const = 0;
    
    // Inputs
    virtual CInput* Input(int idx) = 0;
    virtual const CInput& Input(int idx) const = 0;
    virtual int InputCount() const = 0;

    // Info
    virtual const std::string& Name() const = 0;
    virtual const std::string& TypeName() const = 0;

    // Creation
    virtual CWidget* Clone(const std::string& strName) const = 0;
    virtual bool CanDelete() const = 0;

    // Editing
    virtual bool CanEdit() const = 0;
    virtual void Edit(const CEditContext* pContext) = 0;
    virtual void Freeze() = 0; // make not editable

    virtual ~CWidget() {}
};

/**********************************************************************
* Class: CInput
* Abstract base class for an input to a mixer
**********************************************************************/
class CInput
{
  public:
    virtual const std::string& Name() const = 0;
    virtual CType Type() const = 0;
    virtual bool Connect(const COutput* pOutput) = 0;
    virtual void Disconnect() = 0;
    virtual const COutput* Source() const = 0;
    virtual CValue Value() const = 0;
    virtual ~CInput() {}
    
  protected:
    bool PathExists(const COutput* pOutput) const;
};

/**********************************************************************
* Class: COutput
* Abstract base class for an output from a mixer
**********************************************************************/
class COutput
{
  public:
    virtual const std::string& Name() const = 0;
    virtual CType Type() const = 0;
    virtual CValue Value() const = 0;
    virtual const CWidget* Parent() const = 0;
    virtual ~COutput() {}
};

/**********************************************************************
* Class: CConnectorDescription
* Abstract base class to describe a connection to a mixer
**********************************************************************/
class CConnectorDescription
{
  public:
    virtual const std::string& Name() const = 0;
    virtual CType Type() const = 0;
    virtual ~CConnectorDescription() {}
};


/**********************************************************************
* Class: CWidgetTemplate
* Abstract base class to provide a template for creating mixers
**********************************************************************/
class CWidgetTemplate
{
  public:
    virtual const std::string& Name() const = 0;
    virtual CWidget* Create(const std::string& strName) const = 0;
    virtual const CConnectorDescription& Output(int idx) const = 0;
    virtual int OutputCount() const = 0;
    virtual const CConnectorDescription& Input(int idx) const = 0;
    virtual int InputCount() const = 0;
    virtual ~CWidgetTemplate() {}

    virtual bool CanEdit() const = 0;
    virtual void Edit(CTemplateEditContext* pContext, CTemplateList* pTemplates) = 0;
};

#endif

