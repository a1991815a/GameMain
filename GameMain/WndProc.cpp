#include <windows.h>
#include "EventInclude.h"
#include "AppDelegate.h"
extern void GameInit(HWND hWnd);

LRESULT CALLBACK GameProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message){
	case WM_KEYDOWN:
		_dispathMessage->postKeyMessage(EVENT_KEYDOWN, wParam);
		break;
	case WM_KEYUP:
		_dispathMessage->postKeyMessage(EVENT_KEYUP, wParam);
		break;
	case WM_LBUTTONDOWN:
		_dispathMessage->postMouseMessage(EVENT_MOUSEDOWN, LOWORD(lParam), HIWORD(lParam));
		break;
	case WM_LBUTTONUP:
		_dispathMessage->postMouseMessage(EVENT_MOUSEUP, LOWORD(lParam), HIWORD(lParam));
		break;
	case WM_MOUSEMOVE:
		_dispathMessage->postMouseMessage(EVENT_MOUSEMOVE, LOWORD(lParam), HIWORD(lParam));
		break;
	case WM_CREATE:
		AppDelegate::getInstance()->init();
		GameInit(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProcA(hWnd, message, wParam, lParam);
	}
	return 0;
}