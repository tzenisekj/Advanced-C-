#include <algorithm> // used for copy function
#include <cassert> // includes assert
#include "bag1.h"
using namespace std; 

namespace main_savitch_tz {
	const bag::size_type bag::CAPACITY;

	bag::size_type bag::erase(const value_type& target) {
		size_type index = 0;
		size_type removed = 0;

		while (index < used) {
			if (data[index] == target) {
				--used;
				data[index] = data[used];
				++removed;
			}
			else {
				++index;
			}
		}
		return removed;
	}

	bool bag::erase_one(const value_type& target) {
		size_type index;

		index = 0;
		while ((index < used) && (data[index] != target)) {
			++index;
		}

		if (index == used) {
			return false;
		}

		--used;
		data[index] = data[used];
		return true;
	}

	void bag::insert(const value_type& entry) {
		assert(size() < CAPACITY);

		data[used] = entry;
		++used;
	}

	void bag::operator +=(const bag& addend) {
		assert(size() + addend.size() <= CAPACITY);

		copy(addend.data, addend.data + addend.used, data + used);
		used += addend.used;
	}

	void bag::operator -=(const bag& minend) {
		assert(size() - minend.size() >= 0);

		value_type target;
		for (unsigned int i = 0; i < minend.size(); ++i) {
			target = minend.data[i];
			size_type index = 0;

			while (index < used) {
				if (data[index] == target) {
					--used;
					data[index] = data[used];
				}
				else {
					++index;
				}
			}
		}
	}

	bag::size_type bag::count(const value_type& target) const {
		size_type answer;
		size_type i;

		answer = 0;
		for (i = 0; i < used; ++i) {
			if (target == data[i]) {
				++answer;
			}
		}
		return answer;
	}

	bag operator +(const bag& b1, const bag& b2) {
		bag answer;
		assert(b1.size() + b2.size() <= bag::CAPACITY);

		answer += b1;
		answer += b2;
		return answer;
	}

	bag operator -(const bag& b1, const bag& b2) {
		bag answer;
		assert(b1.size() - b2.size() >= 0);

		answer = b1;
		answer -= b2;
		return answer;
	}
}