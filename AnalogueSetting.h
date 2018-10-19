// AnalogueSetting.h: interface for the CAnalogueSetting class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ANALOGUESETTING_H__0B74A1C2_53D8_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_ANALOGUESETTING_H__0B74A1C2_53D8_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Standard.h"
#include "Value.h"

class CAnalogueSettingTemplate;

/**********************************************************************
* Class: CAnalogueSetting
* Primitive widget class which provides an analogue setting i.e. 
* a widget which allows the user to add analogue set points
**********************************************************************/
class CAnalogueSetting : public CStandardWidget  
{

  class CAnalogueSettingOutput : public CAnalogueOutput
    {
    CValue m_val;
    public:
    CAnalogueSettingOutput(CStandardWidget* pWidget);
    virtual CValue Value() const;

    CValue& EditVal();
    };

  CAnalogueSettingOutput m_output;
  bool m_blEditable;

  friend class CAnalogueSettingTemplate;
  CAnalogueSetting(const CWidgetTemplate* pTemplate, const std::string& strName);

public:
	virtual ~CAnalogueSetting();

  virtual COutput* Output(int idx);
  virtual const COutput& Output(int idx) const;

  virtual CInput* Input(int idx);
  virtual const CInput& Input(int idx) const;

  virtual CWidget* Clone(const std::string& strName) const;

  virtual bool CanEdit() const;
  virtual void Edit(const CEditContext* pContext);
  virtual void Freeze();

  CValue& Value();
};

/**********************************************************************
* Class: CAnalogueSettingTemplate
* Template class for creating analogue settings
**********************************************************************/
class CAnalogueSettingTemplate : public CStandardWidgetTemplate
{
  CAnalogueConnectorDescription m_outputDesc;

public:
  CAnalogueSettingTemplate();
  virtual ~CAnalogueSettingTemplate();

  virtual CWidget* Create(const std::string& strName) const;
  virtual const CConnectorDescription& Output(int idx) const;
  virtual int OutputCount() const;
  virtual const CConnectorDescription& Input(int idx) const;
  virtual int InputCount() const;
};

#endif // !defined(AFX_ANALOGUESETTING_H__0B74A1C2_53D8_11D2_BB29_F5D419D58836__INCLUDED_)
