#ifndef __LAYER__
#define __LAYER__
#include "Node.h"
#include "HeaderMacro.h"

class Layer: public Node{
public:
	CREATE_FUNC(Layer);
	bool init();

	virtual void visit() const override;

};
#endif