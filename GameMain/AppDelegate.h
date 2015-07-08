#ifndef __APPDELEGATE__
#define __APPDELEGATE__
#include "SingleInstance.h"
#include "Application.h"

class AppDelegate: public SingleInstance<AppDelegate>{
	DEFINE_INSTANCE_PRIVATE(AppDelegate);
public:
	void init();
	Application* const getCurrentApplication();
	void setDesignStyle(const char* wnd_name, int width, int height, bool fullScreen);
private:
	Application m_app;
};
#endif