#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

namespace main_savitch_tz {
	class ttt_game {
	public:
		ttt_game();
		ttt_game(int two_player); 
		void display();
		void twoPlayer(); 
		void onePlayer(); 
		void setPlayer(char player); 
		bool gameOver() const;
		bool validInput(int& move) const; 
		void nextMove(char player); 
		void auto_fill(); 

	private:
		char board[3][3] =
		{
		  {'1','2','3'},
		  {'4','5','6'},
		  {'7','8','9'},
		};
		char player_one; 
		char player_two; 
	};
}
#endif
