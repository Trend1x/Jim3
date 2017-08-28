//PokerMain.cpp
//written by James Dixon
//Starting point for poker program

/*INCLUDES*/

#include "PokerMain.h"

int main() {
	deck deck1;
	deck1.makeDeck();
	//cout << "DEBUG: deck = : " << deck << endl;
	deck1.displayDeck();
	deck1.shuffleDeck();
	
	
	deck1.displayDeck();

	return 0;
}

