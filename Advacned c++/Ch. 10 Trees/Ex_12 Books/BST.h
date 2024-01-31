#include <vector>
#include "Book.h"

#ifndef BST_H
#define BST_H

class BST {
private:
	struct BST_Node {
		std::vector<Book> book; 
		BST_Node* left; 
		BST_Node* right; 

		BST_Node(Book& b) {
			book.push_back(b); 
			left = NULL; 
			right = NULL;
		}
	};

	BST_Node* root; 
 
	void delete_node(BST_Node* node); 

public:
	BST() { root = NULL; }
	~BST() { clear(); }

	void insert(Book& b); 
	void clear(); 
	
	std::vector<Book> retriev(std::string author) const; 

	bool in_tree(std::string author) const; 

};
#endif
