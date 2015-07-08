#include "Win32Utils.h"
#include <stdexcept>

LRESULT CALLBACK GameProc(HWND, UINT, WPARAM, LPARAM);

Win32Utils* Win32Utils::m_instance = nullptr;

Win32Utils::~Win32Utils()
{
	if(g_hWnd != NULL)
		::DestroyWindow(g_hWnd);
}

Win32Utils::Win32Utils()
	:g_hWnd(nullptr), g_hInstance(nullptr)
{

}

Win32Utils* Win32Utils::getInstance()
{
	if(m_instance == nullptr)
		m_instance = new Win32Utils();
	return m_instance;
}

void Win32Utils::init(HINSTANCE hInstance)
{
	g_hInstance = hInstance;
}

HWND Win32Utils::createWindow(const char* wnd_name, int width, int height)
{
	if(g_hWnd != NULL)
		throw std::runtime_error("windows has been created!");
	WNDCLASSEXA wnd_class = { 0 };
	wnd_class.cbSize = sizeof(wnd_class);
	wnd_class.hInstance = g_hInstance;
	wnd_class.lpszClassName = wnd_name;
	wnd_class.style = CS_VREDRAW | CS_HREDRAW | CS_OWNDC;
	wnd_class.lpfnWndProc = GameProc;
	RegisterClassExA(&wnd_class);
	g_hWnd = CreateWindowExA(
		NULL,
		wnd_name,
		wnd_name,
		WS_OVERLAPPEDWINDOW ^ WS_MAXIMIZEBOX,
		CW_USEDEFAULT, CW_USEDEFAULT,
		width, height,
		NULL,
		NULL,
		g_hInstance,
		NULL
		);
	if(g_hWnd == nullptr)
		throw std::runtime_error("window create failure!");
	ShowWindow(g_hWnd, SW_SHOWNORMAL);
	UpdateWindow(g_hWnd);
	return g_hWnd;
}

void Win32Utils::destroyWindow()
{
	destroyInstance();
}

HINSTANCE Win32Utils::getApplicationInstance() const
{
	return g_hInstance;
}

HWND Win32Utils::getWin32Window() const
{
	return g_hWnd;
}

void Win32Utils::destroyInstance()
{
	if(m_instance != nullptr){
		delete m_instance;
		m_instance = nullptr;
	}
}


