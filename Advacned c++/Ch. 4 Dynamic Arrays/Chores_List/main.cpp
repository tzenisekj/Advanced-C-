#include <iostream>
#include <fstream>
#include "Chores.h"
#include <string>
using namespace main_savitch_tz; 

int main() {
	Chores_List chores; 
	int input; 
	std::string addChore; 
	char file_validate; 
	std::string file_Name;

	std::cout << "Input file of chores?(Y/N): "; 
	std::cin >> file_validate; 

	if (toupper(file_validate) == 'Y') {
		std::string chore;
		std::ifstream file; 
		std::cout << "\n\nInput file directory for chores: ";
		std::cin >> file_Name; 
		file.open(file_Name); 

		while (!file.eof()) {
			getline(file, chore); 
			chores.add_chore(chore); 
		}
		file.close(); 
	}

	do {
		std::cout << "\nInput the number choice of what you want to do! (1-5):\n";
		std::cout << "1) Add chore\n2) See num of chores\n3) Display chores\n4) Delete chore\n5) Exit program\n--> ";
		std::cin >> input; 

		switch (input) {
		case '1':
			std::cout << "\nInput chore to complete: "; 
			getline(std::cin, addChore); 
			chores.add_chore(addChore); 
			break;

		case '2':
			std::cout << "Number of chores to complete is : " << chores.num_chores() << " chores!\n"; 
			break;

		case '3':
			chores.display_chores(); 
			break;

		case '4':
			chores.delete_chore(); 
			break; 

		case '5':
			if (toupper(file_validate) == 'Y') {
				std::ofstream file; 
				file.open(file_Name); 
				std::string* holder = chores.chores_list(); 
				for (int i = 0; i < chores.num_chores(); ++i) {
					file << holder;
					file << "\n";
					++holder; 
					++i; 
				}
				file.close(); 
			}
			std::cout << "\nExiting the program....." << std::endl;
			break; 

		default:
			std::cout << "Invalid input! Please input a number between 1 and 5!\n";
			break; 
		}
	} while (input != 5); 
	return EXIT_SUCCESS; 
}