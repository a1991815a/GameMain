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
	for(size_t i = 0; i < m_refList.size(); i++)
		m_refList.at(i)->release();
	m_refList.clear();
	isClear = true;
}
