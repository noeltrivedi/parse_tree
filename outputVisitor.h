#ifndef OUTPUT_H
#define OUTPUT_H

#include "visitor.h"
#include "opNode.h"
#include "intNode.h"
#include "rootNode.h"

class outputVisitor : public visitor
{
	virtual void visit(rootNode *n)
	{
		cout << "( ";
		n->first->accept(this);
		cout << ") ";
	}
	virtual void visit(opNode *n)
	{
		if(n != NULL)
		{
			n->left->accept(this);
			cout << n->returnOp() << " ";
			n->right->accept(this);
		}
	}
	virtual void visit(intNode *n)
	{
		//cout << "RAN" << endl;
		cout << n->returnVal()  << " " ;
	
	};

};

#endif