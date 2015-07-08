#ifndef __TIMER__
#define __TIMER__
#include "Ref.h"

class Timer: public Ref{
	friend class TimerSystem;
public:
	Timer();
	~Timer();
	int getDelta() const;
	void reset();
private:
	int m_delta;
};
#endif