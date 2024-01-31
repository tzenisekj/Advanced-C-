#include <iostream>
#include <cassert>
#include "StaticStack.h"

template<class T>
void static_stack<T>::push(const T& data) {
	assert(size() < CAPACITY); 
	arr[filled] = data;
	++filled; 
}

template<class T>
void static_stack<T>::pop() {
	assert(!empty()); 
	--filled; 
}

template<class T>
T static_stack<T>::top() const {
	assert(!empty()); 
	return arr[filled - 1]; 
}


int main() {
	static_stack<int> s1; 
	std::cout << "is empty -> " << s1.empty() << std::endl;
	std::cout << "\n";
	s1.push(55); 
	s1.push(44); 
	s1.push(22); 
	std::cout << "is emtpy -> " << s1.empty() << std::endl;
	std::cout << "size -> " << s1.size() << std::endl;
	std::cout << "\n";
	std::cout << "top -> " << s1.top() << std::endl;
	s1.pop(); 
	std::cout << "\n";
	std::cout << "second top -> " << s1.top() << std::endl;
	std::cout << "size -> " << s1.size() << std::endl;
	std::cout << "is empty -> " << s1.empty() << std::endl;
	s1.pop();
	std::cout << "\n";
	std::cout << "third top -> " << s1.top() << std::endl;
	std::cout << "size -> " << s1.size() << std::endl;
	std::cout << "is empty -> " << s1.empty() << std::endl;

	s1.pop();
	std::cout << "\n";
	std::cout << "size -> " << s1.size() << std::endl;
	std::cout << "is empty -> " << s1.empty() << std::endl;


	return EXIT_SUCCESS; 
}