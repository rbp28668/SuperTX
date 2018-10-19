// FormManager.h: interface for the CFormManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FORMMANAGER_H__2ABA5AE1_646B_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_FORMMANAGER_H__2ABA5AE1_646B_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include <list>

class CDisplay;
class CForm;

/**********************************************************************
* Class: CFormManagerItem
* This class stores a form and a marked flag.  The flag is used to
* stack forms and to rollback to a given point.
**********************************************************************/
class CFormManagerItem
{
  public:
    CFormManagerItem(CForm* pForm);
    CFormManagerItem();
    bool Marked() const;
    void Mark();
    CForm* Form();

    // for list
    bool operator == (const CFormManagerItem& rhs) const;
    bool operator != (const CFormManagerItem& rhs) const;
    bool operator < (const CFormManagerItem& rhs) const;
    bool operator > (const CFormManagerItem& rhs) const;
  private:
    CForm* m_pForm;
    bool m_blMarked;
};

/**********************************************************************
* Class: CFormManager
* This class manages forms on the (liquid crystal) display
**********************************************************************/
class CFormManager  
{
public:

	CFormManager(CDisplay* pDisplay);
	virtual ~CFormManager();

  void ShowForm(CForm* pForm);
  int ShowFormModal(CForm* pForm);
  void MarkCurrent();

  void BackToMark();
  void EndModal(int iRet);

  void OnCmd0();
  void OnCmd1();
  void OnCmd2();
  void OnCmd3();
  void OnCmd4();
  void OnCmd5();
  void OnCmd6();
  void OnCmd7();

  CDisplay& Display();
private:
  CDisplay* m_pDisplay;

  typedef std::list<CFormManagerItem> FormList;
  FormList m_forms;
  bool m_blExitModal;  // set true to exit modal form.
  int m_iModalReturn; // return value from modal form
};

#endif // !defined(AFX_FORMMANAGER_H__2ABA5AE1_646B_11D2_BB29_F5D419D58836__INCLUDED_)
