#if !defined(AFX_OUTPUTCOMBOBOX_H__A8749026_5248_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_OUTPUTCOMBOBOX_H__A8749026_5248_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// OutputComboBox.h : header file
//

class COutput;
class CWidget;

/////////////////////////////////////////////////////////////////////////////
// COutputComboBox window

/**********************************************************************
* Class: COutputComboBox
* Windows combo box for displaying widget outputs
**********************************************************************/
class COutputComboBox : public CComboBox
{
// Construction
public:
	COutputComboBox();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COutputComboBox)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~COutputComboBox();

  void Add(COutput* pOuput);
  void Update(CWidget& widget);
  COutput* Selected();

	// Generated message map functions
protected:
	//{{AFX_MSG(COutputComboBox)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OUTPUTCOMBOBOX_H__A8749026_5248_11D2_BB29_F5D419D58836__INCLUDED_)
