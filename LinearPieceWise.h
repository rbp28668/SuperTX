// LinearPieceWise.h: interface for the CLinearPieceWise class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINEARPIECEWISE_H__A3456E43_595E_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_LINEARPIECEWISE_H__A3456E43_595E_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include <list>
//#include <vector>

#include "Standard.h"
#include "Value.h"

class CLinearPieceWiseTemplate;

/**********************************************************************
* Class: CSegment
* Implenetation class for CLinearPieceWise which holds a fixed 
* point coordinate and a slope
**********************************************************************/
class CSegment
  {
  public:
  CValue x;
  CValue y;
  CValue m; // gradient

  bool operator ==(const CSegment& rhs) const {return x == rhs.x;}
  bool operator !=(const CSegment& rhs) const {return x != rhs.x;}
  bool operator <(const CSegment& rhs) const {return x < rhs.x;}
  bool operator >(const CSegment& rhs) const {return x > rhs.x;}
  };

/**********************************************************************
* Class: CLinearPieceWise
* Primative widget class to implement a linear piece wise approximation
* to arbitrary transfer functions
**********************************************************************/
class CLinearPieceWise : public CStandardWidget  
{
  public:
  typedef std::list<CSegment> SegmentList;

  private:
  class CLinearPieceWiseOutput : public CAnalogueOutput
    {
    public:
    CLinearPieceWiseOutput(CStandardWidget* pWidget);
    virtual CValue Value() const;
    };

	CAnalogueInput m_input;
  CLinearPieceWiseOutput m_output;
  SegmentList m_segments;
  bool m_blEditable;

  friend class CLinearPieceWiseTemplate;
  CLinearPieceWise(const CWidgetTemplate* pTemplate, const std::string& strName);
    
public:
	virtual ~CLinearPieceWise();

  virtual COutput* Output(int idx);
  virtual const COutput& Output(int idx) const;

  virtual CInput* Input(int idx);
  virtual const CInput& Input(int idx) const;

  virtual CWidget* Clone(const std::string& strName) const;

  virtual bool CanEdit() const;
  virtual void Edit(const CEditContext* pContext);
  virtual void Freeze(); // make not editable

  CValue Value() const;

  // Editing interface
  int PointCount() const;
  SegmentList::iterator Points();
  bool NextPoint(SegmentList::const_iterator& iter, CValue& x, CValue& y) const;
  void AddPoint(CValue x, CValue y);
  void DeletePoint(SegmentList::iterator& iter);
  void Clear();
  void Update();

};

/**********************************************************************
* Class: CLinearPieceWiseTemplate
* Template class to produce CLinearPieceWise widgets
**********************************************************************/
class CLinearPieceWiseTemplate : public CStandardWidgetTemplate
{
  CAnalogueConnectorDescription m_inputDesc;
  CAnalogueConnectorDescription m_outputDesc;

public:
  CLinearPieceWiseTemplate();
  virtual ~CLinearPieceWiseTemplate();

  virtual CWidget* Create(const std::string& strName) const;
  virtual const CConnectorDescription& Output(int idx) const;
  virtual int OutputCount() const;
  virtual const CConnectorDescription& Input(int idx) const;
  virtual int InputCount() const;
};


#endif // !defined(AFX_LINEARPIECEWISE_H__A3456E43_595E_11D2_BB29_F5D419D58836__INCLUDED_)
