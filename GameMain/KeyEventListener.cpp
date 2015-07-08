#include "KeyEventListener.h"

KeyEventListener::KeyEventListener()
	:OnKeyDown(nullptr), OnKeyUp(nullptr)
{

}

bool KeyEventListener::triggerThis(Event* event) const
{
	switch (event->getType())
	{
	case EVENT_KEYDOWN:
		if (OnKeyDown)
			return OnKeyDown(event);
		break;
	case EVENT_KEYUP:
		if (OnKeyUp)
			return OnKeyUp(event);
		break;
	default:
		break;
	}
	return false;
}
