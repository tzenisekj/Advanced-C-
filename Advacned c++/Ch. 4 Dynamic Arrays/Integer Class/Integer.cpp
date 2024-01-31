#include "Integer.h"

namespace main_savitch_tz {
	Integer::Integer() {
		allocated = 2; 
		arr_start = new int[allocated]; 
		current_size = 0; 
	}

	Integer::Integer(Integer& num) {
		while (size_of() + num.size_of() >= allocated) {
			reallocate(); 
		}
		for (int i = 0; i < num.size_of(); ++i) {
			arr_start[current_size] = num.arr_start[i]; 
			++current_size; 
		}
	}

	void Integer::operator +=(Integer& num) {
		while (size_of() + num.size_of() >= allocated) {
			reallocate();
		}
		for (int i = 0; i < num.size_of(); ++i) {
			arr_start[current_size] = num.arr_start[i];
			++current_size;
		}
	}

	Integer::~Integer() {
		delete[] arr_start;
	}

	void Integer::reallocate() {
		int* new_start;
		int new_allocate = allocated + 2; 
		new_start = new int[new_allocate]; 
		for (int i = 0; i < current_size; ++i) {
			new_allocate = arr_start[i]; 
		}
		delete[] arr_start; 
		arr_start = new_start; 
		allocated = new_allocate; 
	}

	Integer operator +(Integer& num1, Integer& num2) {
		Integer num3; 
		while (num1.size_of() + num2.size_of() >= num3.size_of()) {
			num3.reallocate(); 
		}
		num3 += num1; 
		num3 += num2; 
		return num3; 
	}

	bool Integer::is_negative() const{
		if (arr_start[0] >= 0) {
			isNegative == false; 
			return isNegative; 
		}
		else {
			isNegative == true; 
			return isNegative; 
		}
	}

	std::size_t Integer::size_of() const {
		return current_size; 
	}

	void Integer::input_number(int& num) {
		if (size_of() + 1 >= allocated) {
			reallocate(); 
		}
		arr_start[current_size] = num; 
		++current_size; 
	}

	int* Integer::num_return() const {
		return arr_start; 
	}
}

