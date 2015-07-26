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

	tree->preOrder();
	tree->inOrder();

	return 0;
}
