// Switches.h: interface for the CSwitches class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SWITCHES_H__69E5B341_437D_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_SWITCHES_H__69E5B341_437D_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "FixedWidget.h"

class CSuperTXDlg;

/**********************************************************************
* Class: CSwitches
* This class models the digital input from the transmitter's switches
**********************************************************************/
class CSwitches : public CFixedWidget  
{
  class CSwitchOutput : public COutput
    {
    CSwitches* m_pSwitches;       // parent converter
    std::string m_strName;        // name of this channel
    int m_iChannel;               // channel number

    public:
    CSwitchOutput();
    void Set(CSwitches* pSwitches
            ,const std::string& strName
            ,int iChannel);
    virtual const std::string& Name() const;
    virtual const CWidget* Parent() const;
    virtual CType Type() const;
    virtual CValue Value() const;
    };

  enum {OUTPUT_COUNT = 6};

  CSuperTXDlg* m_pDlg;

  std::string m_strName;
  std::string m_strTypeName;

  CSwitchOutput m_aOutputs[OUTPUT_COUNT];

public:
	CSwitches();
	virtual ~CSwitches();
  void Tie(CSuperTXDlg *pDlg);

  CValue ChannelValue(int iChannel);

  virtual COutput* Output(int idx);
  virtual const COutput& Output(int idx) const;
  virtual int OutputCount() const;

  virtual const std::string& Name() const;
  virtual const std::string& TypeName() const;

};

#endif // !defined(AFX_SWITCHES_H__69E5B341_437D_11D2_BB29_F5D419D58836__INCLUDED_)
