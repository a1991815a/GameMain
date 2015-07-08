#ifndef __DIRECTOR__
#define __DIRECTOR__
#include "SingleInstance.h"

class Director: public SingleInstance<Director>{
	DEFINE_INSTANCE_PRIVATE(Director);
public:
	void init();
	void mainloop();
private:
	
};
#endif