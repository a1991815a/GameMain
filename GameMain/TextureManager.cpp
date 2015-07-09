#include "TextureManager.h"

TextureManager::TextureManager()
{
	
}

TextureManager::~TextureManager()
{
	
}

void TextureManager::pushTexture( Texture2D* texture )
{
	m_textureList.insert(texture->getName(), texture);
}

void TextureManager::popTexture( Texture2D* texture )
{
	m_textureList.erase(texture->getName());
}

void TextureManager::popTexture( const std::string& key_path )
{
	m_textureList.erase(key_path);
}

Texture2D* TextureManager::getTexture( const std::string& key_path ) const
{
	return m_textureList.at(key_path);
}

void TextureManager::loadImage( const std::string& name_path, size_t row /*= 0*/, size_t col /*= 0*/ )
{
	DXTexture* dx_tex = new DXTexture(name_path.c_str());
	pushDxTexture(dx_tex);

	if (row == 0 || col == 0 || (row == 1 && col == 1))
	{
		Texture2D* texture = new Texture2D(dx_tex);
		pushTexture(texture);
		return;
	}
	int cut_width = dx_tex->getWidth() / col;
	int cut_height = dx_tex->getHeight() / row;
	int count_i = 0;

	std::string pre_path = name_path;
	std::string bac_path = name_path;

	pre_path.erase(name_path.find('.'), pre_path.size());
	bac_path.erase(0, pre_path.size());

	for (size_t row_i = 0; row_i < row; row_i++)
	{
		int cur_y = row_i * cut_height; 
		for (size_t col_i = 0; col_i < col; col_i++, count_i++)
		{
			int cur_x = col_i * cut_width;
			Rect rect;
			rect.x = cur_x;
			rect.y = cur_y;
			rect.width = cut_width;
			rect.height = cut_height;
			char name_tmp[128] = { 0 };
			sprintf_s(name_tmp, "%s_%d%s",pre_path.c_str(), count_i, bac_path.c_str());
			Texture2D* texture = new Texture2D(dx_tex, name_tmp, rect);
			m_textureList.insert(texture->getName(), texture);
		}
	}
}

void TextureManager::pushDxTexture( DXTexture* d_tex )
{
	m_dxImageList.insert(d_tex->getName(), d_tex);
}

void TextureManager::popDxTexture( DXTexture* d_tex )
{
	m_dxImageList.erase(d_tex->getName());
}

void TextureManager::popDxTexture( const std::string& key_path )
{
	m_dxImageList.erase(key_path);
}

DXTexture* TextureManager::getDxTexture( const std::string& key_path ) const
{
	return m_dxImageList.at(key_path);
}
