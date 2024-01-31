#include <cstdlib>
#ifndef DYNAMIC_STACK_H
#define DYNAMIC_STACK_H

template<class T>
class d_stack {
public: 
	d_stack(); 
	~d_stack(); 
	void pop(); 
	void push(T entry); 
	void clear(); 
	T top() const; 
	size_t size() const { return counter; }
	bool is_empty() const { return (counter == 0); }

private:
	struct Node {
	private: 
		T node_data; // data for stack
		Node* node_link; // link to next node

	public: 
		void set_data(T data) { node_data = data; }
		void set_link(Node* new_link) { node_link = new_link; } 
		T data() const { return node_data; }
		Node* link() const { return node_link; } 

	};

	Node* head_ptr; // top of the stack
	Node* current; // cursor to traverse list
	Node* previous; // cursor to follow behind the first

	size_t counter; // size of stack
};
#endif
