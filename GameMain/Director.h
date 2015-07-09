#ifndef __DIRECTOR__
#define __DIRECTOR__
#include "SingleInstance.h"
#include "Scene.h"

class Director: public SingleInstance<Director>{
	DEFINE_INSTANCE_PRIVATE(Director);
public:
	void init();
	void mainloop();
private:
	Scene* m_currentScene;
};
#endif