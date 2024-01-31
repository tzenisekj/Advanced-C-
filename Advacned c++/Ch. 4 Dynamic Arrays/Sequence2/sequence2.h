#include <cstdlib>
#ifndef SEQUENCE1_H
#define SEQUENCE1_H
namespace main_savitch_tz {
	class sequence {
	public:
		typedef double value_type;
		typedef std::size_t size_type;

		sequence();
		sequence(sequence& seq); 
		~sequence(); 
		void start();
		void advance();
		void reallocate(); 
		void reallocate_down(); 
		void insert(const value_type& entry);
		void attatch(const value_type& entry);
		void put_front(const value_type& entry);
		void remove_front();
		void put_back(const value_type& entry);
		void advance_toBack();
		void remove_current();
		size_type size() const;
		bool is_item() const;
		value_type current() const;
		void operator +=(const sequence& addend);
		value_type operator [](size_type index) const;

	private:
		value_type* data;
		size_type allocated; 
		size_type used;
		size_type current_index;
	};
	sequence operator +(const sequence& s1, const sequence& s2);
}
#endif
