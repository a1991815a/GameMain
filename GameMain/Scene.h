#ifndef __SCENE__
#define __SCENE__
#include "Node.h"
#include "Camera.h"
#include "HeaderMacro.h"

class Scene: public Node{
	Scene();
public:
	CREATE_FUNC(Scene);
	bool init();
	Camera* getCamera() const;

	virtual void visit() const override;

private:
	Camera* m_camera;
};
#endif