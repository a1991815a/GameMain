#ifndef __HEADERMACRO__
#define __HEADERMACRO__

#define SAFE_DELETE(P) do{if(P) delete P; P = nullptr;} while(0)
#define SAFE_RELEASE(P) do{if(P) P->release(); P = nullptr;} while(0)

#define ABSTRACT 

#define SET_NULL(DATA) memset(&DATA, 0, sizeof(DATA)) 

#define CREATE_FUNC(OBJ)				\
static OBJ* create(){					\
	OBJ* obj = new OBJ();				\
	if (obj && obj->init()){			\
		obj->autorelease();				\
		return obj;						\
	}									\
	delete obj;							\
	return nullptr;						\
}

enum NodeTypes
{
	SCENE,
	LAYER,
	SPRITE,
	CAMERA
};

#endif