#ifndef __REF__
#define __REF__

class Ref{
	friend class MemoryPool;
public:
	int getReferenceCount() const;
	void autorelease();
	void release();
	void retain();
protected:
	Ref();
	virtual ~Ref();
private:
	int referenceCount;
	bool isAutoRelease;
};
#endif