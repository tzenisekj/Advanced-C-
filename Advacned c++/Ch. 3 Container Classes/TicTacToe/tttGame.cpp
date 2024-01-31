#include "tttGame.h"
#include <iostream>
#include <ctime>
#include <cassert>
#include <cstdlib>
using namespace std; 

namespace main_savitch_tz {
	ttt_game::ttt_game() {
		player_one = 'X';
		player_two = 'O';
		onePlayer(); 
	}

	ttt_game::ttt_game(int two_player) {
		player_one = 'X';
		player_two = 'O';
		twoPlayer(); 
	}

	// function displays the board
    void ttt_game::display() {
		cout << "\n";
		cout << "\t" << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
		cout << "\t" << "---------" << endl;
		cout << "\t" << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
		cout << "\t" << "---------" << endl;
		cout << "\t" << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    }

	// function used to check if somebody has won or if there is a draw
	bool ttt_game::gameOver() const {
		int counter = 0;
		int counterX; 
		int counterO;
		bool gOver = false;
		for (int i = 0; i < 3; ++i) {
			counterX = 0;
			counterO = 0; 
			for (int j = 0; j < 3; ++j) {
				if (board[i][j] == 'X') {
					counterX++; 
					counter++;
				}
				if (board[i][j] == 'O') {
					counterO++;
					counter++;
				}
			}
			if (counterX == 3) {
				gOver = true;
			}
			if (counterO == 3) {
				gOver = true;
			}
		}
		if (counter == 9) {
			gOver = true;
		}

		if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') {
			gOver = true;
		}
		if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O') {
			gOver = true;
		}
		if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X') {
			gOver = true;
		}
		if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O') {
			gOver = true;
		}
		if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X') {
			gOver = true;
		}
		if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O') {
			gOver = true;
		}
		if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') {
			gOver = true;
		}
		if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') {
			gOver = true; 
		}
		if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') {
			gOver = true;
		}
		if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O') {
			gOver = true;
		}
		return gOver; 
	}

	// function checks if the users move is a valid input
	bool ttt_game::validInput(int& move) const {
		bool check = false; 
		if (move == 1)
		{
			if (board[0][0] != 'X' && board[0][0] != 'O') {
				check = true;
			}
		}
		else if (move == 2)
		{
			if (board[0][1] != 'X' && board[0][1] != 'O') {
				check = true;
			}
		}
		else if (move == 3)
		{
			if (board[0][2] != 'X' && board[0][2] != 'O') {
				check = true;
			}
		}
		else if (move == 4)
		{
			if (board[1][0] != 'X' && board[1][0] != 'O') {
				check = true;
			}
		}
		else if (move == 5)
		{
			if (board[1][1] != 'X' && board[1][1] != 'O') {
				check = true;
			}
		}
		else if (move == 6)
		{
			if (board[1][2] != 'X' && board[1][2] != 'O') {
				check = true;
			}
		}
		else if (move == 7)
		{
			if (board[2][0] != 'X' && board[2][0] != 'O') {
				check = true;
			}
		}
		else if (move == 8)
		{
			if (board[2][1] != 'X' && board[2][1] != 'O') {
				check = true;
			}
		}
		else if (move == 9)
		{
			if (board[2][2] != 'X' && board[2][2] != 'O') {
				check = true;
			}
		}
		return check;
	}

	// function sets player as X or O
    void ttt_game::setPlayer(char player) {
        if (player == 'X')
            player = 'O';
        else if (player == 'O')
            player = 'X';
    }

	// function gets the players move and updates the board
    void ttt_game::nextMove(char player) {
		int move;
		cout << "\nPlayer " << player << ", choose your draw!" << endl;
		cout << "--> ";
		cin >> move; 

		while (validInput(move) == false || move > 9 || move < 1) { 
			cout << "\nPlayer " << player << ", choose your draw!" << endl;
			cout << "--> ";
			cin >> move;
		}

		if (move == 1)
		{
			board[0][0] = player;
		}
		else if (move == 2)
		{
			board[0][1] = player;
		}
		else if (move == 3)
		{
			board[0][2] = player;
		}
		else if (move == 4)
		{
			board[1][0] = player;
		}
		else if (move == 5)
		{
			board[1][1] = player;
		}
		else if (move == 6)
		{
			board[1][2] = player;
		}
		else if (move == 7)
		{
			board[2][0] = player;
		}
		else if (move == 8)
		{
			board[2][1] = player;
		}
		else if (move == 9)
		{
			board[2][2] = player;
		}
    }

	// function used to play the game v/s AI (AI is random)
	void ttt_game::onePlayer() {
		while (gameOver() == false) {
			display();
			nextMove(player_one); 
			if (gameOver() == true) break; 
			auto_fill(); 
		}
		cout << "\nGame Over!" << endl;
		display();
	}

	// function simulates a player by randomly selecting a place on the board to play 
	void ttt_game::auto_fill() {
		int pMove; 
		srand((unsigned)time(0));
		pMove = 1 + (rand() % 9);

		while (validInput(pMove) == false) {
			pMove = 1 + (rand() % 9);
		}

		if (pMove == 1)
		{
			board[0][0] = player_two;
		}
		else if (pMove == 2)
		{
			board[0][1] = player_two;
		}
		else if (pMove == 3)
		{
			board[0][2] = player_two;
		}
		else if (pMove == 4)
		{
			board[1][0] = player_two;
		}
		else if (pMove == 5)
		{
			board[1][1] = player_two;
		}
		else if (pMove == 6)
		{
			board[1][2] = player_two;
		}
		else if (pMove == 7)
		{
			board[2][0] = player_two;
		}
		else if (pMove == 8)
		{
			board[2][1] = player_two;
		}
		else if (pMove == 9)
		{
			board[2][2] = player_two;
		}
	}

	// function enables two players to play the game manually 
	void ttt_game::twoPlayer() {
		while (gameOver() == false) {
			display();
			nextMove(player_one);
			if (gameOver() == true) break;
			display(); 
			nextMove(player_two); 
		}
		cout << "\nGame Over!" << endl;
		display();
	}
}