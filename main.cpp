#include <iostream>
#include <cstdlib>

#include "bst.cpp"

using namespace std;

int main () {
	int KeyColors[8] = {1, 1, 0, 0, 1, 0, 0, 1,};
	int TreeKeys[8] = {11, 10, 9, 28, 18, 15, 20, 30};
	int last = 22;

	BST tree(3);
	cout << "Printing the tree in order: " << endl;
	tree.printInOrder();

	for (int i = 0; i < 8; i++) {
		tree.insert(tree.createNode(TreeKeys[i], KeyColors[i]));
	}

	cout << "Printing the tree in order: " << endl;
	tree.printInOrder();
	cout << "\n" << endl;

	BST::tree_node* n = tree.returnNode(18);
	cout << "Node 18  " << "Data: " << n->data << " Color: " << n->color << endl;
	cout << "Parent: " << n->parent->data << " Color: " << n->color << endl;

	BST::tree_node* sib = tree.sibling(n);
	cout << "Sibling of 18 is: " << sib->data << " Color: " << sib->color <<  endl;
	// cout << "Sibling of 18 is: " << n->parent->left->data << " Color: " << n->parent->left->color <<  endl;
	BST::tree_node* gran = tree.grandparent(n);
	cout << "GrandParent of 18 is: " << gran->data << " Color: " << gran->color << endl;
	BST::tree_node* unc = tree.uncle(n);
	cout << "Uncle of 18 is: " << unc->data << " Color: " << unc->color << endl;
	cout << "Parent of 18 is:"  << n->parent->data << " Color: " << n->parent->color << endl;
	tree.verify_properties();

	cout << "Inserting: " << 0 << ": " << 22 << endl;
	tree.insert(tree.createNode(22, 0));
	tree.printInOrder();
	BST::tree_node* lastNode = tree.returnNode(20);

	cout << "Parent of 20 is: "  << lastNode->parent->data << 
			" Color: " << lastNode->parent->color << endl;
	cout << "GrandParent of 20 is: "  << lastNode->parent->parent->data << 
		" Color: " << lastNode->parent->parent->color << endl;
	cout << "Child of 20 is: "  << lastNode->right->data << 
		" Color: " << lastNode->right->color << endl;





	return 0;
}