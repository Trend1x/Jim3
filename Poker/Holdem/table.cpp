#include "table.h"

table::table(){
	numPlayers = 9;
	mainDeck.updateDeckPos(0);
	mainDeck.makeDeck();

}

int table::playerCount(){
	return numPlayers;
}

void table::setPlayer(int seatNum, string playerName){
	seat[seatNum].setPlayerName(playerName);
}

void table::playerCards(int seatNum){
	seat[seatNum].showHoleCards();
}


table::~table(){
}


void table::dealCards() {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < numPlayers; j++) {
			seat[j].setCard(i, mainDeck.getCard(mainDeck.getDeckPos()));
			mainDeck.updateDeckPos(mainDeck.getDeckPos() + 1);
		}
	}
	for (int i = 0; i < 5; i++) {
		board[i].setcard(-1);
	}

}

void table::dealFlop(){
	burn();
	for (int i = 0; i < 3; i++) {
		board[i] = mainDeck.getCard(mainDeck.getDeckPos());
		mainDeck.updateDeckPos(mainDeck.getDeckPos() + 1);
	}
}

void table::dealTurn(){
	burn();
	board[3] = mainDeck.getCard(mainDeck.getDeckPos());
	mainDeck.updateDeckPos(mainDeck.getDeckPos() + 1);
}

void table::dealRiver(){
	burn();
	board[4] = mainDeck.getCard(mainDeck.getDeckPos());
}

void table::burn(){
	mainDeck.updateDeckPos(mainDeck.getDeckPos() + 1);
}


void table::showBoard(string street) { 
	cout << street << endl;
	int index = -1;
	while (board[++index].isValidCard()) {
		if (index != 0) {
			cout << ", ";
		}
		cout << board[index].showCard();
	}
	cout << "\n\n";

}

void table::shuffleCards(int shuffleCount){
	for (int i = 0; i < shuffleCount; i++) {
		mainDeck.shuffleDeck();
	}
}
