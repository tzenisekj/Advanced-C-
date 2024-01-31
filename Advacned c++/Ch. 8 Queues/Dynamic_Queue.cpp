#include <iostream>
#include <cassert>
#include "Dynamic_Queue.h"

namespace tz{
	template<class T>
	dynamic_queue<T>::dynamic_queue() {
		top = NULL; 
		head = NULL; 
		size_chain = 0; 
	}

	template<class T>
	dynamic_queue<T>::~dynamic_queue() {
		clear(); 
	}

	template<class T>
	void dynamic_queue<T>::push(T entry) {
		node* n = new node; 
		n.data = entry; 
		n.next = NULL; 

		head = n; 
		++size_chain; 
		if (size() == 0) {
			top = head; 
		}
		else {
			node* cursor; 
			cursor = head; 
			while (cursor != NULL) {
				cursor = cursor->next; 
			}
			top = cursor; 
		}
	}

	template<class T>
	void dynamic_queue<T>::pop() {
		node* cursor; 
		cursor = head; 

		while (cursor->next != NULL) {
			cursor = cursor->next; 
		}
		cursor->next = NULL; 
		delete top; 
		--size_chain; 
		top = cursor; 
	}

	template<class T>
	T dynamic_queue<T>::top() const {
		return top->data; 
	}

	template<class T>
	void dynamic_queue<T>::clear() {
		while (size() != 0) {
			node* cursor; 
			cursor = head; 

			while (cursor->next != NULL) {
				cursor = cursor->next; 
			}
			cursor->next = NULL; 
			delete top; 
			top = cursor; 
			--size_chain; 
		}
	}
}


using namespace tz; 

int main() {
	dynamic_queue<int> q1; 
	std::cout << "Queue added in 22 as first" << std::endl;
	q1.push(22);
	std::cout << "First in queue (22): " << q1.top() << std::endl;
	q1.push(78);
	std::cout << "\nQueue added in 78 as second" << std::endl;
	std::cout << "First in queue (22): " << q1.top() << std::endl;
	q1.push(82);
	std::cout << "\nQueue added in 82 as third" << std::endl;
	std::cout << "First in queue (22): " << q1.top() << std::endl;

	q1.pop();
	std::cout << "\nRemoving first item (22) from queue" << std::endl;
	std::cout << "New first in queue (78) : " << q1.top() << std::endl;

	return 0; 
}