#ifndef __QUADCOMMAND__
#define __QUADCOMMAND__
#include <d3d9.h>
#include "Rect.h"
#include <d3dx9math.h>
#include "Vec2.h"
#include "Ref.h"

class QuadCommand: public Ref{
	friend class RenderEngine;
public:
	QuadCommand();
	QuadCommand(const QuadCommand& copy_obj);
	void render() const;

private:
	IDirect3DTexture9* render_texture;
	const Rect* render_rect;
	const Vec2* anchorPoint;
	const D3DXMATRIX* final_matrix;
	bool enable;
	int zOrder;
};
#endif