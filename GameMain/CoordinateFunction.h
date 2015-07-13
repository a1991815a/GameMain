#ifndef __COORDINATEFUNCTION__
#define __COORDINATEFUNCTION__
#include "Vec2.h"
#include "Node.h"

Vec2 toLocalCoordinate(const Node* const in_node, const Vec2& point);
Vec2 toGlobalCoordinate(const Node* const in_node, const Vec2& point);
Vec2 toScreenCoordinate(const Node* const in_node, const Vec2& point);

#endif