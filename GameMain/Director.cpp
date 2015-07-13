#include "Director.h"
#include "DirectXUtils.h"
#include "DispatchMessageSystem.h"
#include "MemoryPoolManager.h"
#include "TextureManager.h"
#include "HeaderMacro.h"

Director::Director()
	:m_currentScene(nullptr)
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

void Director::visit() const
{

}

Scene* Director::getCurrentScene() const
{
	return m_currentScene;
}

void Director::repalceScene(Scene* scene)
{
	SAFE_RELEASE(m_currentScene);
	m_currentScene = scene;
}
