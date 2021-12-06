#include "table.h"


table::table(){
	numPlayers = 9;
	mainDeck.updateDeckPos(0);
	mainDeck.makeDeck();
	//mainDeck.displayDeck();
}

table::~table() {
}

int table::playerCount(){
	return numPlayers;
}

void table::setPlayer(int seatNum, std::string playerName){
	seat[seatNum].setPlayerName(playerName);
}

void table::showTablePlayerHoleCards(int seatNum){
	seat[seatNum].showHoleCards();
}

void table::dealPlayerHoleCards() {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < numPlayers; j++) {
			seat[j].setCard(i, mainDeck.dealCard());
		}
	}
}

void table::dealBoard(int numberOfCards) {
	burn();
	for (int i = 0; i < numberOfCards; i++) {
		boardDeque.emplace_back(mainDeck.dealCard());
	}
}

void table::burn(){
	mainDeck.dealCard();
}


void table::showBoard(std::string message) { 
	std::cout << message << std::endl;
	for (auto &boardCard : boardDeque) {
		if (boardCard != boardDeque.front()) {
			std::cout << ", ";
		}
		std::cout << boardCard.showCard();
	}
	std::cout << "\n\n";

}

void table::shuffleCards(int shuffleCount){
	for (int i = 0; i < shuffleCount; i++) {
		mainDeck.shuffleDeck();
	}
	boardDeque.clear();
}


void table::evaluateBoard() {
	
	
	eval.setBoard(boardDeque);
	eval.sortBoard();
	if (eval.isFlushPossible()) {
		std::cout << "Possible Flush\n";
	}
	if (eval.isStraightPossible()) {
		std::cout << "Possible Straight\n";
	}




}