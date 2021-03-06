#include "Sprite.h"
#include "TextureManager.h"
#include "CoordinateFunction.h"
#include "DXDrawUtils.h"

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
	Sprite* ret = Sprite::create();
	ret->m_texture = _textureManager->getTexture(path);
	return ret;
}

void Sprite::visit() const
{
	Vec2 render_pos = toScreenCoordinate(this, getPosition());
	Vec2 anchor_pos = getAnchorPoint();
	anchor_pos.x *= m_texture->getWidth();
	anchor_pos.y *= m_texture->getHeight();
	_dxDrawUtils->drawImage(m_texture, render_pos, anchor_pos);
	visitChilds();
}
