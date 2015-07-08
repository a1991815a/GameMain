#ifndef __WIN32UTILS__
#define __WIN32UTILS__
#include <windows.h>

int GameMain();											//必须重写
LRESULT CALLBACK GameProc(HWND, UINT, WPARAM, LPARAM);	//必须重写

#define _win32Utils Win32Utils::getInstance()

class Win32Utils{
	Win32Utils();
	~Win32Utils();
public:
	static Win32Utils* getInstance();
public:
	void init(HINSTANCE hInstance);
	HWND createWindow(const char* wnd_name, int width, int height);
	void destroyWindow();
	HINSTANCE getApplicationInstance() const;
	HWND getWin32Window() const;
private:
	static void destroyInstance();
	HWND g_hWnd;
	HINSTANCE g_hInstance;
	static Win32Utils* m_instance;
};
#endif