#include <ctime>
#include <stdlib.h>
#include <iostream>

//shuffle function 
template<class type>
void shuffle(type arr[], type n) {
	srand((unsigned)time(0));
	for (int i = 0; i < 25; ++i) {
		for (int j = 0; j < n; ++j) {
			int num = 1 + (rand() % n - 1);
			type holder = arr[0]; 
			arr[0] = arr[num]; 
			arr[num] = holder; 
		}
	 }
}

// prints array
template<class type>
void print(type arr[], type n) {
	for (int i = 0; i < n; ++i) {
		std::cout << arr[i] << " ";
	}
}

int main () {
	const int SIZE = 52; 
	int a[SIZE];
	char input; 

	for (int i = 0, j = 1; i < SIZE; ++i, ++j) {
		a[i] = j; 
	}

	std::cout << "Unshuffled array....." << std::endl;
	print(a, SIZE); 
	std::cout << "\n";

	do {
		shuffle(a, SIZE);
		std::cout << "\nShuffled" << std::endl;
		print(a, SIZE);

		do {
			std::cout << "\nShuffle again? (y/n)" << std::endl;
			std::cout << "--> ";
			std::cin >> input;

			if (tolower(input != 'n' && tolower(input) != 'y')) {
				std::cout << "\nInvalid input!" << std::endl;
			}

		} while (tolower(input != 'n' && tolower(input) != 'y'));
		
		if (tolower(input) == 'n') break;
	} while (true); 

	return EXIT_SUCCESS;
}