#ifndef __APPLICATION__
#define __APPLICATION__
#include <windows.h>
#include "Rect.h"
#include <string>
#include "Timer.h"

class Application{
	friend class AppDelegate;
public:
	Application();
	~Application();
	void run();
	void setFrames(int frame);
private:
	HWND m_hwnd;
	Rect m_rect;
	std::string m_wndName;
	bool m_isFullScreen;
	Timer m_timer;
	int m_delta;
};
#endif