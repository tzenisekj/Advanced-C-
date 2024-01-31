#include <iostream>
//#include <algorithm>
#include "BST.h"
#include "Book.h"

void BST::insert(Book& b) {
	if (root == NULL) {
		BST_Node* n = new BST_Node(b); 
		root = n; 
	}
	else {
		BST_Node* tracer = root; 
		while (true) {
			if (b.get_Author() == tracer->book.front().get_Author()) {
				tracer->book.push_back(b); 
				//sort(tracer->book.begin(), tracer->book.end()); 
				break; 
			}
			else if (b.get_Author() > tracer->book.front().get_Author()) {
				if (tracer->right == NULL) {
					BST_Node* n = new BST_Node(b);
					tracer->right = n;
					break;
				}
				else {
					tracer = tracer->right;
				}
			}
			else {
				if (tracer->left == NULL) {
					BST_Node* n = new BST_Node(b);
					tracer->left = n;
					break;
				}
				else {
					tracer = tracer->left; 
				}
			}
		}
	}
}

void BST::clear() {
	delete_node(root); 
}

void BST::delete_node(BST_Node* node) {
	if (node != NULL) {
		delete_node(node->left); 
		delete_node(node->right); 
		delete node; 
	}
}

bool BST::in_tree(std::string author) const {
	if (root == NULL)
		return false; 
	else {
		BST_Node* tracer = root; 
		while (tracer != NULL) {
			if (author == tracer->book.front().get_Author())
				return true; 
			else if (author > tracer->book.front().get_Author()) {
				if (tracer->right == NULL)
					return false;
				else
					tracer = tracer->right; 
			}
			else {
				if (tracer->left == NULL)
					return false;
				else
					tracer = tracer->left; 
			}
		}
		return false; 
	}
}

std::vector<Book> BST::retriev(std::string author) const{
	BST_Node* tracer = root;
	std::vector<Book> n; 
	while (tracer != NULL) {
		if (author == tracer->book.front().get_Author()) {
			n = tracer->book; 
			break; 
		}
		else if (author > tracer->book.front().get_Author()) {
			if (tracer->right == NULL)
				break; 
			else
				tracer = tracer->right;
		}
		else {
			if (tracer->left == NULL)
				break;
			else
				tracer = tracer->left;
		}
	}
	return n; 
}

int main() {

	return EXIT_SUCCESS;
}