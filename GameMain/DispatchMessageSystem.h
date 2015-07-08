#ifndef __DISPATCHMESSAGESYSTEM__
#define __DISPATCHMESSAGESYSTEM__
#include "SingleInstance.h"
#include "ManagerTemplate.h"
#include "Vec2.h"
#include "EventListener.h"
#include "Event.h"

#define _dispathMessage DispatchMessageSystem::getInstance()

class DispatchMessageSystem: public SingleInstance<DispatchMessageSystem>, public ManagerMapTemplate<EventListener>, public ManagerVectorTemplate<Event>{
	DEFINE_INSTANCE_PRIVATE(DispatchMessageSystem);
public:
	void dispatch();
	void clear();
	void dispatchMessage(EventTypes type, void* data = nullptr);
	void dispatchKeyMessage(EventTypes type, char key, void* data = nullptr);
	void dispatchMouseMessage(EventTypes type, int x, int y, void* data = nullptr);

	char getKey() const;
	const std::vector<char>& getKeys() const;
	const Vec2& getLocation() const;
	inline void addListener(EventListener* listener){ pushMap(listener); };
	inline void deleteListener(EventListener* listener){ popMap(listener); };

private:
	std::vector<char> m_keyboardKey;
	Vec2 m_mouseLocation;
};
#endif