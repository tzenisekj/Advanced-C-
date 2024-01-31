#ifndef EXP_TREE_H
#define EXP_TREE_H

namespace tz {
	template<class Item>
	class exp_tree {
	private:
		struct tree_node {
			Item data;
			tree_node* left;
			tree_node* right;
			tree_node* parent;

			tree_node(Item entry) {
				data = entry;
				left = NULL;
				right = NULL;
				parent = NULL;
			}
		};

		tree_node* root;
		tree_node* cursor;
		size_t t_size;

	public:
		exp_tree();
		void expression_build(const std::string expression); 
		void test_build_validation(char character); 
		int evaluate(tree_node* tracer); 
		void shift_up();
		void shift_left();
		void shift_right();
		void change(const Item& new_entry);
		void add_left(const Item& entry);
		void add_right(const Item& entry);

		tree_node* start() const { return root; }
		size_t size() const { return t_size; }
		Item retrieve() const { return cursor->data; }
		bool has_parent() const { return (cursor->parent != NULL); }
		bool has_left_child() const { return (cursor->left != NULL); }
		bool has_right_child() const { return (cursor->right != NULL); }

	};
}
#endif
