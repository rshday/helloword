
#include "pch.h"
#include <iostream>

using namespace std;

void root(map<int, string> *tree)
{
	int i = 1;
	if (tree->size() == 0)
		tree->insert(make_pair(i, "root"));
	else
	{
		if (tree->size() < 5)
		{
			tree->insert(make_pair(tree->size() + i, "node"));
			
		}
		else
		{
			return;
		}
	}
	
	cout << tree->find(tree->size())->second<<endl;
	root(tree);
}


int main()
{
	map<int, string> tree;
	root(&tree);

	cout << tree.size() << endl;
}

