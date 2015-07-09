#ifndef __DXTEXTURE__
#define __DXTEXTURE__
#include <d3d9.h>
#include <d3dx9.h>
#include "Ref.h"
#include "Rect.h"
#include <string>

class DXTexture: public Ref{
	friend class DirectXUtils;
public:
	DXTexture();
	DXTexture(const char* path);
	~DXTexture();
	void loadImage(const char* path);
	size_t getWidth() const;
	size_t getHeight() const;
	const std::string& getName() const;
private:
	IDirect3DTexture9* m_texture;
	D3DXIMAGE_INFO m_info;
	PALETTEENTRY m_palet;
	Rect m_rect;
	std::string m_name;
};
#endif