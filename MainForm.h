// MainForm.h: interface for the CMainForm class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFORM_H__2ABA5AE4_646B_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_MAINFORM_H__2ABA5AE4_646B_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "Form.h"

class CFormManager;
class CEncoder;
class CModelList;
class CTemplateList;

class CMainForm : public CForm  
{
public:
	CMainForm(CFormManager* pManager);
	virtual ~CMainForm();

  virtual void OnCmd0();
  virtual void OnCmd1();
  virtual void OnCmd2();
  virtual void OnCmd3();
  virtual void OnCmd4();
  virtual void OnCmd5();
  virtual void OnCmd6();
  virtual void OnCmd7();

  virtual void Paint(CDisplay* pDisplay);

private:
  enum 
    {
    MODEL,      // model name in panel 1
    TIMER1,     // timer 1 in panel 2
    TIMER2,     // timer 2 in panel 3
    VOLTS,      // voltage readout in panel 4
    PANELS = 4  // 4 panels in centre section
    }; 

  CRect m_arPanels[PANELS]; // coordinates of each one.
  CPoint m_ptModelName;
  CPoint m_ptTimer1;
  CPoint m_ptTimer2;
  CPoint m_ptVolts;

  CModelList* m_pModels;
  CEncoder* m_pEncoder;
  CTemplateList* m_pTemplates;

};

#endif // !defined(AFX_MAINFORM_H__2ABA5AE4_646B_11D2_BB29_F5D419D58836__INCLUDED_)
