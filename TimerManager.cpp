// TimerManager.cpp: implementation of the CTimerManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TimerManager.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

// singleton - only one timer manager in system driven
// by encoder clock.
CTimerManager CTimerManager::m_manager;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTimerManager::CTimerManager()
{

}

CTimerManager::~CTimerManager()
{
}

void CTimerManager::AddTimer(CTimer* pTimer)
{
  assert(this);
  assert(pTimer);
  m_timers.push_back(pTimer);
}

void CTimerManager::RemoveTimer(CTimer* pTimer)
{
  assert(this);
  assert(pTimer);
  m_timers.remove(pTimer);
}

void CTimerManager::Tick()
{
  assert(this);
  for(TimerList::iterator iter = m_timers.begin();
      iter != m_timers.end();
      ++iter)
    {
    (*iter)->Tick();
    }
}

CTimerManager& CTimerManager::Timers()
{
  return m_manager;
}

