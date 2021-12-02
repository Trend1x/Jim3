#include "table.h"
#include "Evaluator.h"

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

void table::sortBoard()
{
	int minIndex, maxIndex, startScan, numberOfComparisons = 0;
	card minCard, maxCard;
	minCard.setcard(0);
	maxCard.setcard(0);

	for (startScan = 0; startScan < (BOARD_SIZE / 2); startScan++) {
		minIndex = startScan;
		minCard = board[startScan];
		maxIndex = startScan;
		maxCard= board[startScan];
		for (int index = startScan + 1; index < BOARD_SIZE - startScan; index++) {
			numberOfComparisons++;
			if (board[index].isValidCard()) {
				if (board[index].getRankValue() < minCard.getRankValue()) {
					minCard = board[index];
					minIndex = index;
				}
				if (board[index].getRankValue() > maxCard.getRankValue()) {
					maxCard = board[index];
					maxIndex = index;
				}
			}
		}

		if (maxIndex == startScan) {
			board[maxIndex] = board[BOARD_SIZE - startScan - 1];
			board[BOARD_SIZE - startScan - 1] = maxCard;
			board[minIndex] = board[startScan];
			board[startScan] = minCard;
		}
		else {
			board[minIndex] = board[startScan];
			board[startScan] = minCard;
			board[maxIndex] = board[BOARD_SIZE - startScan - 1];
			board[BOARD_SIZE - startScan - 1] = maxCard;
		}
	}


}


void table::showBoard(string street) { 
	cout << street << endl;
	int index = -1;
	while (board[++index].isValidCard() && index < BOARD_SIZE) {
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


void table::evaluateBoard() {
	Evaluator eval;
	if (eval.isFlushPossible(board)) {
		cout << "Possible Flush" << endl;
	}
	else {
		cout << "No flush on board" << endl;
	}
	sortBoard();
	showBoard("Sorted");



}