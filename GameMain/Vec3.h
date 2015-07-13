#ifndef __VEC3__
#define __VEC3__
#include <d3dx9math.h>

struct Vec3{
	float x;
	float y;
	float z;
	float& width;
	float& height;
	float& thick;

//¹¹Ôìº¯Êý
	Vec3();
	Vec3(const Vec3& copy_obj);
	Vec3(float x, float y, float z);

	Vec3 operator+(const Vec3& obj) const;
	Vec3 operator-(const Vec3& obj) const;
	bool operator==(const Vec3& obj) const;
	bool operator!=(const Vec3& obj) const;

	const Vec3& operator=(const Vec3& obj);
	const Vec3& operator+=(const Vec3& obj);
	const Vec3& operator-=(const Vec3& obj);
	D3DXVECTOR3 toDXVec3() const;
};
#endif