#include "table.h"


table::table(){
	mainDeck.makeDeck();

}

table::~table() {
}

int table::playerCount(){
	return seat.size();
}

void table::setPlayer(int seatNum, std::string playerName){
	
	seat[seatNum].setPlayerName(playerName);
}

void table::showTablePlayerHoleCards(int seatNum){
	seat[seatNum].showHoleCards();
}

void table::dealPlayerHoleCards() {
	for (int i = 0; i < 2; i++) {
		for (auto& seated :seat) {
			seated.dealPlayerHoleCard(mainDeck.dealCard());
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
	for (int j = 0; j < numPlayers; j++) {
		seat[j].clearPlayerHoleCards();
	}

}

void table::sortBoard()
{
	int minIndex, startScan = 0;
	card minCard;
	minCard.setcard(0);
	
	for (startScan = 0; startScan < boardDeque.size(); startScan++) {
		minIndex = startScan;
		minCard = boardDeque[startScan];

		for (int index = startScan + 1; index < boardDeque.size(); index++) {
			if (boardDeque[index].getRankValue() < minCard.getRankValue()) {
				minCard = boardDeque[index];
				minIndex = index;
			}
		}
		boardDeque[minIndex] = boardDeque[startScan];
		boardDeque[startScan] = minCard;
	}
}


void table::evaluateBoard() {
	
	sortBoard();
	showBoard("Sorted");
	eval.setBoard(boardDeque);

	for (auto& seated : seat)
	{
		std::cout << "Evaluating " << seated.getPlayerName() << std::endl;
		eval.evaluatePlayerHand(seated.getHoleCards());

	}
	
	//showBoard("after player 1");
}