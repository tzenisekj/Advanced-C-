#include <cstdlib>
#ifndef STATICSTACK_H
#define STATICSTACK_H

template <class T>
class static_stack {
public:
	static const size_t CAPACITY = 30; 
	static_stack() { filled = 0; }
	void push(const T& data); 
	void pop(); 
	bool empty() const { return (filled == 0); };
	size_t size() const { return filled; }; 
	T top() const; 

private:
	T arr[CAPACITY]; 
	size_t filled; 
};
#endif
