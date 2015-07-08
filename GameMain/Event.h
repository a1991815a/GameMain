#ifndef __EVENT__
#define __EVENT__
#include "EventTypes.h"
#include <vector>
#include "Vec2.h"
#include "Ref.h"

class Event: public Ref{
	friend class DispatchMessageSystem;
private:
	Event(EventTypes type, void* data = nullptr);
public:
	EventTypes getType() const;
	Vec2 getLocation() const;
	int getLocationX() const;
	int getLocationY() const;
	char getKey() const;
	std::vector<char> getKeys() const;

	void* getData();
private:
	EventTypes m_eventType;
	void* m_data;
	char m_key;
};
#endif