// TemplateList.cpp: implementation of the CTemplateList class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TemplateList.h"
// Widgets
#include "Adder.h"
#include "Multiplexer.h"
#include "Multiplier.h"
#include "Subtracter.h"
#include "AnalogueSetting.h"
#include "DigitalSetting.h"
#include "Negate.h"
#include "And.h"
#include "Or.h"
#include "Not.h"
#include "Threshold.h"
#include "Delay.h"
#include "RateLimiter.h"
#include "LinearPieceWise.h"
#include "Exponential.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTemplateList::CTemplateList()
{
  m_templates.push_back(new CAdderTemplate);
  m_templates.push_back(new CMultiplexerTemplate);
  m_templates.push_back(new CMultiplierTemplate);
  m_templates.push_back(new CSubtracterTemplate);
  m_templates.push_back(new CAnalogueSettingTemplate);
  m_templates.push_back(new CDigitalSettingTemplate);
  m_templates.push_back(new CNegateTemplate);
  m_templates.push_back(new CLinearPieceWiseTemplate);
  m_templates.push_back(new CRateLimiterTemplate);
  m_templates.push_back(new CAndTemplate);
  m_templates.push_back(new COrTemplate);
  m_templates.push_back(new CNotTemplate);
  m_templates.push_back(new CDelayTemplate);
  m_templates.push_back(new CThresholdTemplate);
  m_templates.push_back(new CExponentialTemplate);
}

CTemplateList::~CTemplateList()
{
  for(iterator iter = m_templates.begin(); iter != m_templates.end(); ++iter)
    {
    delete *iter;
    }
}

void CTemplateList::Add(CWidgetTemplate* pTemplate)
{
  assert(this);
  assert(pTemplate);
  m_templates.push_back(pTemplate);
}

bool CTemplateList::Find(const std::string& strName, CWidgetTemplate*& pTemplate)
{
  assert(this);
  for(iterator iter = m_templates.begin(); iter != m_templates.end(); ++iter)
    {
    if( (*iter)->Name() == strName)
      {
      pTemplate = *iter;
      return true;
      }
    }
  return false;
}

bool CTemplateList::Delete(const std::string& strName)
{
  assert(this);
  CWidgetTemplate* pTemplateToDelete = 0;
  if(Find(strName,pTemplateToDelete))
    {
    assert(pTemplateToDelete);

    m_templates.remove(pTemplateToDelete);
    delete pTemplateToDelete;

    return true;
    }
  return false;

}

CTemplateList::iterator CTemplateList::Begin()
{
  assert(this);
  return m_templates.begin();
}

CTemplateList::iterator CTemplateList::End()
{
  assert(this);
  return m_templates.end();
}

CTemplateList::const_iterator CTemplateList::Begin() const
{
  assert(this);
  return m_templates.begin();
}

CTemplateList::const_iterator CTemplateList::End() const
{
  assert(this);
  return m_templates.end();
}
