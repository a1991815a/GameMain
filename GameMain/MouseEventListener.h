#ifndef __MOUSEEVENTLISTENER__
#define __MOUSEEVENTLISTENER__
#include "EventListener.h"

class MouseEventListener: public EventListener{
public:
	MouseEventListener();

protected:
	virtual bool triggerThis(Event* event) const override;

private:
	listenerFunc OnMouseLDown;
	listenerFunc OnMouseLUp;
	listenerFunc OnMouseMove;
};
#endif