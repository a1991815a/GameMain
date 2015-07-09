#include "DispatchMessageSystem.h"

DispatchMessageSystem::DispatchMessageSystem()
{

}

DispatchMessageSystem::~DispatchMessageSystem()
{
	clearMap();
	clearVector();
}

void DispatchMessageSystem::dispatch()
{
	for(size_t i = 0; i < m_keyboardKey.size(); i++){
		Event* event = new Event(EVENT_KEYDOWN);
		event->m_key = m_keyboardKey.at(i);
		pushVector(event);
	}

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

void DispatchMessageSystem::postMessage(EventTypes type, void* data /*= nullptr*/)
{
	Event* event = new Event(type, data);
	pushVector(event);
}

void DispatchMessageSystem::postKeyMessage(EventTypes type, char key, void* data /*= nullptr*/)
{
	switch (type)
	{
	case EVENT_KEYDOWN:
		for (size_t i = 0; i < m_keyboardKey.size(); i++)
			if (key == m_keyboardKey.at(i))
				return;
		m_keyboardKey.push_back(key);
		break;
	case EVENT_KEYUP:
		for(size_t i = 0; i < m_keyboardKey.size(); i++)
			if (key == m_keyboardKey.at(i))
				m_keyboardKey.erase(m_keyboardKey.begin() + i);
		break;
	default:
		break;
	}
}

void DispatchMessageSystem::postMouseMessage(EventTypes type, float x, float y, void* data /*= nullptr*/)
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
