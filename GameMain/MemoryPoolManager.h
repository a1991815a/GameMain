#ifndef __MEMORYPOOLMANAGER__
#define __MEMORYPOOLMANAGER__
#include "MemoryPool.h"
#include "SingleInstance.h"

class MemoryPoolManager: public SingleInstance<MemoryPoolManager>{
	DEFINE_INSTANCE_PRIVATE(MemoryPoolManager);
public:
	MemoryPool* getCurrentPool();
	void push(MemoryPool* pool);
	void pop();
	void clear();
private:
	std::vector<MemoryPool*> m_poolList;
};
#endif