#include "win32.h"
#include <map>
#include "AppDelegate.h"
#include "DirectXUtils.h"
#include "EventInclude.h"
int GameMain(){
	AppDelegate::getInstance()->setDesignStyle("我的测试窗口", 800, 600, false);
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
			OutputDebugStringA("输入:W \n");
			break;
		case 'S':
			OutputDebugStringA("输入:S \n");
			break;
		case 'A':
			OutputDebugStringA("输入:A \n");
			break;
		case 'D':
			OutputDebugStringA("输入:D \n");
			break;
		default:
			break;
		}
		return true;
	};
	_textureManager->loadImage("Vehicle.png", 9, 12);
}

void GameDraw(){
	_textureManager->getTexture("Vehicle.png")->visit(Vec2(0, 0),Vec2(50, 50));
}

