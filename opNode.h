#ifndef OPNODE_H
#define OPNODE_H

#include "node.h"
#include "visitor.h"

class opNode : public Node
{
public:
	opNode(char op)
	{
		this->op = op;
	}

	opNode()
	{
		op = 'R';
	}

	virtual void accept(visitor* v)
	{
		v->visit(this);
	}

	char returnOp()
	{
		return op;
	}

private:
	char op;
};

#endif