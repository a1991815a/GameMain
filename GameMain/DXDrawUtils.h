#ifndef __DXDRAWUTILS__
#define __DXDRAWUTILS__
#include "SingleInstance.h"
#include "Texture2D.h"

#define _dxDrawUtils DXDrawUtils::getInstance()

class DXDrawUtils: public SingleInstance<DXDrawUtils>{
	DEFINE_INSTANCE_PRIVATE(DXDrawUtils);
public:
	void drawImage(Texture2D* texture, const Vec2& pos, const Vec2& anchorPoint);
	void drawText(const std::string& text);
private:
	
};
#endif