#include "Texture2D.h"
#ifndef __TEXTUREMANAGER__
#define __TEXTUREMANAGER__
#include <d3d9.h>
#include <d3dx9.h>
#include "SingleInstance.h"
#include "Map.h"
#include "Texture2D.h"
#include "DXTexture.h"
#include <string>

#define _textureManager TextureManager::getInstance()

class TextureManager: public SingleInstance<TextureManager>{
	DEFINE_INSTANCE_PRIVATE(TextureManager);
	friend class DXTexture;
	friend class Texture2D;
public:
	void pushTexture(Texture2D* texture);
	void popTexture(Texture2D* texture);
	void popTexture(const std::string& key_path);
	Texture2D* getTexture(const std::string& key_path) const;
	void loadImage(const std::string& name_path, size_t row = 0, size_t col = 0);
private:
	void pushDxTexture(DXTexture* d_tex);
	void popDxTexture(DXTexture* d_tex);
	void popDxTexture(const std::string& key_path);
	DXTexture* getDxTexture(const std::string& key_path) const;
private:
	Map<std::string, DXTexture*> m_dxImageList;
	Map<std::string, Texture2D*> m_textureList;
};
#endif