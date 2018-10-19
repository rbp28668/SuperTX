// AnalogueConverter.h: interface for the CAnalogueConverter class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ANALOGUECONVERTER_H__84EF3BE1_355C_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_ANALOGUECONVERTER_H__84EF3BE1_355C_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


#include "FixedWidget.h"

class CSuperTXDlg;


/**********************************************************************
* Class: CAnalogueConverter
* This class models the Analogue to Digital converter (ADC) which
* digitises the inputs from the analogue channels
**********************************************************************/
class CAnalogueConverter : public CFixedWidget  
{
  class CADCOutput : public COutput
    {
    CAnalogueConverter* m_pADC;   // parent converter
    std::string m_strName;        // name of this channel
    int m_iChannel;               // channel number

    public:
    CADCOutput();
    void Set(CAnalogueConverter* pADC
            ,const std::string& strName
            ,int iChannel);
    virtual const std::string& Name() const;
    virtual const CWidget* Parent() const;
    virtual CType Type() const;
    virtual CValue Value() const;
    };

  enum {OUTPUT_COUNT = 8};

  CSuperTXDlg* m_pDlg;

  std::string m_strName;
  std::string m_strTypeName;

  CADCOutput m_aOutputs[OUTPUT_COUNT];

public:
	CAnalogueConverter();
	virtual ~CAnalogueConverter();

  void Tie(CSuperTXDlg *pDlg);

  CValue ChannelValue(int iChannel);

  virtual COutput* Output(int idx);
  virtual const COutput& Output(int idx) const;
  virtual int OutputCount() const;

  virtual const std::string& Name() const;
  virtual const std::string& TypeName() const;
  
};

#endif // !defined(AFX_ANALOGUECONVERTER_H__84EF3BE1_355C_11D2_BB29_F5D419D58836__INCLUDED_)
