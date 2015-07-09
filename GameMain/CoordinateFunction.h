#ifndef __COORDINATEFUNCTION__
#define __COORDINATEFUNCTION__
#include "Vec2.h"
#include "Node.h"

Vec2 toLocalCoordinate(Node* node, const Vec2& point);
Vec2 toGlobalCoordinate(Node* node, const Vec2& point);
Vec2 toScreenCoordinate(Node* node, const Vec2& point);

#endif