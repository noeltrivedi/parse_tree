#ifndef ROOTNODE_H
#define ROOTNODE_H

#include "node.h"
#include "visitor.h"

class rootNode : public opNode
{
public:
	rootNode()
	{
		
	}

	virtual void accept(visitor* v)
	{
		v->visit(this);
	}

	opNode* first;

};

#endif