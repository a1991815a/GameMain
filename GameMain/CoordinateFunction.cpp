#include "CoordinateFunction.h"

Vec2 toLocalCoordinate(Node* node, const Vec2& point)
{
	Vec2 node_pos = point;
	for (; node && node->getNodeType() != SCENE; node = node->getParent())
		node_pos -= node->getPosition();
	if (node == nullptr)
		throw std::logic_error("This node' parent is not exist!");
	node_pos -= node->getPosition();
	return node_pos;
}

Vec2 toGlobalCoordinate(Node* node, const Vec2& point)
{
	Vec2 g_pos = point;
	for (; node && node->getNodeType() != SCENE; node = node->getParent())
		g_pos += node->getPosition();
	if (node == nullptr)
		throw std::logic_error("This node' parent is not exist!");
	g_pos += node->getPosition();
	return g_pos;
}

Vec2 toScreenCoordinate(Node* node, const Vec2& point)
{
	Vec2 s_pos = point;
	for (; node && node->getNodeType() != SCENE; node = node->getParent())
		s_pos += node->getPosition();
	if (node == nullptr)
		throw std::logic_error("This node' parent is not exist!");
	s_pos += node->getPosition();

	node = node->getParent();
	if (node == nullptr || node->getNodeType() != CAMERA)
		throw std::logic_error("There isn't Camera or this scene is not sub Camera!");
	s_pos -= node->getPosition();
	return s_pos;
}
