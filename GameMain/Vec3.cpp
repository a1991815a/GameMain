#include "Vec3.h"

#pragma warning(disable:4355)

Vec3::Vec3()
	:x(0), y(0), z(0), width(this->x), height(this->y), thick(this->z)
{

}

Vec3::Vec3(const Vec3& copy_obj)
	:x(copy_obj.x), y(copy_obj.y), z(copy_obj.z), width(this->x), height(this->y), thick(this->z)
{

}

Vec3::Vec3(float x, float y, float z)
	:x(x), y(y), z(z), width(this->x), height(this->y), thick(this->z)
{

}

Vec3 Vec3::operator+(const Vec3& obj) const
{
	Vec3 vec = *this;
	vec += obj;
	return vec;
}

Vec3 Vec3::operator-(const Vec3& obj) const
{
	Vec3 vec = *this;
	vec -= obj;
	return vec;
}

const Vec3& Vec3::operator-=(const Vec3& obj)
{
	this->x -= obj.x;
	this->y -= obj.y;
	this->z -= obj.z;
	return *this;
}

const Vec3& Vec3::operator+=(const Vec3& obj)
{
	this->x += obj.x;
	this->y += obj.y;
	this->z += obj.z;
	return *this;
}

D3DXVECTOR3 Vec3::toDXVec3() const
{
	D3DXVECTOR3 dx_vec3;
	dx_vec3.x = this->x;
	dx_vec3.y = this->y;
	dx_vec3.z = this->z;
	return dx_vec3;
}

const Vec3& Vec3::operator=(const Vec3& obj)
{
	this->x = obj.x;
	this->y = obj.y;
	this->z = obj.z;
	return *this;
}

bool Vec3::operator!=(const Vec3& obj) const
{
	return !(*this == obj);
}

bool Vec3::operator==(const Vec3& obj) const
{
	return (this->x == obj.x && this->y == obj.y && this->z == obj.z);
}


#pragma warning(default:4355)