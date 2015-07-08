#include "MouseEventListener.h"

MouseEventListener::MouseEventListener()
	:EventListener(EVENT_MOUSE),
	OnMouseLDown(nullptr), OnMouseLUp(nullptr), OnMouseMove(nullptr)
{

}

bool MouseEventListener::triggerThis(Event* event) const
{
	switch (event->getType())
	{
	case EVENT_MOUSEDOWN:
		if (OnMouseLDown)
			return OnMouseLDown(event);
		break;
	case EVENT_MOUSEUP:
		if (OnMouseLUp)
			return OnMouseLUp(event);
		break;
	case EVENT_MOUSEMOVE:
		if (OnMouseMove)
			return OnMouseMove(event);
		break;
	default:
		break;
	}
	return false;
}
