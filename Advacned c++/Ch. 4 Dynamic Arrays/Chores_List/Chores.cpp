#include "Chores.h"
#include <iostream>
#include <algorithm>

namespace main_savitch_tz {
	Chores_List::Chores_List() {
		allocated = 2; 
		chores_arr = new std::string[allocated]; 
		current_size = 0; 
	}

	Chores_List::~Chores_List() {
		delete [] chores_arr; 
	}

	void Chores_List::add_chore(std::string& chore) {
		if (num_chores() >= allocated) {
			reallocate(); 
		}
		chores_arr[current_size] = chore; 
		++current_size; 
	}

	int Chores_List::num_chores() const {
		return current_size; 
	}

	void Chores_List::display_chores() {
		std::cout << "Chores:" << std::endl;
		std::cout << "=======" << std::endl;
		for (int i = 0, int j = 1; i < current_size; ++i, ++j) {
			std::cout << j << ". " << chores_arr[i] << std::endl;
		}
	}

	void Chores_List::delete_chore() {
		for (int i = current_size; i > 0; ++i) {
			chores_arr[i - 1] = chores_arr[i - 2]; 
			--i; 
		}
		--current_size; 
		std::cout << "Chore deleted...." << std::endl;
	}

	std::string* Chores_List::chores_list() const {
		return chores_arr; 
	}

	void Chores_List::reallocate() {
		std::string* new_arr; 
		int new_allocated = allocated + 2; 
		new_arr = new std::string[new_allocated]; 
		copy(chores_arr, chores_arr + current_size, new_arr);
		delete[] chores_arr; 
		chores_arr = new_arr; 
		allocated = new_allocated; 
	}
}