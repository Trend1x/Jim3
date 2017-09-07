//PokerMain.cpp
//written by James Dixon
//Starting point for poker program

/*INCLUDES*/

#include "PokerMain.h"

int main() {
	const int NUM_PLAYERS = 9;
	deck deck1;
	deck1.makeDeck();
	int deckPosition = 0;

	//create player array and assing names (Player 1, etc)
	player seat[NUM_PLAYERS];
	string tempName;
	for (int i = 0; i < NUM_PLAYERS; i++) {
		tempName = "Player ";
		tempName += to_string(i + 1);
		seat[i].setPlayerName(tempName);
		cout << "Player Name: " << seat[i].getPlayerName() << endl;
	}


	
	//cout << "DEBUG: deck = : " << deck << endl;
	//deck1.displayDeck();
	deck1.shuffleDeck();
	deck1.shuffleDeck();
	deck1.shuffleDeck();
	
	deck1.displayDeck();


	// deal cards
	int numplyers = NUM_PLAYERS;
	deckPosition = dealCards(deck1, seat, numplyers);
	cout << "DEBUG: deck Position = " << deckPosition << endl;

	//show player hole cards
	for (int i = 0; i < numplyers; i++) {
		seat[i].showHoleCards();
	}


	return 0;
}

int dealCards(deck deck1, player position[], int numPlayers) {
	int deckPos = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < numPlayers; j++) {
			position[j].setCard(i, deck1.getCard(deckPos++));
			}
		}



	return deckPos;
}

int dealFlop(int deckPos, deck deck1)
{
	return 0;
}



