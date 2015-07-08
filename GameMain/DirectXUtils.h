#ifndef __DIRECTXUTILS__
#define __DIRECTXUTILS__
#include <d3d9.h>
#include <d3dx9.h>
#include "SingleInstance.h"

#define _directUtils DirectXUtils::getInstance()

class DirectXUtils: public SingleInstance<DirectXUtils>{
	DEFINE_INSTANCE_PRIVATE(DirectXUtils);
public:
	LRESULT init(HWND hWnd);
	void render();
private:
	IDirect3D9* mp_d3d;
	IDirect3DDevice9* mp_d3dDevice;
	ID3DXSprite* mp_sprite;
};
#endif