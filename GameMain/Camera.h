#ifndef __CAMERA__
#define __CAMERA__
#include "Node.h"
#include "HeaderMacro.h"

class Camera: public Node{
	Camera();
public:
	CREATE_FUNC(Camera);
	bool init();
	void Move(const Vec2& vec_offset);

	virtual void visit() const override;

};
#endif