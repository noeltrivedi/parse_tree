#ifndef NODE_H
#define NODE_H

#include "visitor.h"
#include <iostream>

using namespace std;

class Node
{
public:
	Node()
	{
		left = right = parent = NULL;
	}
	virtual void accept(visitor*) = 0;

	virtual bool isInt()
	{
		return left == NULL && right == NULL;
	}

	Node* left;
	Node* right;
	Node* parent;

};

#endif