#include "DXTexture.h"
#include "HeaderMacro.h"
#include "DirectXUtils.h"
#include <stdexcept>
#include "TextureManager.h"

DXTexture::DXTexture()
	:m_texture(nullptr)
{
	SET_NULL(m_info);
	SET_NULL(m_palet);
	this->autorelease();
}

DXTexture::DXTexture( const char* path )
	:m_texture(nullptr)
{
	SET_NULL(m_info);
	SET_NULL(m_palet);
	this->autorelease();
	loadImage(path);
}

DXTexture::~DXTexture()
{
	if(m_texture != nullptr)
		m_texture->Release();
}

void DXTexture::loadImage( const char* path )
{
	if(m_texture != nullptr)
	{
		m_texture->Release();
		m_texture = nullptr;
	}
	HRESULT result = D3DXCreateTextureFromFileExA(
		_directUtils->getDirectDevice(),
		path,
		D3DX_FROM_FILE, D3DX_FROM_FILE,
		D3DX_FROM_FILE,
		0,
		D3DFMT_A8R8G8B8,
		D3DPOOL_MANAGED,
		D3DX_FILTER_LINEAR, D3DX_DEFAULT,
		0xFF000000,
		&m_info,
		&m_palet,
		&m_texture
		);

	if(FAILED(result))
		throw std::runtime_error("file is not exist!");
	m_name = path;
}

size_t DXTexture::getWidth() const
{
	return m_info.Width;
}

size_t DXTexture::getHeight() const
{
	return m_info.Height;
}

const std::string& DXTexture::getName() const
{
	return m_name;
}
