#include "CoordinateFunction.h"
#include "Scene.h"

Vec2 toLocalCoordinate(const Node* const in_node, const Vec2& point)
{
	const Node* node = in_node;
	Vec2 node_pos = point;
	for (; node && node->getNodeType() != SCENE; node = node->getParent())
		node_pos -= node->getPosition();
	if (node == nullptr)
		throw std::logic_error("This node' parent is not exist!");
	node_pos -= node->getPosition();
	return node_pos;
}

Vec2 toGlobalCoordinate(const Node* const in_node, const Vec2& point)
{
	const Node* node = in_node;
	Vec2 g_pos = point;
	for (; node && node->getNodeType() != SCENE; node = node->getParent())
		g_pos += node->getPosition();
	if (node == nullptr)
		throw std::logic_error("This node' parent is not exist!");
	g_pos += node->getPosition();
	return g_pos;
}

Vec2 toScreenCoordinate(const Node* const in_node, const Vec2& point)
{
	const Node* node = in_node;
	Vec2 s_pos = point;
	for (; node && node->getNodeType() != SCENE; node = node->getParent())
		s_pos += node->getPosition();
	if (node == nullptr)
		throw std::logic_error("This node' parent is not exist!");
	s_pos += node->getPosition();

	const Scene* scene = dynamic_cast<const Scene*>(node);
	node = scene->getCamera();

	if (node == nullptr || node->getNodeType() != CAMERA)
		throw std::logic_error("There isn't Camera or this scene is not sub Camera!");
	s_pos -= node->getPosition();
	return s_pos;
}
