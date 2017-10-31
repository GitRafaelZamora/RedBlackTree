#include <iostream>
#include <cstdlib>
#include <cassert>
#include <string>


#include "rbtree.h"
#include "file.h"

using namespace std;


// Constructor
BST::BST(int i) {
	this->root = NULL;
}

string BST::RBWrite(tree_node* Pointer, string str) {
	if (Pointer != NULL) {
		str = to_string(Pointer->color) + ": " + to_string(Pointer->data) + "\n";
		if (Pointer->left != NULL) {
			str += RBWrite(Pointer->left, str);
		}
		// cout << Pointer->color << ": " << Pointer->data << endl;
		if (Pointer->right != NULL) {
			str += RBWrite(Pointer->right, str);
		}
	}
    return str;
}

BST::tree_node* BST::createNode(int data, int color) {
	tree_node* n = new tree_node;
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	n->parent = NULL;
	n->color = color;
	return n;
}

BST::tree_node* BST::getRoot() {
    return this->root;
}

//************ FAMILY FUNCTIONS ***************//
BST::tree_node* BST::grandparent(tree_node* n) {
    // if (n != NULL && n->parent != NULL && n->parent->parent != NULL) {
    // 	return n->parent->parent;
    // } else {
    // 	return NULL;
    // }

    assert (n != NULL);
    assert (n->parent != NULL);
    assert (n->parent->parent != NULL);
    return n->parent->parent;
}

BST::tree_node* BST::sibling(tree_node* n) {
	if (n != NULL && n->parent != NULL) {
		if (n == n->parent->left) {
			return n->parent->right;
		} else {
			return n->parent->left;
		}
	} else {
		return NULL;
	}
}

BST::tree_node* BST::uncle(tree_node* n) {
    // if (n != NULL && n->parent != NULL && n->parent->parent != NULL) {
    // 	return sibling(n->parent);
    // } else {
    // 	return NULL;
    // }
    assert (n != NULL);
    assert (n->parent != NULL);
    assert (n->parent->parent != NULL);
    return sibling(n->parent);
}
//************ END FAMILY FUNCTIONS ***************//

int BST::node_color(tree_node* n) {
	return n == NULL ? 1 : n->color;
}

//************ PROPERTIES FUNCTIONS ***************//
void BST::verify_properties() {
    verify_property_1 (this->root);
    verify_property_2 (this->root);
    verify_property_4 (this->root);
    verify_property_5 (this->root);
}

void BST::verify_property_1(tree_node* n)
{
    assert (node_color(n) == 0 || node_color(n) == 1);
    if (n == NULL)
        return;
    verify_property_1(n->left);
    verify_property_1(n->right);
}

void BST::verify_property_2(tree_node* n) {
    assert (node_color(n) == 1);
}

void BST::verify_property_4(tree_node* n) {
    if (node_color(n) == 0)
    {
        assert(node_color(n->left) == 1);
        assert(node_color(n->right) == 1);
        assert(node_color(n->parent) == 1);
    }
    if (n == NULL)
        return;
    verify_property_4(n->left);
    verify_property_4(n->right);
}

void BST::verify_property_5(tree_node* n) {
	int black_height = -1;
	verify_property_5_helper(n, 0, &black_height);
}

void BST::verify_property_5_helper(tree_node* n, int black_height, int* path_count) {
	if (node_color(n) == 1) {
		black_height++;
	}
	if (n == NULL) {
		if (*path_count == -1) {
			*path_count = black_height;
		} else {
			assert(black_height == *path_count);
		}
		return;
	}
	verify_property_5_helper(n->left, black_height, path_count);
	verify_property_5_helper(n->right, black_height, path_count);
}

//************ END PROPERTIES FUNCTIONS ***************//

//************ ROTATION FUNCTIONS ***************//
void BST::rotate_left(tree_node* n)
{
    tree_node* r = n->right;
    replace_node(n, r);
    n->right = r->left;
    if (r->left != NULL)
    {
        r->left->parent = n;
    }
    r->left = n;
    n->parent = r;
}

void BST::rotate_right(tree_node* n)
{
    tree_node* L = n->left;
    replace_node(n, L);
    n->left = L->right;
    if (L->right != NULL) {
        L->right->parent = n;
    }
    L->right = n;
    n->parent = L;
}

void BST::replace_node(tree_node* oldn, tree_node* newn)
{
    if (oldn->parent == NULL) {
        this->root = newn;
    } else {
        if (oldn == oldn->parent->left) {
            oldn->parent->left = newn;
        } else {
            oldn->parent->right = newn;
        }
    }
    if (newn != NULL) {
        newn->parent = oldn->parent;
    }
}
//************************************ END ROTATION FUNCTIONS ************************************************//

//************ INSERT CASE FUNCTIONS ***************//
void BST::RBInsert(tree_node* newNode) {
	insertPrivate(newNode, this->root);
}

void BST::insertPrivate(tree_node* newNode, tree_node* Pointer) {
	if (this->root == NULL) {
		this->root = newNode;
		// this->root->color = 1;
		// this->root->parent = NULL;
	} else {
		// Traverse Left side;
		if (newNode->data < Pointer->data) {
			if (Pointer->left != NULL) {
				insertPrivate(newNode, Pointer->left);
			} else {
				Pointer->left = newNode;
				newNode->parent = Pointer;
			}
		} else if (newNode->data > Pointer->data) {
			if (Pointer->right != NULL) {
				insertPrivate(newNode, Pointer->right);
			} else {
				Pointer->right = newNode;
				newNode->parent = Pointer;
			}
		} else if (newNode->data == Pointer->data) {
			cout << "SAME NODE" << endl;
		}
		
	}

	if (node_color(newNode->parent) == 0 && newNode->color == 0) {
		insert_case_1(newNode);
		verify_properties();
	}
	
}

void BST::insert_case_1(tree_node* n) {
    if (n->parent == NULL) {
        n->color = 1;
    } else {
    	insert_case_2(n);
    }
}

void BST::insert_case_2(tree_node* n) {
    if (node_color(n->parent) == 1) {
		return;
    } else {
        insert_case_3(n);
    }
}

void BST::insert_case_3(tree_node* n) {
	if (node_color(uncle(n)) == 0) {
        n->parent->color = 1;
        uncle(n)->color = 1;
        grandparent(n)->color = 0;
        insert_case_1(grandparent(n));
    } else {
        insert_case_4(n);
    }

}

void BST::insert_case_4(tree_node* n) {
	if (n == n->parent->right && n->parent == grandparent(n)->left) {
        rotate_left(n->parent);
        n = n->left;
    } else if (n == n->parent->left && n->parent == grandparent(n)->right) {
        rotate_right(n->parent);
        n = n->right;
    }
    insert_case_5(n);
}

void BST::insert_case_5(tree_node* n) {
    n->parent->color = 1;
    grandparent(n)->color = 0;
    if (n == n->parent->left && n->parent == grandparent(n)->left) {
        rotate_right(grandparent(n));
    } else {
        assert (n == n->parent->right && n->parent == grandparent(n)->right);
        rotate_left(grandparent(n));
    }
}


//************ END INSERT CASE FUNCTIONS ***************//
BST::tree_node* BST::returnNodePrivate(int data, tree_node* Pointer) {
	if (Pointer != NULL) {
		if (Pointer-> data == data) {
			return Pointer;
		} else if (data < Pointer->data) {
			return returnNodePrivate(data, Pointer->left);
		} else {
			return returnNodePrivate(data, Pointer->right);
		}
	} else {
		return NULL;
	}
	return NULL;
}

BST::tree_node* BST::returnNode(int data) {
	return returnNodePrivate(data, root);
}