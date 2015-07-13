#ifndef __RENDERENGINE__
#define __RENDERENGINE__
#include "SingleInstance.h"
#include "Vector.h"
#include "QuadCommand.h"

class RenderEngine: public SingleInstance<RenderEngine>{
	DEFINE_INSTANCE_PRIVATE(RenderEngine);
public:
	void init();
	void reset();
	void render();
	void pushQuadCommand(IDirect3DTexture9* render_texture, const Rect* render_rect, const Vec2* anchorPoint, const D3DXMATRIX* final_matrix,int localzOrder, int GlobalzOrder = 0);

private:
	void dragBack(Vector<QuadCommand*>& list, int index);
private:
	Vector<QuadCommand*> m_globalRenderList;
	Vector<QuadCommand*> m_localRenderList;
};
#endif