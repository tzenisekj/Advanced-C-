#include <iostream>
#include "List.h"

template<class type>
List<type>::List::List() {
	head = NULL;
	current = NULL;
	previous = NULL;
	next = NULL;
	length = 0; 
}

template<class type>
List<type>::List::List(List& l) {
	head = NULL;
	current = NULL;
	previous = NULL;
	next = NULL;
	length = 0;
	l.current = l.head; 
	while (l.current != NULL) {
		append(l.current->value); 
		l.current = l.current->link; 
	}
}

template<class type>
List<type>::List::~List() {
	while (size() != 0) {
		current = head; 
		while (current != NULL) {
			current = current->link; 
		}
		delete current; 
		--length; 
	}
}

template<class type>
void List<type>::List::append(type new_value) {
	// creates new node
	node_ptr a = new Node; 
	a->value = new_value; 
	a->link = NULL;
	
	if (head != NULL) {
		current = head; 
		while (current->link != NULL) {
			current = current->link; 
		}
		current->link = a; 
		length++; 
	}
	else {
		head = a; 
		++length;
	}
}

template<class type>
void List<type>::List::print_list() {
	current = head; 
	while (current != NULL) {
		std::cout << current->value << std::endl;
		current = current->link; 
	}
}

template<class type>
void List<type>::List::delete_value(type del_value) {
	// checks for empty list
	if (head == NULL) {
		std::cout << del_value << " not found in list!\n";
		return;
	}

	// loops to search list for value 
	current = head; 
	previous = NULL; 
	while (current != NULL) {
		if (current->value == del_value) {
			break; 
		}
		else {
			previous = current; 
			current = current->link; 
		}
	}

	// if value isn't found in list
	if (current == NULL) {
		std::cout << del_value << " not found in list!\n";
	}
	// if value is found in list
	else {
		// if value is at the head
		if (current == head) {
			head = head->link;  
		}
		// if value is somewhere in list beyond the head
		else {
			previous->link = current->link; 
		}
		delete current; 
		--length; 
		std::cout << del_value << " deleted!\n";
	}
}

template<class type>
void List<type>::List::reverse() {
	previous = NULL;
	current = head; 
	while (current != NULL) {
		next = current->link; 
		current->link = previous; 
		previous = current; 
		current = next; 
	}
	head = previous;
}

template<class type>
void List<type>::List::insert(int position, type value) {
	node_ptr a = new Node; 
	a->value = value;
	a->link = NULL; 

	if (position <= 1) {
		a->link = head; 
		head = a; 
		++length; 
		return; 
	}
	current = head; 
	for (int i = 0; i < position - 2; i++) {
		if (current->link == NULL) {
			break; 
		}
		current = current->link; 
	}
	a->link = current->link;
	current->link = a; 
	++length; 
}

// sort function
template<class type>
void List<type>::List::sort() { 
	node_ptr new_head = new Node; 
	new_head->link = NULL; 
	type largest = head->vaue; 

	previous = head; 
	current = head; 
	while (current != NULL) {
		if (current->value > largest) {
			previous->link = current->link;
			current->link = NULL;
			if (new_head->link == NULL) {
				new_head = current;
				previous = current;
				current = head; 
			}
			else {
				current->link = new_head; 
				new_head = current; 
				previous = curent; 
				current = head; 
			}
		}
		else {
			previous = current;
			current = current->link; 
		}
	}
	head = new_head; 
	delete new_head; 
}

int main() {
	List<int> p;
		p.append(5);
		p.append(6);
		p.append(7);
		p.append(8);
		p.append(9);
		p.append(10);
		p.print_list();
		std::cout << "\n";
		std::cout << "size -> " << p.size() << std::endl;
		std::cout << "\n";
		p.insert(8, 99);
		p.print_list();
		std::cout << "\n";
		p.insert(2, 122);
		p.print_list();
		return 0;
	return 0; 
}






