//PokerMain.cpp
//written by James Dixon
//Starting point for poker program

/*INCLUDES*/

#include "PokerMain.h"

int main() {
	table table1;
	
	//assing names (Player 1, etc)
	//player seat[NUM_PLAYERS];
	string tempName;
	for (int i = 0; i < table1.playerCount(); i++) {
		tempName = "Player ";
		tempName += to_string(i + 1);
		table1.setPlayer(i, tempName);
		//cout << "Player Name: " << table1.seat[i].getPlayerName() << endl;
	}
	
	table1.shuffleCards(5);
	table1.dealCards();

	//show player hole cards
	for (int i = 0; i < table1.playerCount(); i++) {
		table1.playerCards(i);
	}
	table1.dealFlop();
	table1.showBoard("THE FLOP");
	table1.dealTurn();
	table1.showBoard("THE TURN");
	table1.dealRiver();
	table1.showBoard("THE RIVER");



	return 0;
}


//cout << "DEBUG: Back into main" << endl;