#include "Director.h"
#include "DirectXUtils.h"
#include "DispatchMessageSystem.h"
#include "MemoryPoolManager.h"

Director::Director()
{

}

Director::~Director()
{
	
}

void Director::init()
{
	MemoryPoolManager::getInstance()->init();
}

void Director::mainloop()
{
	_directUtils->render();
	_dispathMessage->dispatch();
	MemoryPoolManager::getInstance()->getCurrentPool()->clear();
}
