#ifndef __VEC2__
#define __VEC2__

struct Vec2{
	Vec2();
	Vec2(int x, int y);

	Vec2 operator+(const Vec2& obj) const;
	Vec2 operator-(const Vec2& obj) const;
	const Vec2& operator+=(const Vec2& obj);
	const Vec2& operator-=(const Vec2& obj);
	const Vec2& operator=(const Vec2& obj);

	bool operator==(const Vec2& obj) const;
	bool operator!=(const Vec2& obj) const;

	int x;
	int y;
	int& width;
	int& height;
};

#endif