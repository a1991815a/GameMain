#include "DXDrawUtils.h"
#include "DirectXUtils.h"

DXDrawUtils::DXDrawUtils()
{

}

DXDrawUtils::~DXDrawUtils()
{

}

void DXDrawUtils::drawImage(Texture2D* texture, const Vec2& pos, const Vec2& anchorPoint)
{
	_directUtils->drawImage(texture->m_texture,
		0, 0,
		texture->getWidth(), texture->getHeight(),
		anchorPoint, pos
		);
}

void DXDrawUtils::drawText(const std::string& text)
{
	
}
