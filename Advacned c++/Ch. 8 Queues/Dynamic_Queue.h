#include <cstdlib>
#ifndef DYNAMIC_QUEUE_H
#define DYNAMIC_QUEUE_H

namespace tz {
	template<class T>
	class dynamic_queue {
	public:
		dynamic_queue();
		~dynamic_queue(); 
		void push(T entry);
		void pop();
		void clear(); 
		T top() const;
		size_t size() const { return size_chain }
		bool is_empty() const { return (size_chain == 0); }

	private:
		struct node {
			T data; 
			node* next; 
		};
		node* top_link; 
		node* head; 
		size_t size_chain; 
	};
}
#endif