#include <iostream>
#include <string>
#include "parse.h"
#include "allVisitors.h"

using namespace std;

int main()
{
	string expression;
	cout << "Please enter an expression. Separate each term and operator with a space.\n";
	getline(cin, expression);
	parseTree myTree(expression);

	outputVisitor *myVisitor = new outputVisitor;
	evaluateVisitor *eval = new evaluateVisitor;


	cout << "\nYour expression:\n";
	myTree.accept(myVisitor);
	cout << endl;
	cout << "\nWork to Solve:\n";
	myTree.accept(eval);


}