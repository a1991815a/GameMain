#include "TimerSystem.h"
#include <windows.h>

TimerSystem::~TimerSystem()
{
	clearMap();
}

TimerSystem::TimerSystem()
{

}

void TimerSystem::init()
{
	start_time = pre_timer = cur_timer = GetTickCount();
}

void TimerSystem::refresh()
{
	pre_timer = cur_timer;
	cur_timer = GetTickCount();
	int dt = (int)(cur_timer - pre_timer);
	auto itor = beginMap();
	for (; itor != endMap(); ++itor)
		itor->second->m_delta += dt;
}
