#include "Director.h"
#include "DirectXUtils.h"

Director::Director()
{

}

Director::~Director()
{

}

void Director::mainloop()
{
	_directUtils->render();
}
