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
	D3DPRESENT_PARAMETERS d3dpp = { 0 };

	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	if (FAILED(mp_d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, 
		hWnd,
		D3DCREATE_HARDWARE_VERTEXPROCESSING,
		&d3dpp, &mp_d3dDevice)))
		return E_FAIL;
	 D3DXCreateSprite(mp_d3dDevice, &mp_sprite);
	 D3DXMatrixTranslation(&m_unitMatrix, 0, 0, 0);

	 return S_OK;
}

void DirectXUtils::render()
{
	if(!SUCCEEDED(mp_d3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_ARGB(255, 0, 0, 0), 0, 0)))
		return;
	if(!SUCCEEDED(mp_d3dDevice->BeginScene()))
		return;
	if(SUCCEEDED(mp_sprite->Begin(D3DXSPRITE_ALPHABLEND)))
	{
		GameDraw();
		mp_sprite->End();
	}
	mp_d3dDevice->EndScene();
	mp_d3dDevice->Present(0, 0, 0, 0);
}

void DirectXUtils::drawImage( DXTexture* texture, 
	int src_x, int src_y, int src_width, int src_height,
	const Vec2& anchorPoint,const Vec2& pos ) const
{
	RECT rect = { 0 };
	rect.left = src_x;
	rect.right = src_x + src_width;
	rect.top = src_y;
	rect.bottom = src_y + src_height;
	D3DXVECTOR3 anchorPoint3V, pos3V;
	anchorPoint3V.x = anchorPoint.x;
	anchorPoint3V.y = anchorPoint.y;
	anchorPoint3V.z = 0;
	pos3V.x = pos.x;
	pos3V.y = pos.y;
	pos3V.z = 0;

	mp_sprite->Draw(
		texture->m_texture,
		&rect,
		&anchorPoint3V,
		&pos3V,
		0xFFFFFFFF
		);
}

void DirectXUtils::drawImage(IDirect3DTexture9* dx_tex, const Rect* draw_rect, const Vec2* anchorPoint, const D3DXMATRIX* final_matrix) const
{
	RECT rect;
	rect.left = draw_rect->x;
	rect.right = draw_rect->x + draw_rect->width;
	rect.top = draw_rect->y;
	rect.bottom = draw_rect->y + draw_rect->height;

	mp_sprite->SetTransform(final_matrix);
	mp_sprite->Draw(dx_tex, &rect, &anchorPoint->toDXVec3(), NULL, NULL);
	mp_sprite->SetTransform(&m_unitMatrix);
}

