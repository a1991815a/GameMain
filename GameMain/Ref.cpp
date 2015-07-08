#include "Ref.h"
#include <stdexcept>
#include "MemoryPoolManager.h"
#include <windows.h>

Ref::Ref()
	:referenceCount(0), isAutoRelease(false)
{}

Ref::~Ref()
{
	if (isAutoRelease && referenceCount != 0)
		throw std::runtime_error("reference is not 0!");
}

int Ref::getReferenceCount() const
{
	return referenceCount;
}

void Ref::autorelease()
{
	++referenceCount;
	isAutoRelease = true;
	MemoryPoolManager::getInstance()->getCurrentPool()->push(this);
}

void Ref::release()
{
	if (--referenceCount == 0)
		delete this;
}

void Ref::retain()
{
	++referenceCount;
}
