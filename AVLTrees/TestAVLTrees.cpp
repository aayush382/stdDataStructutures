#include <iostream>
#include "AVLTrees.hpp"

using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	class AVLTrees * tree = new AVLTrees();
	tree->add(10);
	tree->add(20);
	tree->add(30);
	tree->add(40);
	tree->add(50);
	tree->add(25);

	cout << endl;
	cout << " pre order traversal" << endl;
	tree->preOrder();

	cout << " In order traversal" << endl;
	cout << endl;
	tree->inOrder();

	class AVLTrees * ntree = new AVLTrees();

	ntree->add(9);ntree->add(5);ntree->add(10);ntree->add(0);ntree->add(6);ntree->add(11);ntree->add(-1);ntree->add(1);ntree->add(2);

	cout << endl;
	cout << " pre order traversal" << endl;
	ntree->preOrder();

	ntree->remove(10);
	cout << endl;
	cout << " pre order traversal" << endl;
	ntree->preOrder();

	cout << endl;
	cout << " In order traversal" << endl;
	ntree->inOrder();
	return 0;
}
