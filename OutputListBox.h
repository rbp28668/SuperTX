#if !defined(AFX_OUTPUTLISTBOX_H__B37359E2_5705_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_OUTPUTLISTBOX_H__B37359E2_5705_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// OutputListBox.h : header file
//

class COutput;
class CWidget;

/////////////////////////////////////////////////////////////////////////////
// COutputListBox window

/**********************************************************************
* Class: COutputListBox
* Windows list box for displaying widget outputs
**********************************************************************/
class COutputListBox : public CListBox
{
// Construction
public:
	COutputListBox();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COutputListBox)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~COutputListBox();

  void Add(const COutput* pOutput);
  void Update(const CWidget& widget);
  const COutput* Selected();

// Generated message map functions
protected:
	//{{AFX_MSG(COutputListBox)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OUTPUTLISTBOX_H__B37359E2_5705_11D2_BB29_F5D419D58836__INCLUDED_)
