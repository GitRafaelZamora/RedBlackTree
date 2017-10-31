#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>

#include "rbtree.cpp"
#include "file.cpp"

using namespace std;

int main (int argc, char *argv[]) {
	BST tree(2);
	File inFile(argv[1], "in");

	int numberOfRBNodes = inFile.getNumberOfNodes();

	int color;
	int data;
	string line;
	for (int i = 0; i < numberOfRBNodes; i++) {
		line = inFile.getLine();
		color = stoi(line.substr(0,1));
		data = stoi(line.substr(1,3));
		tree.RBInsert(tree.createNode(data, color));
	}

	int numberOfRegularNodes = stoi(inFile.getLine());

	for (int i = 0; i < numberOfRegularNodes; i++) {
		tree.RBInsert(tree.createNode(stoi(inFile.getLine()), 0));
	}
	inFile.close();

	File outFile("../out/output.txt", "out");
	outFile.write(tree.RBWrite(tree.getRoot(), " "));
	outFile.close();

	BST::tree_node* n11 = tree.returnNode(11);
	BST::tree_node* n10 = tree.returnNode(10);
	BST::tree_node* n9 = tree.returnNode(9);
	BST::tree_node* n28 = tree.returnNode(28);
	BST::tree_node* n18 = tree.returnNode(18);
	BST::tree_node* n15 = tree.returnNode(15);
	BST::tree_node* n20 = tree.returnNode(20);
	BST::tree_node* n30 = tree.returnNode(30);

	cout << "Node: " << n11->data << " L: " << n11->left->data << " P: " << n11->parent->data << " R: " << n11->right->data << endl;
	cout << "Node: " << n10->data << " L: " << n10->left->data << " P: " << n10->parent->data << " R: NULL" << endl;
	cout << "Node: " << n9->data << " L: NULL" << " P: " << n9->parent->data << " R: NULL" << endl;
	cout << "Node: " << n28->data << " L: " << n28->left->data << " P: " << n28->parent->data << " R: " << n28->right->data << endl;
	cout << "Node: " << n18->data << " L: " << n18->left->data << " P: NULL" << " R: " << n18->right->data << endl;
	cout << "Node: " << n15->data << " L: NULL" << " P: " << n15->parent->data << " R: NULL" << endl;
	cout << "Node: " <<  n20->data << " L: NULL" << " P: " << n20->parent->data << " R: " << n20->right->data << endl;
	cout << "Node: " <<  n30->data << " L: NULL"  << " P: " << n30->parent->data << " R: NULL" << endl;





	return 0;
}