#ifndef __SPRITE__
#define __SPRITE__
#include "Node.h"
#include "Texture2D.h"

class Sprite: public Node{
protected:
	Sprite();
public:
	static Sprite* create();
	static Sprite* create(Texture2D* texture);
	static Sprite* create(const char* path);
	static Sprite* createByFrame(const char* path);
	virtual void visit() const override;
private:
	Texture2D* m_texture;
};
#endif