// Form.h: interface for the CForm class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FORM_H__2ABA5AE2_646B_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_FORM_H__2ABA5AE2_646B_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include <string>
class CDisplay;
class CFormManager;
struct BitmapT;
struct FontT;

/**********************************************************************
* Class: CForm
* Base class for all the forms displayed on the LCD
**********************************************************************/
class CForm  
{
public:
  enum {BUTTONS = 8};

	CForm(CFormManager* pManager);
	virtual ~CForm();

  virtual void OnCmd0() {}
  virtual void OnCmd1() {}
  virtual void OnCmd2() {}
  virtual void OnCmd3() {}
  virtual void OnCmd4() {}
  virtual void OnCmd5() {}
  virtual void OnCmd6() {}
  virtual void OnCmd7() {}

  virtual void Paint(CDisplay* pDisplay) = 0;

private:
  CFormManager* m_pManager;
  CRect m_rClient; // after buttons drawn

protected:
  CFormManager* Manager();
  const CRect& Client() const;
  
  void SetButton(int idx, const std::string& strName);
  void SetButton(int idx, const BitmapT* pbmp);
  
  void SetCaption(const std::string& strCaption);
  CRect GetDisplayArea(int ixPix, int iyPix);

  virtual const FontT& Font() const;
};



#endif // !defined(AFX_FORM_H__2ABA5AE2_646B_11D2_BB29_F5D419D58836__INCLUDED_)
