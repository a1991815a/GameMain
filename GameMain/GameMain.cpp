#include "win32.h"
#include <map>
#include "AppDelegate.h"
#include "DirectXUtils.h"

int GameMain(){
	AppDelegate::getInstance()->setDesignStyle("�ҵĲ��Դ���", 800, 600, false);
	AppDelegate::getInstance()->getCurrentApplication()->run();
	return 0;
}

void GameInit(HWND hWnd){
	_directUtils->init(hWnd);
}

void GameDraw(){
	
}

