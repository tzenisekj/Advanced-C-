#include <cstdlib>

namespace main_savitch_tz {
	class Integer {
	public:
		Integer(); 
		~Integer(); 
		Integer(Integer&); 
		bool is_negative() const;
		void input_number(int&); 
		std::size_t size_of() const; 
		int* num_return() const; 
		void reallocate();
		void operator +=(Integer&); 

	private:
		int* arr_start; 
		std::size_t allocated; 
		std::size_t current_size; 
		bool isNegative; 
	};

	Integer operator +(Integer& num1, Integer& num2); 
}
