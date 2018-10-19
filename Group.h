// Group.h: interface for the CGroup class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GROUP_H__A66D3C01_4753_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_GROUP_H__A66D3C01_4753_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include <vector>
#include <string>
#include "Widgets.hpp"
#include "WidgetList.h"
#include "type.h"

/**********************************************************************
* Class: CConnector
* This connects an input directly to an output.  Connectors are
* found only in CConnectorWidgets.
**********************************************************************/
class CConnector : public CInput, public COutput
{
  const CWidget* m_pParent;     // containing widget
  const COutput* m_pSource;     // source of its data.
  std::string m_strName;        // name of the connection
  CType m_type;                 // connector type (analogue or digital)

  public:
  CConnector(const CWidget* pParent, const std::string& strName, const CType type);
  virtual ~CConnector();

  // CInput & COutput
  virtual const std::string& Name() const;
  virtual CType Type() const;
  virtual CValue Value() const;

  // CInput
  virtual bool Connect(const COutput* pOutput);
  virtual void Disconnect();
  virtual const COutput* Source() const;

  // COutput
  virtual const CWidget* Parent() const;
};

/**********************************************************************
* Class: CConnectorWidget
* Class to contain a number of connectors. A group widget has 2
* connector widgets - one for inputs & one for outputs. 
* Note that from the outside, the connectors' parent widget is the
* parent of this widget.  From the inside (e.g. when editing) the
* connectors' parent is this connector widget.
**********************************************************************/
class CConnectorWidget : public CWidget
{
  std::vector<CConnector*> m_connectors;     
  std::string m_strName;            // "inputs" or "outputs"
  const CWidget* m_pParent;         // containing group widget.
  static std::string m_strTypeName; // "connectors"
  
  public:
  CConnectorWidget(const CWidget* pParent, const std::string& strName);
  virtual ~CConnectorWidget();

  virtual COutput* Output(int idx);
  virtual const COutput& Output(int idx) const;
  virtual int OutputCount() const;
  
  virtual CInput* Input(int idx);
  virtual const CInput& Input(int idx) const;
  virtual int InputCount() const;

  virtual const std::string& Name() const;
  virtual const std::string& TypeName() const;

  virtual CWidget* Clone(const std::string& strName) const;
  virtual bool CanDelete() const;

  virtual bool CanEdit() const;
  virtual void Edit(const CEditContext* pContext);
  virtual void Freeze();

  CConnector*  AddConnector(const std::string& strName, const CType type);
  void DeleteConnector(const std::string& strName);
};


/**********************************************************************
* Class: CGroup
* This is composite - a group of widgets that is itself a widget. 
**********************************************************************/
class CGroup : public CWidget  
{
  CConnectorWidget m_inputs;        // all the input connectors
  CConnectorWidget m_outputs;       // all the output connectors
  CWidgetList m_widgets;  // the widgets in this group
  std::string m_strName;            // the group's name
  std::string m_strTypeName;        // and its type(from template)
  bool m_blEditable;                // true if (potentially) can be edited

public:
  CGroup(const std::string& strName, const std::string& strTypeName);
	virtual ~CGroup();

  virtual COutput* Output(int idx);
  virtual const COutput& Output(int idx) const;
  virtual int OutputCount() const;
  
  virtual CInput* Input(int idx);
  virtual const CInput& Input(int idx) const;
  virtual int InputCount() const;

  virtual const std::string& Name() const;
  virtual const std::string& TypeName() const;

  CWidget* Clone(const std::string& strName) const;
  virtual bool CanDelete() const;

  virtual bool CanEdit() const;
  virtual void Edit(const CEditContext* pContext);
  virtual void Freeze();

  // Group specific implementation for editing
  CWidgetList& Widgets();
  CConnectorWidget& Inputs();
  CConnectorWidget& Outputs();
  CInput* AddInput(const std::string& strName, const CType type);
  COutput* AddOutput(const std::string& strName, const CType type);
  void DeleteInput(const std::string& strName);
  void DeleteOutput(const std::string& strName);

private:
  void ConnectInputs(const CWidget* pOld, CWidget* pNew, CGroup* pNewGroup) const;
};


/**********************************************************************
* Class: CGroupConnectorDescription
* A connector description for use within a group template
**********************************************************************/
class CGroupConnectorDescription : public CConnectorDescription
{
  std::string m_strName;
  CType m_type;
  public:
    CGroupConnectorDescription(const std::string& strName, CType type);
    virtual ~CGroupConnectorDescription();
    virtual const std::string& Name() const;
    virtual CType Type() const;
};

/**********************************************************************
* Class: CGroupTemplate
* This uses a prototype pattern to allow groups to be created and
* used as templates to create other, identical groups.
**********************************************************************/
class CGroupTemplate : public CWidgetTemplate
{
  CGroup m_pattern; // Group widget used as pattern to make new ones
  std::vector<CGroupConnectorDescription*> m_inputDescriptions;
  std::vector<CGroupConnectorDescription*> m_outputDescriptions;

  public:
    CGroupTemplate(const std::string& strTypeName);
    virtual ~CGroupTemplate();

    virtual const std::string& Name() const;
    virtual CWidget* Create(const std::string& strName) const;
    virtual const CConnectorDescription& Output(int idx) const;
    virtual int OutputCount() const;
    virtual const CConnectorDescription& Input(int idx) const;
    virtual int InputCount() const;

    virtual bool CanEdit() const;
    virtual void Edit(CTemplateEditContext* pContext, CTemplateList* pTemplates);

    CWidgetList& Widgets();
    CConnectorWidget& Inputs();
    CConnectorWidget& Outputs();
    CInput* AddInput(const std::string& strName, const CType type);
    COutput* AddOutput(const std::string& strName, const CType type);
    void DeleteInput(const std::string& strName);
    void DeleteOutput(const std::string& strName);


};

#endif // !defined(AFX_GROUP_H__A66D3C01_4753_11D2_BB29_F5D419D58836__INCLUDED_)
