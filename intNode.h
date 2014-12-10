#ifndef INTNODE_H
#define INTNODE_H

#include "node.h"
#include <sstream>
#include <string>
#include "visitor.h"

class intNode : public Node
{
public:
	intNode(string n)
	{
		//cout << "constructor: " << n << endl;
		stringstream ss;
		ss << n;
		double x;
		ss >> x;
		this->n = x;
	}

	void accept(visitor* v)
	{
		v->visit(this);
	}

	double returnVal()
	{
		return n;
	}

private:
	double n;
};

#endif