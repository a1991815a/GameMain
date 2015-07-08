#ifndef __EVENTLISTENER__
#define __EVENTLISTENER__
#include "HeaderMacro.h"
#include <functional>
#include "Event.h"
#include "Ref.h"

typedef std::function<bool(Event*)> listenerFunc;

ABSTRACT class EventListener: public Ref{
public:
	EventListener(EventTypes type);
	bool trigger(Event* event) const;
protected:
	virtual bool triggerThis(Event* event) const = 0;
	EventTypes m_type;
};
#endif