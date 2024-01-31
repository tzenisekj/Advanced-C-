#include <cstdlib>
#ifndef STATIC_QUEUE_H
#define STATIC_QUEUE_H

namespace tz {
	template<class T>
	class static_queue {
	public: 
		const static size_t CAPACITY = 30; 

		static_queue(); 
		void push(T entry); 
		void pop(); 
		T top() const; 
		size_t size() const { return size_arr; }
		bool is_empty() const { return (size_arr == 0); }
		bool is_full() const { return (size_arr == CAPACITY); }

	private: 
		T arr[CAPACITY]; 
		size_t size_arr; 

	};
}
#endif