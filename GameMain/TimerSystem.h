#ifndef __TIMERSYSTEM__
#define __TIMERSYSTEM__
#include "SingleInstance.h"
#include "ManagerTemplate.h"
#include "Timer.h"

typedef unsigned long long time_type;

class TimerSystem: public SingleInstance<TimerSystem>, public ManagerMapTemplate<Timer>{
	DEFINE_INSTANCE_PRIVATE(TimerSystem);
public:
	void init();
	void refresh();
private:
	time_type start_time;
	time_type pre_timer;
	time_type cur_timer;
};
#endif