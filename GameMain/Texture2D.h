#ifndef __TEXTURE2D__
#define __TEXTURE2D__
#include <d3d9.h>
#include <d3dx9.h>
#include "Rect.h"
#include "Ref.h"
#include "Vec2.h"
#include "DXTexture.h"

class Texture2D: public Ref{
	friend class TextureManager;
	friend class DXDrawUtils;
public:
	Texture2D();
	Texture2D(const char* path);
	Texture2D(DXTexture* tex);
	Texture2D(DXTexture* tex, const char* name, const Rect& rect);
	~Texture2D();
	void visit(const Vec2& anchorPoint, const Vec2& pos) const;
	int getWidth() const;
	int getHeight() const;
	const std::string& getName() const;
private:
	DXTexture* m_texture;
	Rect m_rect;
	std::string m_name;
};
#endif