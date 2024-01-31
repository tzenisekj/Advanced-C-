#include "tttGame.h"
#include <iostream>
using namespace std; 
using namespace main_savitch_tz; 

int main() {
	int choice; 

	cout << "|| Tic Tac Toe! ||\n";
	cout << "------------------\n";
	do {
		cout << "\nMenu Prompt:\n1) Single Player\n2) Two players\n3) End Program" << endl;
		cout << "Choice--> ";
		cin >> choice;

		if (choice == 1) {
			ttt_game game;
		}
		else if (choice == 2) {
			ttt_game game(2);
		}
		else {
			cout << "\nExiting program......." << endl;
		}
	} while (choice != 3); 
	return EXIT_SUCCESS; 
}