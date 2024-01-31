#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>

#include "ExpTree.h"

namespace tz {

	template<class Item>
	exp_tree<Item>::exp_tree() {
		root = NULL;
		cursor = NULL;
		t_size = 0;
	}

	template<class Item>
	void exp_tree<Item>::shift_left() {
		if (!isdigit(cursor->data)) {
			if (has_left_child()) {
				cursor = cursor->left;
			}
			else
				return;
		}
		else
			return; 
	}

	template<class Item>
	void exp_tree<Item>::shift_right() {
		if (!isdigit(cursor->data)) {
			if (has_right_child()) {
				cursor = cursor->right;
			}
			else
				return;
		}
		else
			return; 
	}

	template<class Item>
	void exp_tree<Item>::shift_up() {
		if (has_parent()) {
			cursor = cursor->parent;
		}
		else
			return;
	}

	template<class Item>
	void exp_tree<Item>::change(const Item& new_entry) {
		if (size() > 0)
			cursor->data = new_entry;
		else
			return;
	}

	template<class Item>
	void exp_tree<Item>::add_left(const Item& entry) {
		if (size() > 0 && !has_left_child() && !isdigit(cursor->data)) {
			tree_node* n = new tree_node(entry);
			cursor->left = n;
			++t_size;
		}
		else
			return;
	}

	template<class Item>
	void exp_tree<Item>::add_right(const Item& entry) {
		if (size() > 0 && !has_right_child() && !isdigit(cursor->data)) {
			tree_node* n = new tree_node(entry);
			cursor->right = n;
			++t_size;
		}
		else
			return;
	}

	template<class Item>
	void exp_tree<Item>::expression_build(const std::string expression) {
		for (unsigned int i = 0; i < expression.size(); ++i) {
			if (isdigit(expression[i]) || expression[i] == '*' || expression[i] == '+') {
					test_build_validation(expression[i]); 
			}
		}
	}

	template<class Item>
	void exp_tree<Item>::test_build_validation(char character) {
		if (size() == 0) {
			tree_node* n = new tree_node(character); // creates first node
			root = n;
			++t_size; 
			cursor = n;
		}
		else {
			if (!has_left_child() && character == '*' || character == '+') {
				add_left(character);											// create left node of parent
				shift_left();													// shift to node of non leaf
			}	
			else if (!has_left_child() && isdigit(character)) {
				add_left(character);										// create left node of parent 
			}
			else if (!has_right_child() && character == '*' || character == '+') {
				add_right(character);											// creates right node of parent if left is created
				shift_right();													// shifts to node of non leaf
			}
			else if (!has_right_child() && isdigit(character)) {
				add_right(character);										// create right node of parent
			}
			else if (has_right_child() && has_left_child()) {
				shift_up();														// parent already has children
				test_build_validation(character);								// shift up as needed
			}																	// recursively calls itself
		}
	}

	template<class Item>
	int exp_tree<Item>::evaluate(tree_node* root) {
		// empty tree  
		if (!root)
			return 0;

		// leaf node i.e, an integer  
		if (!root->left && !root->right)
			return (int)root->data;

		// Evaluate left subtree  
		int l_val = evaluate(root->left);

		// Evaluate right subtree  
		int r_val = evaluate(root->right);

		// Check which operator to apply  
		if (root->data == '+')
			return l_val + r_val;

		if (root->data == '*')
			return l_val * r_val;

		return (int)root->data; 
	}
} 

using namespace tz; 

int main() {
	std::string input; 
	exp_tree<char> tree; 

	std::cout << "Program to evaluate post fix expressions!" << std::endl;
	std::cout << "\n";

	std::cout << "Input expression (prefix notation): "; 
	std::getline(std::cin, input); 
	tree.expression_build(input); 
	std::cout << "\n";
	std::cout << input << " = " << tree.evaluate(tree.start()) << std::endl;
	return EXIT_SUCCESS; 
}