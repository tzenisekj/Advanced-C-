#ifndef TREE_NODE_H
#define TREE_NODE_H
#include "Fr_Re.h"

namespace tz {
	class TreeNode {
	public:
		Contact data; 
		TreeNode* left; 
		TreeNode* right; 
		TreeNode* parent; 

		TreeNode(Contact data) {
			this->data; 
			left = nullptr; 
			right = nullptr; 
			parent = nullptr; 
		}

	};
}
#endif
