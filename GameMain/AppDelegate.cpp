#include "AppDelegate.h"
#include "Director.h"

AppDelegate::AppDelegate()
{

}

AppDelegate::~AppDelegate()
{

}

void AppDelegate::init()
{
	Director::getInstance()->init();
}

Application *const AppDelegate::getCurrentApplication()
{
	return &m_app;
}

void AppDelegate::setDesignStyle(const char* wnd_name, int width, int height, bool fullScreen)
{
	m_app.m_wndName = wnd_name;
	m_app.m_rect.x = 0;
	m_app.m_rect.y = 0;
	m_app.m_rect.width = width;
	m_app.m_rect.height = height;
	m_app.m_isFullScreen = fullScreen;
}
