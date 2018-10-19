// Group.cpp: implementation of the CGroup class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <algorithm>

#include "Group.h"
#include "Value.h"
#include "EditContext.h"
#include "TemplateEditContext.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


///////////////////////////////////////////////////////////////////////
// CConnector

CConnector::CConnector(const CWidget* pParent
                       , const std::string& strName
                       , const CType type)
: m_pParent(pParent)
, m_strName(strName)
, m_pSource(0)
, m_type(type)
{
  assert(this);
  assert(pParent);
}

CConnector::~CConnector()
{
}


const std::string& CConnector::Name() const
{
  assert(this);
  return m_strName;
}

CType CConnector::Type() const
{
  assert(this);
  return m_type;
}

CValue CConnector::Value() const
{
  assert(this);
  if(m_pSource)
    return m_pSource->Value();
  else
    return CValue(0);
}

bool CConnector::Connect(const COutput* pOutput)
{
  assert(this);
  assert(pOutput);
  if(PathExists(pOutput)) // don't create circular paths
    return false;
  m_pSource = pOutput;
  return true;
}

void CConnector::Disconnect()
{
  assert(this);
  m_pSource = 0;
}

const COutput* CConnector::Source() const
{
  assert(this);
  return m_pSource;
}

const CWidget* CConnector::Parent() const
{
  assert(this);
  return m_pParent;
}

//////////////////////////////////////////////////////////////////////
// CConnectorWidget

std::string CConnectorWidget:: m_strTypeName = "Connector";

#pragma warning(disable : 4355) // 'this' : used in base member initializer list

CConnectorWidget::CConnectorWidget(const CWidget* pParent
                                 , const std::string& strName
                                 )
: m_pParent(pParent)
, m_strName(strName)
{
  assert(this);
  assert(pParent);
}

CConnectorWidget::~CConnectorWidget()
{
  std::vector<CConnector*>::iterator iter = m_connectors.begin();
  while(iter != m_connectors.end())
    {
    delete *iter;
    ++iter;
    }
}

COutput* CConnectorWidget::Output(int idx)
{
  assert(this);
  assert(idx >= 0 && idx < OutputCount());
  return static_cast<COutput*>(m_connectors[idx]);
}

const COutput& CConnectorWidget::Output(int idx) const
{
  assert(this);
  assert(idx >= 0 && idx < OutputCount());
  return static_cast<const COutput&>(*m_connectors[idx]);
}

int CConnectorWidget::OutputCount() const
{
  assert(this);
  return m_connectors.size();
}

CInput* CConnectorWidget::Input(int idx)
{
  assert(this);
  assert(idx >= 0 && idx < InputCount());
  return static_cast<CInput*>(m_connectors[idx]);
}

const CInput& CConnectorWidget::Input(int idx) const
{
  assert(this);
  assert(idx >= 0 && idx < InputCount());
  return static_cast<const CInput&>(*m_connectors[idx]);
}

int CConnectorWidget::InputCount() const
{
  assert(this);
  return m_connectors.size();
}


const std::string& CConnectorWidget::Name() const
{
  assert(this);
  return m_strName;
}

const std::string& CConnectorWidget::TypeName() const
{
  assert(this);
  return m_strTypeName;
}

CWidget* CConnectorWidget::Clone(const std::string& strName) const
{
  assert(this);
  assert(false);  // should never need to clone as integral part of CGroup
  return 0;
}

bool CConnectorWidget::CanDelete() const
{
  assert(this);
  return false;  // connector widgets are always members of a group and
                  // should never be deleted.
}

bool CConnectorWidget::CanEdit() const
{
  assert(this);
  return false;
}

void CConnectorWidget::Edit(const CEditContext* /*pContext*/)
{
  assert(this);
  assert(false);
}

void CConnectorWidget::Freeze()
{
  assert(this);
}

CConnector* CConnectorWidget::AddConnector(const std::string& strName, CType type)
{
  CConnector* pConnector = new CConnector(this, strName, type);
  m_connectors.push_back(pConnector);
  return pConnector;
}

void CConnectorWidget::DeleteConnector(const std::string& strName)
{
  for(std::vector<CConnector*>::iterator iter = m_connectors.begin();
      iter != m_connectors.end();
      ++iter)
    {
    if((*iter)->Name() == strName)
      {
      CConnector* pCon = *iter;
      m_connectors.erase(iter);
      delete pCon;
      }
    }
}

//////////////////////////////////////////////////////////////////////
// CGroup

CGroup::CGroup(const std::string& strName, const std::string& strTypeName)
: m_strName(strName)
, m_strTypeName(strTypeName)
, m_inputs(this, "Inputs")
, m_outputs(this, "Outputs")
, m_blEditable(true)
{
  m_widgets.Add(&m_inputs);
  m_widgets.Add(&m_outputs);
}

CGroup::~CGroup()
{
}

COutput* CGroup::Output(int idx)
{
  assert(this);
  assert(idx >= 0 && idx < OutputCount());
  return m_outputs.Output(idx);
}

const COutput& CGroup::Output(int idx) const
{
  assert(this);
  assert(idx >= 0 && idx < OutputCount());
  return m_outputs.Output(idx);
}

int CGroup::OutputCount() const
{
  assert(this);
  return m_outputs.OutputCount();
}

CInput* CGroup::Input(int idx)
{
  assert(this);
  assert(idx >= 0 && idx < InputCount());
  return m_inputs.Input(idx);
}

const CInput& CGroup::Input(int idx) const
{
  assert(this);
  assert(idx >= 0 && idx < InputCount());
  return m_inputs.Input(idx);
}

int CGroup::InputCount() const
{
  assert(this);
  return m_inputs.InputCount();
}

const std::string& CGroup::Name() const
{
  assert(this);
  return m_strName;
}

const std::string& CGroup::TypeName() const
{
  assert(this);
  return m_strTypeName;
}

CWidget* CGroup::Clone(const std::string& strName) const
{
  assert(this);
  
  CGroup* pNewGroup = new CGroup(strName,TypeName());
  // pNewGroup is now an empty group with no inputs or outputs
  // defined.

  // Add all the widgets to the new group - new widgets inherit
  // the template's name. Don't copy any fixed widgets - they
  // should be set up by the constructor
  CWidgetList::const_iterator iter =  m_widgets.Begin();
  while(iter != m_widgets.End())
    {
    CWidget* pOld = *iter;
    if(pOld->CanDelete())
      pNewGroup->m_widgets.Add(pOld->Clone(pOld->Name()));
    ++iter;
    }

  // And set up the input & output connectors
  int nInputs = m_inputs.InputCount();
  int i;
  for(i=0; i<nInputs; ++i)
    pNewGroup->m_inputs.AddConnector(m_inputs.Input(i).Name(), m_inputs.Input(i).Type());

  int nOutputs = m_outputs.OutputCount();
  for(i=0; i<nOutputs; ++i)
    pNewGroup->m_outputs.AddConnector(m_outputs.Output(i).Name(), m_outputs.Output(i).Type());

  // Now we need to set up the connections between the different parts

  // First set up the connections of all the widgets - note that 
  // the 2 groups should have their widgets in the same order
  CWidgetList::iterator iterNew = pNewGroup->m_widgets.Begin();

  for(iter = m_widgets.Begin(); iter != m_widgets.End(); ++iter, ++iterNew)
    {
    const CWidget* pOld = *iter;    // this is the original
    CWidget*       pNew = *iterNew; // and this is its copy
    ConnectInputs(pOld, pNew, pNewGroup);
    }

  // if this group isn't editable, neither should the new one be
  pNewGroup->m_blEditable = m_blEditable;

  return pNewGroup;
}

bool CGroup::CanDelete() const
{
  assert(this);
  return true;
}

bool CGroup::CanEdit() const
{
  assert(this);
  bool blEditable = false;
  if(m_blEditable)
    {
    CWidgetList::const_iterator iter;
    for(iter = m_widgets.Begin(); iter != m_widgets.End(); ++iter)
      {
      if((*iter)->CanEdit())
        {
        blEditable = true;
        break;
        }
      }
    }
  return blEditable;
}

void CGroup::Edit(const CEditContext* pContext)
{
  assert(this);
  assert(pContext);
  assert(CanEdit());
  pContext->EditCGroup(this);
}

void CGroup::Freeze()
{
  assert(this);
  m_blEditable = false;
}

void CGroup::ConnectInputs(const CWidget* pOld, CWidget* pNew, CGroup* pNewGroup) const
{
  assert(pOld->Name() == pNew->Name()); // make sure order matches
  assert(pNew->InputCount() == pOld->InputCount());
  assert(pNew->OutputCount() == pOld->OutputCount());

  // For each input
  for(int iInput=0; iInput < pOld->InputCount(); ++iInput)
    {
    // Get the old source output & its parent widget.
    const COutput* poldSource = pOld->Input(iInput).Source();
    if(poldSource) // not all inputs have to be connected
      {
      const CWidget* poldSourceParent = poldSource->Parent();

      // Find the widget in the clone with the same name as the source widget
      CWidget* pParent = 0;
      pNewGroup->m_widgets.Find(poldSourceParent->Name(), pParent);
      assert(pParent);

      // now find the output (by name) to connect to.
      int nOutputs = pParent->OutputCount();
      const COutput* pOutput = 0;
      for(int i=0; i<nOutputs; ++i)
        {
        if(pParent->Output(i)->Name() == poldSource->Name())
          {
          pOutput = pParent->Output(i);
          break;
          }
        }
      assert(pOutput);

      pNew->Input(iInput)->Connect(pOutput);
      }
    }
}

CWidgetList& CGroup::Widgets()
{
  assert(this);
  return m_widgets;
}

CConnectorWidget& CGroup::Inputs()
{
  assert(this);
  return m_inputs;
}


CConnectorWidget& CGroup::Outputs()
{
  assert(this);
  return m_outputs;
}


CInput* CGroup::AddInput(const std::string& strName, const CType type)
{
  assert(this);
  return m_inputs.AddConnector(strName,type);
}

COutput* CGroup::AddOutput(const std::string& strName, const CType type)
{
  assert(this);
  return m_outputs.AddConnector(strName,type);
}

void CGroup::DeleteInput(const std::string& strName)
{
  assert(this);
  m_inputs.DeleteConnector(strName);
}

void CGroup::DeleteOutput(const std::string& strName)
{
  assert(this);

  // Find the output
  COutput* pOutput = 0;
  int iOutput = 0;
  int nOutputs = m_outputs.OutputCount();
  for(int i=0; i<nOutputs; ++i)
    {
    if(m_outputs.Output(i)->Name() == strName)
      {
      pOutput = m_outputs.Output(i);
      iOutput = i;
      break;
      }
    }

  assert(pOutput);

  // Disconnect any inputs in the group which are
  // connected to this output
  for(CWidgetList::iterator iter = m_widgets.Begin();
      iter != m_widgets.End();
      ++iter)
    {
    CWidget* pWidget = *iter;
    int nInputs = pWidget->InputCount();
    for(int i=0; i<nInputs; ++i)
      if(pWidget->Input(i)->Source() == pOutput)
        pWidget->Input(i)->Disconnect();
    }

  m_outputs.DeleteConnector(strName);
}


///////////////////////////////////////////////////////////////////////
// CGroupConnectorDescription
CGroupConnectorDescription::CGroupConnectorDescription(const std::string& strName, CType type)
: m_strName(strName)
, m_type(type)
{
}

CGroupConnectorDescription::~CGroupConnectorDescription()
{
}

const std::string& CGroupConnectorDescription::Name() const
{
  assert(this);
  return m_strName;
}

CType CGroupConnectorDescription::Type() const
{
  assert(this);
  return m_type;
}


///////////////////////////////////////////////////////////////////////
// CGroupTemplate
CGroupTemplate::CGroupTemplate(const std::string& strTypeName)
: m_pattern("Template",strTypeName)
{
  assert(this);
}

CGroupTemplate::~CGroupTemplate()
{
  assert(this);
}

const std::string& CGroupTemplate::Name() const
{
  assert(this);
  return m_pattern.TypeName();
}

CWidget* CGroupTemplate::Create(const std::string& strName) const
{
  assert(this);
  return m_pattern.Clone(strName);
}

const CConnectorDescription& CGroupTemplate::Output(int idx) const
{
  assert(this);
  assert(idx >= 0 && idx < OutputCount());
  assert(m_outputDescriptions.size() == m_pattern.OutputCount());
  return *m_outputDescriptions[idx];
}

int CGroupTemplate::OutputCount() const
{
  assert(this);
  assert(m_inputDescriptions.size() == m_pattern.InputCount());
  return m_pattern.OutputCount();
}

const CConnectorDescription& CGroupTemplate::Input(int idx) const
{
  assert(this);
  assert(idx >= 0 && idx < InputCount());
  assert(m_inputDescriptions.size() == m_pattern.InputCount());
  return *m_inputDescriptions[idx];
}

int CGroupTemplate::InputCount() const
{
  assert(this);
  assert(m_inputDescriptions.size() == m_pattern.InputCount());
  return m_pattern.InputCount();
}

bool CGroupTemplate::CanEdit() const
{
  assert(this);
  return(true); // all group templates can be edited
}

void CGroupTemplate::Edit(CTemplateEditContext* pContext, CTemplateList* pTemplates)
{
  assert(this);
  assert(pContext);
  pContext->EditGroupTemplate(this, pTemplates);

}

CWidgetList& CGroupTemplate::Widgets()
{
  assert(this);
  return m_pattern.Widgets();
}

CConnectorWidget& CGroupTemplate::Inputs()
{
  assert(this);
  return m_pattern.Inputs();
}

CConnectorWidget& CGroupTemplate::Outputs()
{
  assert(this);
  return m_pattern.Outputs();
}

CInput* CGroupTemplate::AddInput(const std::string& strName, const CType type)
{
  assert(this);
  return m_pattern.AddInput(strName,type);
}

COutput* CGroupTemplate::AddOutput(const std::string& strName, const CType type)
{
  assert(this);
  return m_pattern.AddOutput(strName,type);
}

void CGroupTemplate::DeleteInput(const std::string& strName)
{
  assert(this);
  m_pattern.DeleteInput(strName);
}

void CGroupTemplate::DeleteOutput(const std::string& strName)
{
  assert(this);
  m_pattern.DeleteOutput(strName);
}


