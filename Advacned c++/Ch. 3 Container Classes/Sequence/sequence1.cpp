#include "sequence1.h"
#include <cassert>

namespace main_savitch_tz {
	sequence::sequence() {
		used = 0; 
		current_index = NULL; 
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
		assert(size() < CAPACITY); 

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
		assert(size() < CAPACITY); 

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
		assert(size() < CAPACITY); 
		data[used + 1] = entry; 
		++used; 
		current_index = used; 
	}

	void sequence::attatch(const value_type& entry) {
		assert(size() < CAPACITY); 
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
		for (unsigned int i = current_index + 1; i < used - 1; ++i)
		{
			data[i] = data[i + 1];
			--used;
		}
		data[used + 1] = NULL; 
	}

	void sequence::remove_front() {
		assert(is_item()); 
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
		assert(size() + addend.size() <= CAPACITY); 

		for (unsigned int i = 0; i < addend.size(); ++i) {
			data[used + 1] = addend.data[i]; 
			++used; 
		}
	}

	sequence operator +(const sequence& s1, const sequence& s2) {
		sequence s3; 
		assert(s1.size() + s2.size() <= s3.CAPACITY); 

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