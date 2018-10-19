// TimerManager.h: interface for the CTimerManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TIMERMANAGER_H__A3456E44_595E_11D2_BB29_F5D419D58836__INCLUDED_)
#define AFX_TIMERMANAGER_H__A3456E44_595E_11D2_BB29_F5D419D58836__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include <list>

/**********************************************************************
* Class: CTimer
* Abstract base class for timers.  Timers need to be registered
* with the singleton CTimerManager.  Their Tick method is then
* called at every frame
**********************************************************************/
class CTimer
{
  public:
    virtual ~CTimer() {}
    virtual void Tick();
};

/**********************************************************************
* Class: CTimerManager
* This singleton class keeps a list of timers in the system.  Each
* timer is called every frame that is transmitted. 
**********************************************************************/
class CTimerManager  
{
  typedef std::list<CTimer*> TimerList;

  TimerList m_timers;
  
  static CTimerManager m_manager;

public:
	CTimerManager();
	virtual ~CTimerManager();

  void AddTimer(CTimer* pTimer);
  void RemoveTimer(CTimer* pTimer);

  void Tick();
  static CTimerManager& Timers();

};

#endif // !defined(AFX_TIMERMANAGER_H__A3456E44_595E_11D2_BB29_F5D419D58836__INCLUDED_)
