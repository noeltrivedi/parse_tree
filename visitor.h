#ifndef VISITOR_H
#define VISITOR_H

class opNode;
class intNode;
class rootNode;

class visitor
{
public:
	virtual void visit(opNode*) = 0;
	virtual void visit(intNode*) = 0;
	virtual void visit(rootNode*) = 0;

};

#endif