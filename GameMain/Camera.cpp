#include "Camera.h"

Camera::Camera()
{
	setNodeType(CAMERA);
}

Camera::~Camera()
{
	
}

bool Camera::init()
{
	setPosition(Vec2(0, 0));
	return true;
}

void Camera::Move(const Vec2& vec_offset)
{
	setPosition(getPosition() + vec_offset);
}

void Camera::visit() const
{
	
}