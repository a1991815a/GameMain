#include "DispatchMessageSystem.h"

DispatchMessageSystem::DispatchMessageSystem()
{

}

DispatchMessageSystem::~DispatchMessageSystem()
{
	clearMap()
	clearVector();
}

void DispatchMessageSystem::dispatch()
{
	auto eventItor = beginVector();
	for (; eventItor != endVector(); ++eventItor)
	{
		auto listenerItor = beginMap();
		for (; listenerItor != endMap(); ++listenerItor)
			if (listenerItor->second->trigger(*eventItor))
				break;
	}
	clear();
}

void DispatchMessageSystem::clear()
{
	clearVector();
}

void DispatchMessageSystem::dispatchMessage(EventTypes type, void* data /*= nullptr*/)
{
	Event* event = new Event(type, data);
	pushVector(event);
}

void DispatchMessageSystem::dispatchKeyMessage(EventTypes type, char key, void* data /*= nullptr*/)
{
	Event* event = new Event(type, data);
	event->m_key = key;
	pushVector(event);
	switch (type)
	{
	case EVENT_KEYDOWN:
		m_keyboardKey.push_back(key);
		break;
	case EVENT_KEYUP:
		for(size_t i = 0; i < m_keyboardKey.size(); i++)
			if (key == m_keyboardKey.at(i))
			{
				m_keyboardKey.erase(m_keyboardKey.begin() + i);
				break;
			}
		break;
	default:
		break;
	}
}

void DispatchMessageSystem::dispatchMouseMessage(EventTypes type, int x, int y, void* data /*= nullptr*/)
{
	Event* event = new Event(type, data);
	pushVector(event);
	m_mouseLocation.x = x;
	m_mouseLocation.y = y;
}

char DispatchMessageSystem::getKey() const
{
	return m_keyboardKey.back();
}

const std::vector<char>& DispatchMessageSystem::getKeys() const
{
	return m_keyboardKey;
}

const Vec2& DispatchMessageSystem::getLocation() const
{
	return m_mouseLocation;
}
