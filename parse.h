#ifndef PARSE_TREE
#define PARSE_TREE

#include <string>
#include <list>
#include <sstream>

#include "allNodes.h"
#include "allVisitors.h"

using namespace std;

class parseTree
{
public:
	parseTree(string expression)
	{
		root = new rootNode;
		prevOp = NULL;
		stringstream ss(expression);
		readInput(ss);
	}




	void accept(visitor* v)
	{
		//cout << "Root" << endl;
		//acceptHelper(root, v);
		root->first->accept(v);
	}

protected:
	rootNode *root;
		//the root node
			//points to a single opNode
	Node *intHolder;
	opNode *prevOp;
	bool parenOpen;

	void acceptHelper(Node* n, visitor* v)
	{
		if(n != NULL)
		{
			acceptHelper(n->left, v);
			n->accept(v);
			acceptHelper(n->right, v);
		}
	}

	void readInput(stringstream &ss)
	{
		string temp;
		while(!ss.eof())
		{
			ss >> temp;
			if(temp == "*" || temp == "/" || temp == "-" || temp == "+")
			{
				//operator
				Node* newOp = new opNode(temp[0]);
				add( (opNode*) newOp);
			}
			else if (temp == "(")
			{
				//cout << "found (" << endl;
				readParen(ss);			

			}
			else if (true)
			{
				//cout << "Creating intNode with " << temp << endl;
				Node* newInt = new intNode(temp);
				add(  (intNode*) newInt);
				
			}
		}
	}

	void readParen(stringstream &ss)
	{
		string temp;
		string parantheses;
		ss >> temp;
		int parenCount = 1;
		while(parenCount != 0)
		{		
			
			
			if( temp == ")")
			{
				parenCount--;
				if(parenCount != 0)
				{
					ss >> temp;
				}
			}
			else
			{
				parantheses += " " ;
				parantheses += temp;
				ss >> temp;
			}
				
			
		}

		
		parseTree internalTree(parantheses);
		//evaluateVisitor *output = new evaluateVisitor;
		//internalTree.accept(output);

		if(prevOp == NULL)
		{
			//this means no operator has been added yet
			this->root->first = internalTree.root;
			prevOp = root->first;
		}	
		else
		{
			if(prevOp->right == NULL)
			{
				prevOp->right = (opNode*) internalTree.root;
				prevOp->right->parent = prevOp;
			}
			else if(prevOp->left == NULL)
			{
				prevOp->left = (opNode*) internalTree.root;
				prevOp->left->parent = prevOp;
			}
		}
	}

	void add(opNode *n)
	{

		if(prevOp == NULL)
		{
			//no operation has been loaded in yet
			//let this operation become the root

			prevOp =  n;
			prevOp->left = intHolder;
			//intHolder =NULL;

			root->first = prevOp;
		}
		else
		{
			//an op exists
			//we should set this op as its parent
			root->first->parent = n;
			n->left = root->first;
				//unlinks the root's child from the root and attaches it to n
			root->first = n;
			n->parent = root;
				//attaches the node n to the root

			//n->parent = root;
			//add the previous operator to this one as a child

			if( !(n->returnOp() == '+' || n->returnOp() == '-')	)
			{
				while(prevOp->returnOp() == '+' || prevOp->returnOp() == '-') 
				{

					//cout << n << endl;
					//need to swap
					Node* oldRight = prevOp->right;

					n->left = oldRight;
					oldRight->parent = n;
					n->right = NULL;

					prevOp->parent = NULL;

					prevOp->right = n;
					n->parent = prevOp;
					
					root->first = prevOp;
					prevOp = n;
				}
			}

			prevOp = n;
		}
	}

	void add(intNode *i)
	{
		//cout << "Adding Node... ";
		if(prevOp == NULL)
		{	
			//cout << "Happens once" << endl;
			//root->left = new internalNode(i);
			intHolder = i;
			//cout << "Success!" << endl;
		}
		else
		{
			//there is an op
			if(prevOp->right == NULL)
			{
				prevOp->right = i;
				i->parent = prevOp;
				prevOp = (opNode*) root->first;
			//	cout << "Success!" << endl;
			}
		}
	}
};

#endif