// DigitalSetting.h: interface for the CDigitalSetting class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DIGITALSETTING_H__0B74A1C3_53D8_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_DIGITALSETTING_H__0B74A1C3_53D8_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Standard.h"
#include "Value.h"

class CDigitalSettingTemplate;

/**********************************************************************
* Class: CDigitalSetting
* A primitive widget class which allows the user to add digital
* settings to a model or group mixer.
**********************************************************************/
class CDigitalSetting : public CStandardWidget  
{

  class CDigitalSettingOutput : public CDigitalOutput
    {
    CValue m_val;
    public:
    CDigitalSettingOutput(CStandardWidget* pWidget);
    virtual CValue Value() const;

    void Value(CValue val);
    };

  CDigitalSettingOutput m_output;
  bool m_blEditable;

  friend class CDigitalSettingTemplate;
  CDigitalSetting(const CWidgetTemplate* pTemplate, const std::string& strName);

public:
	virtual ~CDigitalSetting();

  virtual COutput* Output(int idx);
  virtual const COutput& Output(int idx) const;

  virtual CInput* Input(int idx);
  virtual const CInput& Input(int idx) const;

  virtual CWidget* Clone(const std::string& strName) const;

  virtual bool CanEdit() const;
  virtual void Edit(const CEditContext* pContext);
  virtual void Freeze();

  bool Value() const;
  void Value(bool blVal);
};

/**********************************************************************
* Class: CDigitalSettingTemplate
* A template class for creating digital settings.
**********************************************************************/
class CDigitalSettingTemplate : public CStandardWidgetTemplate
{
  CDigitalConnectorDescription m_outputDesc;

public:
  CDigitalSettingTemplate();
  virtual ~CDigitalSettingTemplate();

  virtual CWidget* Create(const std::string& strName) const;
  virtual const CConnectorDescription& Output(int idx) const;
  virtual int OutputCount() const;
  virtual const CConnectorDescription& Input(int idx) const;
  virtual int InputCount() const;
};


#endif // !defined(AFX_DIGITALSETTING_H__0B74A1C3_53D8_11D2_BB29_F5D419D58836__INCLUDED_)
