#include "Event.h"
#include "DispatchMessageSystem.h"

Event::Event(EventTypes type, void* data /*= nullptr*/)
	:m_eventType(type), m_data(data), m_key(0)
{
	this->autorelease();
}

EventTypes Event::getType() const
{
	return m_eventType;
}

Vec2 Event::getLocation() const
{
	return _dispathMessage->getLocation();
}

int Event::getLocationX() const
{
	return _dispathMessage->getLocation().x;
}

int Event::getLocationY() const
{
	return _dispathMessage->getLocation().y;
}

char Event::getKey() const
{
	return m_key;
}

std::vector<char> Event::getKeys() const
{
	return _dispathMessage->getKeys();
}

void* Event::getData()
{
	return m_data;
}
