#include "Texture2D.h"
#include "DirectXUtils.h"
#include "TextureManager.h"
#include "HeaderMacro.h"

Texture2D::Texture2D()
	:m_texture(nullptr)
{
	this->autorelease();
}

Texture2D::Texture2D( const char* path )
	:m_texture(nullptr)
{
	this->autorelease();
	m_texture = TextureManager::getInstance()->getDxTexture(m_name);
	m_rect.x = m_rect.y = 0;
	m_rect.width = m_texture->getWidth();
	m_rect.height = m_texture->getHeight();
	m_name = m_texture->getName();
	m_texture->retain();
}

Texture2D::Texture2D( DXTexture* tex )
{
	this->autorelease();
	m_texture = tex;
	m_rect.x = m_rect.y = 0;
	m_rect.width = tex->getWidth();
	m_rect.height = tex->getHeight();
	m_name = tex->getName();
	m_texture->retain();
}

Texture2D::Texture2D( DXTexture* tex, const char* name, const Rect& rect )
{
	this->autorelease();
	this->m_rect = rect;
	this->m_name = name;
	this->m_texture = tex;
	m_texture->retain();
}

Texture2D::~Texture2D()
{
	SAFE_RELEASE(m_texture);
}

void Texture2D::visit(const Vec2& anchorPoint, const Vec2& pos) const
{
	_directUtils->drawImage(m_texture, m_rect.x, m_rect.y, m_rect.width, m_rect.height, anchorPoint, pos);
}

int Texture2D::getWidth() const
{
	return m_rect.width;
}

int Texture2D::getHeight() const
{
	return m_rect.height;
}

const std::string& Texture2D::getName() const
{
	return m_name;
}
