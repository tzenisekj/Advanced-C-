#include <iostream>

#include "BST_Fr_Re.h"
#include "Fr_Re.h"

namespace tz {
	void BST_Fr_Re::insert(Contact& person) {
		if (size() == 0) {
			TreeNode* n = new TreeNode(person); 
			root = n; 
			++t_size; 
		}
		else {
			TreeNode* tracer = root; 
			while (true) {
				if (person.phone_number < tracer->data.phone_number) {
					if (tracer->left == nullptr) {
						TreeNode* n = new TreeNode(person); 
						tracer->left = n; 
						++t_size;
						break; 
					}
					else {
						tracer = tracer->left; 
					}
				}
				else if(person.phone_number > tracer->data.phone_number){
					if (tracer->right == nullptr) {
						TreeNode* n = new TreeNode(person);
						tracer->right = n;
						++t_size;
						break;
					}
					else {
						tracer = tracer->right;
					}
				}
				else {
					break;
				}
			}
		}
	}

	bool BST_Fr_Re::find(int& number) {
		TreeNode* tracer = root; 

		while (tracer != nullptr) {
			if (tracer->data.phone_number != number) {
				if (number < tracer->data.phone_number) {
					tracer = tracer->left; 
				}
				else if (number > tracer->data.phone_number) {
					tracer = tracer->right;
				}
			}
			else {
				return true;
			}
		}
		return false; 
	}

	void BST_Fr_Re::clear() {
		delete_node(root); 
	}

	void BST_Fr_Re::delete_node(TreeNode* node) {
		if (node != nullptr) {
			delete_node(node->left); 
			delete_node(node->right); 
			delete node;
		}
	}

	std::ostream& operator <<(std::ostream& ostr, const BST_Fr_Re& rhs) {
		return rhs.print(ostr, rhs.root); 
	}

	std::ostream& BST_Fr_Re::print(std::ostream& ostr, TreeNode* rhs) const{
		if (rhs != nullptr) {
			print(ostr, rhs->left); 
			std::cout << " " << rhs->data.email << " : " << rhs->data.phone_number << std::endl; 
			print(ostr, rhs->right); 
		}
		return ostr; 
	}
}

using namespace tz;

int main() {
	BST_Fr_Re tree; 

	std::cout << "Program using tree to hold contacts....." << std::endl; 

	std::cout << "\nCreating 3 contacts:" << std::endl; 
	std::cout << "\n1)" << std::endl; 
	std::cout << "\t\tEmail: arnold_ds@gmail.com\n\t\tPhone Number: 7865843265" << std::endl; 
	std::cout << "\n2)" << std::endl;
	std::cout << "\t\tEmail: lizzie@gmail.com\n\t\tPhone Number: 1503695689" << std::endl;
	std::cout << "\n3)" << std::endl;
	std::cout << "\t\tEmail: jesseleamm@yahoo.com\n\t\tPhone Number: 2659863256" << std::endl;

	Contact n1; 
	n1.email = "arnold_ds@gmail.com"; 
	n1.phone_number = 7865843265; 

	Contact n2;
	n1.email = "lizzie@gmail.com";
	n1.phone_number = 1503695689;

	Contact n3;
	n1.email = "jesseleamm@yahoo.com";
	n1.phone_number = 2659863256;


	tree.insert(n1); 
	tree.insert(n2);
	tree.insert(n3);
	tree.insert(n1);

	std::cout << std::endl; 
	std::cout << tree << std::endl; 
	return EXIT_SUCCESS;
}