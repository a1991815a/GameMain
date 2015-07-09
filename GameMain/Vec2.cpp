#include "Vec2.h"

#pragma warning(disable:4355)

Vec2::Vec2()
	:x(0), y(0), width(this->x), height(this->y)
{

}

Vec2::Vec2( float x, float y )
	:x(x), y(y), width(this->x), height(this->y)
{

}

Vec2 Vec2::operator+( const Vec2& obj ) const
{
	Vec2 vec2;
	vec2.x = x + obj.x;
	vec2.y = y + obj.y;
	return vec2;
}

Vec2 Vec2::operator-( const Vec2& obj ) const
{
	Vec2 vec2;
	vec2.x = x - obj.x;
	vec2.y = y - obj.y;
	return vec2;
}

D3DXVECTOR3 Vec2::toDXVec3() const
{
	D3DXVECTOR3 dx_v3;
	dx_v3.x = x;
	dx_v3.y = y;
	dx_v3.z = 0;
	return dx_v3;
}

const Vec2& Vec2::operator+=( const Vec2& obj )
{
	x += obj.x;
	y += obj.y;
	return *this;
}

const Vec2& Vec2::operator-=( const Vec2& obj )
{
	x -= obj.x;
	y -= obj.y;
	return *this;
}

const Vec2& Vec2::operator=( const Vec2& obj )
{
	x = obj.x;
	y = obj.y;
	return *this;
}

bool Vec2::operator==( const Vec2& obj ) const
{
	return (x == obj.x && y == obj.y);
}

bool Vec2::operator!=( const Vec2& obj ) const
{
	return !(*this == obj);
}


#pragma warning(default:4355)