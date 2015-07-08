#include "MemoryPool.h"
#include "MemoryPoolManager.h"

MemoryPool::MemoryPool()
	:isClear(false)
{
	m_refList.reserve(160);
	MemoryPoolManager::getInstance()->push(this);
}

MemoryPool::~MemoryPool()
{
	MemoryPoolManager::getInstance()->pop();
	clear();
}

void MemoryPool::push(Ref* ref)
{
	m_refList.push_back(ref);
	if (isClear)
		isClear = false;
}

void MemoryPool::clear()
{
	if (isClear)
		return;
	std::vector<Ref*> clearList;
	m_refList.swap(clearList);
	for(int i = 0; i < clearList.size(); i++)
		clearList.at(i)->release();
	isClear = true;
}
