#include <iostream>
#include <cstdlib>

#include "B_Tree.h"

namespace tz {
	template<class Item>
	b_tree<Item>::b_tree() {
		root = NULL; 
		cursor = NULL; 
		t_size = 0; 
	}

	template<class Item>
	void b_tree<Item>::create_first_node(const Item& entry) {
		tree_node* n = new tree_node(entry); 
		root = n; 
		cursor = root; 
		++t_size; 
	}

	template<class Item>
	void b_tree<Item>::shift_left() {
		if (has_left_child()) {
			cursor = cursor->left;
		}
		else
			return; 
	}

	template<class Item>
	void b_tree<Item>::shift_right() {
		if (has_right_child()) {
			cursor = cursor->right;
		}
		else
			return; 
	}

	template<class Item>
	void b_tree<Item>::shift_root() {
		if (size() > 0)
			cursor = root;
		else
			return; 
	}

	template<class Item>
	void b_tree<Item>::shift_up() {
		if (has_parent()) {
			cursor = cursor->parent;
		}
		else
			return; 
	}

	template<class Item>
	void b_tree<Item>::change(const Item& new_entry) {
		if (size() > 0)
			cursor->data = new_entry;
		else
			return; 
	}

	template<class Item>
	void b_tree<Item>::add_left(const Item& entry) {
		if (size() > 0 && !has_left_child()) {
			tree_node* n = new tree_node(entry);
			cursor->left = n;
			++t_size; 
		}
		else
			return; 
	}

	template<class Item>
	void b_tree<Item>::add_right(const Item& entry) {
		if (size() > 0 && !has_right_child()) {
			tree_node* n = new tree_node(entry);
			cursor->right = n;
			++t_size;
		}
		else
			return; 
	}
}