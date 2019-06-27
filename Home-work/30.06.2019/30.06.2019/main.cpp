#include "Tree.h"
#include <iostream>
using namespace std;

int main()
{
	Tree tree;
	tree.Add("DA2342DE","qwee ew qeq efdfgd\nwq eq ");
	tree.Add("CL2342DE", "qwee ew qeq \newq eq ");
	tree.Add("QW2342DE", "qwee ew qeq \newq eq ");
	tree.Add("AS2342DE", "qwe\ne ew qeq ewq eq ");
	tree.Add("FG2342DE", "qwee e\nw qeq ewq e\n\nq ");
	tree.Add("IO2342DE", "qwee \new qeq e\nwq eq ");


	tree.PrintSort();
	cout << "-------------------\n";


	system("pause");
	return 0;
}