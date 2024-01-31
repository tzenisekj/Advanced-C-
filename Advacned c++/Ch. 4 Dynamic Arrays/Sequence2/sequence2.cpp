#include "sequence2.h"
#include <cassert>
#include <algorithm>

namespace main_savitch_tz {
	sequence::sequence() {
		allocated = 2; 
		used = 0; 
		data = new value_type[allocated]; 
		current_index = {}; 
	}

	sequence::sequence(sequence& seq) {
		while (size() + seq.size() >= allocated) {
			reallocate(); 
		}
		for (int i = 0; i < seq.used; ++i) {
			data[used] = seq.data[i]; 
			++used; 
			current_index = used; 
		}
	}

	sequence::~sequence() {
		delete [] data; 
	}

	void sequence::reallocate() {
		size_type new_allocated = allocated + 2; 
		value_type* holder; 
		holder = new value_type[new_allocated]; 
		for (int i = 0; i < used; ++i) {
			holder[i] = data[i]; 
		}
		delete[] data; 
		data = holder; 
		allocated = new_allocated; 
	}

	void sequence::reallocate_down() {
		size_type new_allocated = allocated - 1;
		value_type* holder;
		holder = new value_type[new_allocated];
		for (int i = 0; i < used; ++i) {
			holder[i] = data[i];
		}
		delete[] data;
		data = holder;
		allocated = new_allocated;
	}

	void sequence::start() {
		if (size() == 0) {
			current_index = NULL;
		}
		current_index = 0;
	}

	void sequence::advance() {
		assert(is_item());
		if (current_index = used - 1) {
			current_index = NULL;
		}
		else {
			++current_index;
		}
	}

	void sequence::advance_toBack() {
		assert(is_item());
		current_index = used;
	}

	void sequence::insert(const value_type& entry) {
		if (size() + 1 >= allocated) {
			reallocate(); 
		}

		if (size() == 0) {
			data[0] = entry;
			current_index = 0;
			++used;
		}
		else {
			for (unsigned int i = size(); i > current_index; --i) {
				data[i + 1] = data[i];
			}
			data[current_index] = entry;
			++used;
		}
	}

	void sequence::put_front(const value_type& entry) {
		if (size() + 1 >= allocated) {
			reallocate();
		}

		if (size() == 0) {
			data[0] = entry;
			current_index = 0;
			++used;
		}
		else {
			for (unsigned int i = size(); i > 0; --i) {
				data[i + 1] = data[i];
			}
			data[0] = entry;
			++used;
			current_index = used;
		}
	}

	void sequence::put_back(const value_type& entry) {
		if (size() + 1 >= allocated) {
			reallocate();
		}

		data[used + 1] = entry;
		++used;
		current_index = used;
	}

	void sequence::attatch(const value_type& entry) {
		if (size() + 1 >= allocated) {
			reallocate();
		}

		if (size() == 0) {
			data[0] = entry;
			current_index = 0;
			++used;
		}
		else {
			for (unsigned int i = size(); i > current_index + 1; --i) {
				data[i + 1] = data[i];
			}
			data[current_index + 1] = entry;
			++used;
			++current_index;
		}
	}

	void sequence::remove_current() {
		assert(is_item());
		if (size() - 1 <= allocated) {
			reallocate_down(); 
		}
		for (unsigned int i = current_index + 1; i < used - 1; ++i)
		{
			data[i] = data[i + 1];
			--used;
		}
		data[used + 1] = NULL;
	}

	void sequence::remove_front() {
		assert(is_item());
		if (size() - 1 <= allocated) {
			reallocate_down();
		}
		for (unsigned int i = 0; i < used - 1; ++i) {
			data[i] = data[i + 1];
			--used;
		}
		data[used + 1] = NULL;
	}

	sequence::size_type sequence::size() const {
		return used;
	}

	bool sequence::is_item() const {
		if (size() >= 0) {
			return true;
		}
		else {
			return false;
		}
	}

	sequence::value_type sequence::current() const {
		assert(is_item());
		return data[current_index];
	}

	void sequence::operator +=(const sequence& addend) {
		while (size() + addend.size() >= allocated) {
			reallocate(); 
		}
		for (unsigned int i = 0; i < addend.size(); ++i) {
			data[used + 1] = addend.data[i];
			++used;
		}
	}

	sequence operator +(const sequence& s1, const sequence& s2) {
		sequence s3;
		s3 += s1;
		s3 += s2;
		return s3;
	}

	sequence::value_type sequence::operator [](size_type index) const {
		assert(index >= used);
		return data[index];
	}
}

int main() {
	return EXIT_SUCCESS;
}