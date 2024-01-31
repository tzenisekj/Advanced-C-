#include <cassert>
#include <iostream>
#include "Dynaic_Stack.h"

template<class T>
d_stack<T>::d_stack() {
	head_ptr = NULL; 
	current = NULL; 
	previous = NULL; 
	counter = 0; 
}

template<class T>
d_stack<T>::~d_stack() {
	clear(); 
}

template<class T>
void d_stack<T>::push(T entry) {
	Node* n = new Node;
	n->set_data(entry);
	n->set_link(head_ptr);
	head_ptr = n; 
	++counter; 
}

template<class T>
T d_stack<T>::top() const {
	return head_ptr->data();
}

template<class T>
void d_stack<T>::pop() {
	if (is_empty()) return;
	else {
		current = head_ptr; 
		head_ptr = head_ptr->link(); 
		delete current; 
		--counter; 
	}
}

template<class T>
void d_stack<T>::clear() {
	if (is_empty()) return;
	else {
		while (!is_empty()) {
			current = head_ptr;
			while (current != NULL) {
				previous = current;
				current = current->link();
			}
			previous->set_link(NULL);
			delete current;
			--counter;
		}
		head_ptr = NULL;
		current = NULL;
		previous = NULL;
	}
}

int main() {
	d_stack<int> d1;
	d1.push(22);
	std::cout << "First top -> " << d1.top() << std::endl;
	std::cout << "size -> " << d1.size() << std::endl;
	d1.push(63); 
	d1.push(48); 
	std::cout << "Third top (48) -> " << d1.top() << std::endl;
	std::cout << "size (3) -> " << d1.size() << std::endl;
	std::cout << d1.top() << std::endl;
	d1.pop(); 
	std::cout << "New top (63) -> " << d1.top() << std::endl;
	std::cout << "New size (2) -> " << d1.size() << std::endl;
	return EXIT_SUCCESS;
}