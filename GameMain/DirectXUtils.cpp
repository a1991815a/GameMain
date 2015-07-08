#include "DirectXUtils.h"

extern void GameDraw();

DirectXUtils::DirectXUtils()
	:mp_d3d(nullptr), mp_d3dDevice(nullptr), mp_sprite(nullptr)
{

}

DirectXUtils::~DirectXUtils()
{
	if (mp_sprite)
		mp_sprite->Release();
	if (mp_d3dDevice)
		mp_d3dDevice->Release();
	if (mp_d3d)
		mp_d3d->Release();
}

LRESULT DirectXUtils::init(HWND hWnd)
{
	if (NULL == (mp_d3d = Direct3DCreate9(D3D_SDK_VERSION)))
		return E_FAIL;
	D3DPRESENT_PARAMETERS d3dpp;

	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	if (FAILED(mp_d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, 
		hWnd,
		D3DCREATE_HARDWARE_VERTEXPROCESSING,
		&d3dpp, &mp_d3dDevice)))
		return E_FAIL;
	 D3DXCreateSprite(mp_d3dDevice, &mp_sprite);
	 return S_OK;
}

void DirectXUtils::render()
{
	mp_d3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_ARGB(255, 0, 0, 0), 1, 0);
	mp_d3dDevice->BeginScene();
	mp_sprite->Begin(D3DRS_ALPHABLENDENABLE);
	GameDraw();
	mp_sprite->End();
	mp_d3dDevice->EndScene();
	mp_d3dDevice->Present(0, 0, 0, 0);
}

