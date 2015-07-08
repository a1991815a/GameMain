#include <windows.h>
extern void GameInit(HWND hWnd);

LRESULT CALLBACK GameProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message){
	case WM_CREATE:
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