#include "MemoryPoolManager.h"

MemoryPoolManager::MemoryPoolManager()
{
	m_poolList.reserve(10);
}

MemoryPoolManager::~MemoryPoolManager()
{
	clear();
}

MemoryPool* MemoryPoolManager::getCurrentPool()
{
	return m_poolList.back();
}

void MemoryPoolManager::init()
{
	new MemoryPool();
}

void MemoryPoolManager::push(MemoryPool* pool)
{
	m_poolList.push_back(pool);
}

void MemoryPoolManager::pop()
{
	if (m_poolList.size() > 1)
		m_poolList.pop_back();
}

void MemoryPoolManager::clear()
{
	delete m_poolList.front();
	m_poolList.clear();
}
