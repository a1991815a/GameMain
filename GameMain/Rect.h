#ifndef __RECT__
#define __RECT__

struct Rect{
	Rect();
	Rect(int x, int y, int width, int height);
	int x;
	int y;
	int width;
	int height;
};

#endif