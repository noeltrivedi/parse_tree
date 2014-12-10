#ifndef EVAL_H
#define EVAL_H

#include "allNodes.h"
#include "allVisitors.h"
#include <iostream>

class evaluateVisitor : public visitor
{
	virtual void visit(rootNode *n)
	{
		n->first->accept(this);
	}

	virtual void visit(opNode *n)
	{
	//	cout << "opNode: " << n->returnOp() << endl;
		temporary = 0;	
		double left, right;

		if(n->left != NULL)
		{
			n->left->accept(this);
			left = temporary;
		}
		if(n->right != NULL)
		{
			//cout << "IN" << endl;
			n->right->accept(this);
			right = temporary;
			//cout << "Right: " << right << endl;
		}
		char temp = n->returnOp();
		if(temp == '*')
			temporary = left*right;
		if(temp == '+')
			temporary = left + right;
		if(temp == '-')
			temporary = left - right;
		if(temp == '/')
			temporary = left/right;
		

		cout << left << " " << temp << " " << right << " = " << temporary << endl;
	}

	virtual void visit(intNode *n)
	{
		//complete = !complete;
		temporary = n->returnVal();
	}
private:
	char lastOp;
	double temporary;
};

#endif