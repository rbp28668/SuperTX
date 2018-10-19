// Selection.h: interface for the CSelection class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SELECTION_H__8D18CDE1_66C1_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_SELECTION_H__8D18CDE1_66C1_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include <list>

class CDisplay;
struct FontT;

#pragma warning(disable: 4786) // name > 255 chars

/**********************************************************************
* Class: CSelectionEntry
* Implementation class for CSelection which stores a single 
* entry in a selection
**********************************************************************/
class CSelectionEntry
{
  public:
    CSelectionEntry();
    CSelectionEntry(const std::string& str, void* ptr);

    bool operator == (const CSelectionEntry& rhs) const;
    bool operator != (const CSelectionEntry& rhs) const;
    bool operator < (const CSelectionEntry& rhs) const;
    bool operator > (const CSelectionEntry& rhs) const;

    void* Ptr() const;
    const std::string& Str() const;

  private:
    std::string m_str;
    void* m_ptr;
};

/**********************************************************************
* Class: CSelection
* User interface class for selecting one of N items (like a list box)
**********************************************************************/
class CSelection  
{
public:
	CSelection();
	virtual ~CSelection();

  virtual void RemoveAll();
  virtual void SetPosition(const CRect& rPosition);
  virtual void Paint(CDisplay* pDisplay);
  virtual void Title(const std::string& strTitle);

  const std::string& Selected();
  bool SelectionValid();

  void Up();
  void Down();

protected:
  void Add(const std::string& strName, void* ptr, CDisplay* pDisplay=0);
  void* SelectedPtr();
  const FontT& Font() const;
  CRect& ScreenPosition();

private:
  typedef std::list<CSelectionEntry> EntryList;
  CRect m_rPosition;          // position on screen
  std::string m_strTitle;     // title for selection
  EntryList m_entries;        // list of entries
  EntryList::iterator m_pos;  // position of selected item
  int m_iPos;                 // and its integer position
  int m_iOffset;              // contents scrolled by this amount.
  int m_iDisplaySize;         // number of lines in display
};

template <class T> class Selection : public CSelection
{
  public:
    void Add(const std::string& strName,  const T* ptr, CDisplay* pDisplay = 0) {CSelection::Add(strName, (void*)ptr, pDisplay);}
    void Add(const std::string& strName,  T* ptr, CDisplay* pDisplay = 0) {CSelection::Add(strName, ptr, pDisplay);}
    T* SelectedPtr() {return static_cast<T*>(CSelection::SelectedPtr());}
};

#endif // !defined(AFX_SELECTION_H__8D18CDE1_66C1_11D2_BB29_F5D419D58836__INCLUDED_)
