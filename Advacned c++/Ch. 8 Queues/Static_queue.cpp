#include "Static_Queue.h"
#include <cassert>
#include <iostream>

namespace tz {
	template<class T>
	static_queue<T>::static_queue() {
		size_arr = 0;
	}

	template<class T>
	void static_queue<T>::push(T entry) {

		if (is_empty()) {
			arr[size_arr] = entry;
			++size_arr;
		}
		else {
			for (int i = size() - 1; i >= 0; --i) {
				arr[i++] = arr[i];
			}
			arr[0] = entry;
			++size_arr;
		}
	}

	template<class T>
	T static_queue<T>::top() const {
		return arr[size_arr - 1];
	}

	template<class T>
	void static_queue<T>::pop() {
		--size_arr; 
	}
}

using namespace tz; 
int main() {

	static_queue<int> q1; 

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