#include "win32.h"
#include <map>
#include "AppDelegate.h"
#include "DirectXUtils.h"
#include "EventInclude.h"
#include "TextureManager.h"
DXTexture* dx_tex = nullptr;

int x = 50, y = 50;

int GameMain(){
	AppDelegate::getInstance()->setDesignStyle("ÎÒµÄ²âÊÔ´°¿Ú", 800, 600, false);
	AppDelegate::getInstance()->getCurrentApplication()->run();
	return 0;
}

void GameInit(HWND hWnd){
	
 	_directUtils->init(hWnd);
	KeyEventListener* listener = new KeyEventListener();
	_dispathMessage->addListener(listener);
	listener->OnKeyDown = [](Event* event)->bool{
		switch (event->getKey())
		{
		case 'W':
			y-=2;
			break;
		case 'S':
			y+=2;
			break;
		case 'A':
			x-=2;
			break;
		case 'D':
			x+=2;
			break;
		default:
			break;
		}
		return true;
	};
	_textureManager->loadImage("Vehicle.png", 9, 12);
}

void GameDraw(){
	Texture2D* t2d = _textureManager->getTexture("Vehicle_1.png");
	t2d->visit(Vec2(0, 0), Vec2(x, y));
	t2d->visit(Vec2(t2d->getWidth(), t2d->getHeight()), Vec2(50, 50));
}

