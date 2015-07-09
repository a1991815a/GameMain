#ifndef __HEADERMACRO__
#define __HEADERMACRO__

#define SAFE_DELETE(P) do{if(P) delete P; P = nullptr;} while(0)
#define SAFE_RELEASE(P) do{if(P) P->release(); P = nullptr;} while(0)

#define ABSTRACT 

#define SET_NULL(DATA) memset(&DATA, NULL, sizeof(DATA)) 

#endif