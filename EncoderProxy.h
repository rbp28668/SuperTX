// EncoderProxy.h: interface for the CEncoderProxy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ENCODERPROXY_H__219CA364_4F2A_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_ENCODERPROXY_H__219CA364_4F2A_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "FixedWidget.h"


/**********************************************************************
* Class: CEncoderProxy
* This class acts as a proxy for the encoder proper. This allows the
* systems to have many proxies (one per model) but only one proper 
* encoder.  A model is activated by connecting that model's 
* encoder proxy to the encoder
**********************************************************************/
class CEncoderProxy : public CFixedWidget  
{
  class CEncoderInput : public CInput
  {
    const CEncoderProxy* m_pProxy;
    const COutput* m_pOutput;
    std::string m_strName;

      // Note - constructor & init function are private -
      // can only be used by (friend) CEncoder
      CEncoderInput();
      void Set(CEncoderProxy* pProxy, const std::string& strName);
      friend class CEncoderProxy;

    public:

    virtual const std::string& Name() const;
    virtual CType Type() const;
    virtual bool Connect(const COutput* pOutput);
    virtual void Disconnect();
    virtual const COutput* Source() const;
    virtual CValue Value() const;
  };


enum {CHANNELS = 8};

  std::string m_strName;
  std::string m_strTypeName;

  CEncoderInput m_aInputs[CHANNELS];

public:
	CEncoderProxy();
	virtual ~CEncoderProxy();

  // Widget
  virtual CInput* Input(int idx);
  virtual const CInput& Input(int idx) const;
  virtual int InputCount() const;

  virtual const std::string& Name() const;
  virtual const std::string& TypeName() const;

  CValue Channel(int idx) const;
};

#endif // !defined(AFX_ENCODERPROXY_H__219CA364_4F2A_11D2_BB29_F5D419D58836__INCLUDED_)
