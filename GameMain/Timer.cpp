#include "Timer.h"
#include "TimerSystem.h"

Timer::Timer()
	:m_delta(0)
{
	TimerSystem::getInstance()->pushMap(this);
}

Timer::~Timer()
{
	TimerSystem::getInstance()->pushMap(this);
}

int Timer::getDelta() const
{
	return m_delta;
}

void Timer::reset()
{
	m_delta = 0;
}
