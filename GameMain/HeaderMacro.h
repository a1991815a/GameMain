#ifndef __HEADERMACRO__
#define __HEADERMACRO__

#define SAFE_DELETE(P) do{if(P) delete P; P = nullptr;} while(0)
#define SAFE_RELEASE(P) do{if(P) P->release();} while(0)

#define ABSTRACT 

#endif