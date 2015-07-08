#include "Application.h"
#include "Win32Utils.h"
#include "Director.h"
#include "TimerSystem.h"

Application::Application()
{
	
}

Application::~Application()
{

}

void Application::run()
{
	m_hwnd = _win32Utils->createWindow(m_wndName.c_str(), m_rect.width, m_rect.height);
	if (m_hwnd == NULL)
		return;
	MSG msg = { 0 };
	while (msg.message != WM_QUIT){
		if (PeekMessageA(&msg, NULL, 0, 0, PM_REMOVE)){
			TranslateMessage(&msg);
			DispatchMessageA(&msg);
		}
		else
			if (m_timer.getDelta() >= m_delta)
				Director::getInstance()->mainloop();
		TimerSystem::getInstance()->refresh();
	}
}

void Application::setFrames(int frame)
{
	m_delta = 1000 / frame;
}
