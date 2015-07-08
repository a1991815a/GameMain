#ifndef __KEYEVENTLISTENER__
#define __KEYEVENTLISTENER__
#include "EventListener.h"

class KeyEventListener: public EventListener{
public:
	KeyEventListener();

protected:
	virtual bool triggerThis(Event* event) const override;
public:
	listenerFunc OnKeyDown;
	listenerFunc OnKeyUp;
	
};
#endif