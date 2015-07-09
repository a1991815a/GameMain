#include "win32.h"
#include <map>
#include "AppDelegate.h"
#include "DirectXUtils.h"
#include "EventInclude.h"
int GameMain(){
	AppDelegate::getInstance()->setDesignStyle("�ҵĲ��Դ���", 800, 600, false);
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
			OutputDebugStringA("����:W \n");
			break;
		case 'S':
			OutputDebugStringA("����:S \n");
			break;
		case 'A':
			OutputDebugStringA("����:A \n");
			break;
		case 'D':
			OutputDebugStringA("����:D \n");
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

