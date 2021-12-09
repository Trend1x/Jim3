//PokerMain.cpp
//written by James Dixon
//Starting point for poker program

/*INCLUDES*/

#include "PokerMain.h"

int main() {
	table table1;
	
	//assing names (Player 1, etc)
	for (int i = 0; i < table1.playerCount(); i++) {
		table1.setPlayer(i, "Player " + std::to_string(i + 1) );
	}
	
	table1.shuffleCards(5);
	table1.dealPlayerHoleCards();

	//show player hole cards
	for (int i = 0; i < table1.playerCount(); i++) {
		table1.showTablePlayerHoleCards(i);
	}
	table1.dealBoard(3);
	//table1.showBoard("THE FLOP");
	table1.dealBoard(1);
	//table1.showBoard("THE TURN");
	table1.dealBoard(1);
	table1.showBoard("THE RIVER");

	table1.evaluateBoard();

	return 0;
}


//cout << "DEBUG: Back into main" << endl;