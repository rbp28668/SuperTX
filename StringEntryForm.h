// StringEntryForm.h: interface for the CStringEntryForm class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STRINGENTRYFORM_H__C18284E1_7350_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_STRINGENTRYFORM_H__C18284E1_7350_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Form.h"

/**********************************************************************
* Class: CStringEntryForm
* Form for entering string data
**********************************************************************/
class CStringEntryForm : public CForm  
{
public:
	CStringEntryForm(CFormManager* pManager);
	virtual ~CStringEntryForm();

  virtual void OnCmd0(); // Insert
  virtual void OnCmd1(); // Delete
  virtual void OnCmd2(); // Right
  virtual void OnCmd3(); // Left
  virtual void OnCmd4(); // Caps
  virtual void OnCmd5();
  virtual void OnCmd6(); // Cancel
  virtual void OnCmd7(); // OK

  virtual void Paint(CDisplay* pDisplay);

  const std::string& Text() const;
  void SetText(const std::string& str);

private:
  static char* m_aszKeys[];
  static int m_aiLengths[];
  enum {KEY_ROWS = 4};

  int m_iRow;     // row of currently selected letter
  int m_iColumn;  // column of currently selected letter
  std::string m_strText; // current text value
  bool m_blCaps;      // true if caps on.
  CPoint m_ptBuffer;  // position of text buffer on screen.
  CPoint m_aptRowStart[KEY_ROWS];

  void UpdateKey(bool blInvert);
};

#endif // !defined(AFX_STRINGENTRYFORM_H__C18284E1_7350_11D2_BB29_F5D419D58836__INCLUDED_)
