#if !defined(AFX_MODELLISTBOX_H__97337623_5188_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_MODELLISTBOX_H__97337623_5188_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// ModelListBox.h : header file
//

class CModel;
class CModelList;

/////////////////////////////////////////////////////////////////////////////
// CModelListBox window

/**********************************************************************
* Class: CModelListBox
* Windows list box for displaying a list of models
**********************************************************************/
class CModelListBox : public CListBox
{
// Construction
public:
	CModelListBox();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CModelListBox)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CModelListBox();
  
  void Update(CModelList* pList);
  void Add(CModel* pModel);
  CModel* Selected();

	// Generated message map functions
protected:
	//{{AFX_MSG(CModelListBox)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MODELLISTBOX_H__97337623_5188_11D2_BB29_F5D419D58836__INCLUDED_)
