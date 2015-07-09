#include "Director.h"
#include "DirectXUtils.h"
#include "DispatchMessageSystem.h"
#include "MemoryPoolManager.h"
#include "TextureManager.h"

Director::Director()
{

}

Director::~Director()
{
	
}

void Director::init()
{
	MemoryPoolManager::getInstance()->init();
	TextureManager::getInstance();
}

void Director::mainloop()
{
	_directUtils->render();
	_dispathMessage->dispatch();
	MemoryPoolManager::getInstance()->getCurrentPool()->clear();
}
