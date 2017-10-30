class BST {
public:
	struct tree_node {
		int data;
		int color;
		tree_node* left;
		tree_node* right;
		tree_node* parent;
	};
private:
	

	tree_node* root;

	void insertPrivate(tree_node* newNode, tree_node* Pointer);
	void printInOrderPrivate(tree_node* Pointer);
	tree_node* returnNodePrivate(int data, tree_node* Pointer);


public: 
	BST(int i);
	void printInOrder();
	tree_node* createNode(int data, int color);

	//**** FAMILY FUNCTIONS ****//
	tree_node* sibling(tree_node* n);
	tree_node* grandparent(tree_node* n);
	tree_node* uncle(tree_node* n);
	//**** END FAMILY FUNCTIONS ****//

	int node_color(tree_node* n);

	//**** PROPERTIES FUNCTIONS ****//
	void verify_properties();
	void verify_property_1(tree_node* n);
	void verify_property_2(tree_node* n);
	void verify_property_4(tree_node* n);
	void verify_property_5(tree_node* n);
	void verify_property_5_helper(tree_node* n, int black_height, int* path_count);
	// void verify_property_4(tree_node* n);
	//**** END PROPERTIES FUNCTIONS ****//

	//**** INSERT CASE FUNCTIONS ****//
	void insert(tree_node* newNode);
	void insert_case_1(tree_node* n);
	void insert_case_2(tree_node* n);
	void insert_case_3(tree_node* n);
	void insert_case_4(tree_node* n);
	void insert_case_5(tree_node* n);
	void rotate_left(tree_node* n);
	void rotate_right(tree_node* n);
	void replace_node(tree_node* oldn, tree_node* newn);

	//**** END INSERT CASE FUNCTIONS ****//

	tree_node* returnNode(int data);
};



/*
	1. Every node is either red or black.
	2. The root node is black.
	3. Every leaf (NULL) is black.
	4. If a node is red, then both its children are black.
	5. Every simple path from a node to a descendant leaf contains the same number of black nodes.
*/