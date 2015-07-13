#ifndef __DIRECTXUTILS__
#define __DIRECTXUTILS__
#include <d3d9.h>
#include <d3dx9.h>
#include "SingleInstance.h"
#include "DXTexture.h"
#include "Vec2.h"

#define _directUtils DirectXUtils::getInstance()

class DirectXUtils: public SingleInstance<DirectXUtils>{
	DEFINE_INSTANCE_PRIVATE(DirectXUtils);
public:
	LRESULT init(HWND hWnd);
	void render();
	void drawImage(DXTexture* texture, int src_x, int src_y, int src_width, int src_height,const Vec2& anchorPoint,const Vec2& pos) const;

	void drawImage(IDirect3DTexture9* dx_tex, const Rect* draw_rect, const Vec2* anchorPoint, const D3DXMATRIX* final_matrix) const;


	inline IDirect3DDevice9* getDirectDevice() const{ return mp_d3dDevice; };
	inline ID3DXSprite* getDirectSprite() const { return mp_sprite; };
private:
	IDirect3D9* mp_d3d;
	IDirect3DDevice9* mp_d3dDevice;
	ID3DXSprite* mp_sprite;
	D3DXMATRIX m_unitMatrix;

};
#endif