// ConnectForm.h: interface for the CConnectForm class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONNECTFORM_H__6C89F2C1_894E_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_CONNECTFORM_H__6C89F2C1_894E_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "SelectionForm.h"
#include "Selection.h"
#include "Widgets.hpp"

class CWidgetList;

/**********************************************************************
* Class: CConnectSelect
* Selection for connection dialog- needs to hold any one of widgets,
* inputs or outputs depending on the use at any one time.  This also
* draws the current connection details if m_blPaintConnectin is true.
**********************************************************************/
class CConnectSelect : public CSelection
{
  public:

    CConnectSelect();

    virtual void Paint(CDisplay* pDisplay);

    void Add(const CWidget* ptr, CDisplay* pDisplay = 0);
    CWidget* SelectedWidget();

    void Add(const CInput* ptr, CDisplay* pDisplay = 0);
    CInput* SelectedInput();

    void Add(const COutput* ptr, CDisplay* pDisplay = 0);
    COutput* SelectedOutput();

    // Current connection details.
    void PaintConnection();
    void Destination(const std::string& strName);
    void Input(const std::string& strName);
    void Source(const std::string& strName);
    void Output(const std::string& strName);

  private:
    bool m_blPaintConnection;
    std::string m_strDest;
    std::string m_strInput;
    std::string m_strSrc;
    std::string m_strOutput;

};

/**********************************************************************
* Class: CConnectForm
* TX User interface form for setting up connections between widgets.
**********************************************************************/
class CConnectForm : public CSelectionForm  
{
public:
	CConnectForm(CWidgetList* pWidgets, CFormManager* pManager);
	virtual ~CConnectForm();

  virtual void OnCmd0(); // Dest
  virtual void OnCmd1(); // Input
  virtual void OnCmd2(); // Source
  virtual void OnCmd3(); // Output
  //virtual void OnCmd4() 
  //virtual void OnCmd5() 
  virtual void OnCmd6(); // Connect
  //virtual void OnCmd7()

  virtual void Paint(CDisplay* pDisplay);

private:
    enum ModeT
      {
      CONNECT,
      SOURCE,
      OUTPUT,
      DEST,
      INPUT
      };

  ModeT m_mode;

  CWidgetList* m_pWidgets;
  CConnectSelect m_select;

  CWidget* m_pSourceWidget;
  CWidget* m_pDestWidget;
  COutput* m_pSourceOutput;
  CInput* m_pDestInput;

  void DisplayInputWidgets();
  void DisplayOutputWidgets();
  void DisplayInputs(CWidget* pWidget);
  void DisplayOutputs(CWidget* pWidget);

};

#endif // !defined(AFX_CONNECTFORM_H__6C89F2C1_894E_11D2_BB29_F5D419D58836__INCLUDED_)
