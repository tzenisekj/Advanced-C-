#include "stats.h"
#include <iostream>

namespace main_savitch_2C {
	statistician::statistician() {
		count = 0;
		tinyest = {};
		largest = {};
		total = 0.0;
	}

	void statistician::next(double r) {
		if (count == 0) {
			total += r; 
			largest = r; 
			tinyest = r; 
		}
		else {
			total += r; 
			if (r > largest) {
				largest = r;
			}
			if (r < tinyest) {
				tinyest = r;
			}
		}
		count++; 
	}

	void statistician::reset() {
		count = 0; 
		total = 0.0; 
		tinyest = NULL; 
		largest = NULL; 
	}

	int statistician::length()const {
		return count;
	}

	double statistician::sum()const {
		return total; 
	}

	double statistician::mean()const {
		if (count > 0) {
			return total / count;
		}
		else {
			return NULL; 
		}
	}

	double statistician::minimum()const {
		if (count > 0) {
			return tinyest;
		}
		else {
			return NULL; 
		}
	}

	double statistician::maximum()const {
		if (count > 0) {
			return largest;
		}
		else {
			return NULL; 
		}
	}

	statistician operator +(const statistician& s1, const statistician& s2) {
		statistician s3; 
		if (s1.length() == 0) {
			return s2; 
		}
		else if (s2.length() == 0) {
			return s1; 
		}
		else {
			s3.count = s1.length() + s2.length();
			s3.total = s1.sum() + s2.sum();
			if (s1.maximum() > s2.maximum()) {
				s3.largest = s1.maximum();
			}
			else if (s1.maximum() < s2.maximum()) {
				s3.largest = s2.maximum();
			}
			else {
				s3.largest = s1.maximum();
			}

			if (s1.minimum() < s2.minimum()) {
				s3.tinyest = s1.minimum();
			}
			else if (s1.minimum() > s2.minimum()) {
				s3.tinyest = s2.minimum();
			}
			else {
				s3.tinyest = s1.minimum();
			}
			return s3;
		}
	}

	statistician operator *(double scale, const statistician& s) {
		if (s.length() == 0) {
			return s; 
		}
		else {
			statistician r;
			r.count = s.length();
			r.total = s.sum() * scale;
			r.largest = s.maximum() * scale;
			r.tinyest = s.minimum() * scale;
			return r;
		}
	}

	bool operator ==(const statistician& s1, const statistician& s2) {
		if (s1.length() == 0 && s2.length() == 0) {
			return true; 
		}
		else {
			if (s1.length() == s2.length() && s1.sum() == s2.sum() && s1.mean() == s2.mean() && s1.maximum() == s2.maximum() && s1.minimum() == s2.minimum()) {
				return true; 
			}
			else {
				return false; 
			}
		}
	}
}

	using namespace main_savitch_2C; 
	int main() {
		statistician joe; 
		joe.next(1.01); 
		joe.next(6.3); 

		joe.reset(); 

		joe.next(20.52); 
		joe.next(105.66); 

		std::cout << joe.mean() << std::endl;

		statistician marly; 
		marly.next(.09); 
		marly.next(.15);

		std::cout << marly.maximum() << std::endl; 

		statistician lizz = marly + joe; 
		std::cout << lizz.length() << std::endl; 

		return EXIT_SUCCESS;
	}
