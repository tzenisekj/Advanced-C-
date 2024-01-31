#ifndef BST_FR_RE_H
#define BST_FR_RE_H

#include "TreeNode.h"

namespace tz {
	class BST_Fr_Re {
	private:
		TreeNode* root;
		size_t t_size; 

		void delete_node(TreeNode* node); 
		std::ostream& print(std::ostream& ostr, TreeNode* rhs) const; 

	public:
		BST_Fr_Re() {
			root = nullptr;
			t_size = 0; 
		}

		~BST_Fr_Re() {
			clear();
		}

		void clear();
		void insert(Contact& person);
		bool find(int& number); 

		size_t size() const { return t_size; }
		friend std::ostream& operator <<(std::ostream& ostr, const BST_Fr_Re& rhs); 

	};
}
#endif