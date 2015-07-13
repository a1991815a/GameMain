#ifndef __VEC2__
#define __VEC2__
#include <d3dx9math.h>


struct Vec2{
	float x;
	float y;
	float& width;
	float& height;

//¹¹Ôìº¯Êý
	Vec2();
	Vec2(const Vec2& copy_obj);
	Vec2(float x, float y);

	Vec2 operator+(const Vec2& obj) const;
	Vec2 operator-(const Vec2& obj) const;
	const Vec2& operator+=(const Vec2& obj);
	const Vec2& operator-=(const Vec2& obj);
	const Vec2& operator=(const Vec2& obj);

	bool operator==(const Vec2& obj) const;
	bool operator!=(const Vec2& obj) const;

	D3DXVECTOR3 toDXVec3() const;
};

#endif