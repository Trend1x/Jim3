#pragma once

#include <iostream>
#include <string>
#include "card.h"
#include <stdlib.h>
#include <ctime>


using namespace std;

const int DECK_SIZE = 52;

class deck
{
private:
	card dk[DECK_SIZE];
	int deckPos;
	

public:
	deck();
	void makeDeck();
	void displayDeck();
	void shuffleDeck();
	card getCard(int index);
	void updateDeckPos(int newPos);
	int getDeckPos();

	~deck();
};



