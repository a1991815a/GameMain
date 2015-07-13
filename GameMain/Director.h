#ifndef __DIRECTOR__
#define __DIRECTOR__
#include "SingleInstance.h"
#include "Scene.h"

class Director: public SingleInstance<Director>{
	DEFINE_INSTANCE_PRIVATE(Director);
public:
	void init();
	void mainloop();
	void visit() const;
	Scene* getCurrentScene() const;
	void repalceScene(Scene* scene);
private:
	Scene* m_currentScene;
};
#endif