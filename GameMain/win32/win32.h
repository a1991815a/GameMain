#ifndef __WIN32__
#define __WIN32__
#include "Win32Utils.h"

int WINAPI WinMain( 
	__in HINSTANCE hInstance, 
	__in_opt HINSTANCE hPrevInstance,
	__in LPSTR lpCmdLine,
	__in int nShowCmd )
{
	_win32Utils->init(hInstance);
	return GameMain();
}

#endif