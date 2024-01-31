
#include <cstdlib>

namespace main_savitch_tz {
	class bag {
	public:
		// public variable
		typedef int value_type; // holds bag type
		typedef std::size_t size_type; // holds size
		static const size_type CAPACITY = 30; // max capacity of bag

		// constructor
		bag() { used = 0; }
		size_type erase(const value_type& target);
		bool erase_one(const value_type& target);
		void insert(const value_type& entry);

		// allows bag to be added to already existing bag
		void operator +=(const bag& addend);
		void operator -=(const bag& minend);
		// const member functions
		size_type size() const { return used; }
		size_type count(const value_type& target) const;

	private:
		value_type data[CAPACITY];
		size_type used;
	};

	// adds to bags together to create new bag
	bag operator +(const bag& b1, const bag& b2);
	bag operator -(const bag& b1, const bag& b2);
}

