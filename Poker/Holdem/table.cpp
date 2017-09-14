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

void table::calculateHand(player current){
	card hand[7];
	
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
}

void table::dealFlop(){
	burn();
	for (int i = 0; i < 3; i++) {
		flop[i] = mainDeck.getCard(mainDeck.getDeckPos());
		hand[i] = flop[i];
		mainDeck.updateDeckPos(mainDeck.getDeckPos() + 1);
	}
}

void table::dealTurn(){
	burn();
	turn = mainDeck.getCard(mainDeck.getDeckPos());
	hand[3] = turn;
	mainDeck.updateDeckPos(mainDeck.getDeckPos() + 1);
}

void table::dealRiver(){
	burn();
	hand[4] = river;
	river = mainDeck.getCard(mainDeck.getDeckPos());
}

void table::burn(){
	mainDeck.updateDeckPos(mainDeck.getDeckPos() + 1);
}

void table::showFlop()
{
	cout << endl << "THE FLOP" << endl;
	for (int i = 0; i < 3; i++) {
		cout << flop[i].showCard();
		if (i != 2) {
			cout << ", ";
			}
		else {
			cout << "\n\n";
		}
	}
}

void table::showTurn()
{
	cout << "THE TURN" << endl;
	cout << turn.showCard() << ", ";
	for (int i = 0; i < 3; i++) {
		cout << flop[i].showCard();
		if (i != 2) {
			cout << ", ";
		}
		else {
			cout << "\n\n";
		}
	}
}

void table::showRiver()
{
	cout << "THE RIVER" << endl;
	cout << river.showCard() << ", " << turn.showCard() << ", ";
	for (int i = 0; i < 3; i++) {
		cout << flop[i].showCard();
		if (i != 2) {
			cout << ", ";
		}
		else {
			cout << "\n\n";
		} 
	}
}

void table::shuffleCards(int shuffleCount){
	for (int i = 0; i < shuffleCount; i++) {
		mainDeck.shuffleDeck();
	}
}
