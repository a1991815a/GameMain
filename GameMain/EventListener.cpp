#include "EventListener.h"

EventListener::EventListener()
{
	this->autorelease();
}

bool EventListener::trigger(Event* event) const
{
	if ((event->getType() & m_type) == 0)
		return false;
	return this->triggerThis(event);
}
