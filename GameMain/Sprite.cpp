#include "Sprite.h"
#include "TextureManager.h"

Sprite::Sprite()
	:m_texture(nullptr)
{
	setNodeType(SPRITE);
}

Sprite* Sprite::create()
{
	Sprite* ret = new Sprite();
	ret->autorelease();
	return ret;
}

Sprite* Sprite::create(Texture2D* texture)
{
	Sprite* ret = new Sprite();
	ret->m_texture = texture;
	ret->autorelease();
	return ret;
}

Sprite* Sprite::create(const char* path)
{
	_textureManager->loadImage(path);
	return createByFrame(path);
}

Sprite* Sprite::createByFrame(const char* path)
{
	Sprite* ret = new Sprite();
	ret->m_texture = _textureManager->getTexture(path);
	return ret;
}

void Sprite::visit() const
{
	
}
