#ifndef LIST_H
#define LIST_H

template<class type>
class List {
public:
	List();
	List(List& l); 
	~List(); 
	void append(type new_value);
	void reverse(); 
	void sort(); 
	void insert(int position, type value); 
	void delete_value(type del_value);
	void print_list(); 
	size_t size() const { return length;  }

private:
	struct Node {
		type value; 
		Node* link;
	};

	typedef struct Node*  node_ptr; 
	node_ptr head; 
	node_ptr current; 
	node_ptr previous; 
	node_ptr next; 
	size_t length; 
};
#endif
