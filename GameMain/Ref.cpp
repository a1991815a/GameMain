#include "Ref.h"
#include <stdexcept>

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
