#pragma once

#include <iostream>
#include <string>
#include "card.h"
#include <stdlib.h>
#include <ctime>
#include <list>
#include <deque>

const int DECK_SIZE = 52;

class deck
{
private:
	//deque<card> deckList;
	card dk[DECK_SIZE];
	int deckPos;

	//Part of shuffleDeck(), moves 1-3 cards from one of the halfs to the shuffled pile.
	void clumpDrop(int &currentIndex, int &halfIndex, int endPoint, card refrenceDeck[]);


public:
	deck();

	//Create a deck and initialize values. Can be used to simulate "setup" requests.
	void makeDeck();

	//Displays the deck to the console. Used Primarily for debugging shuffle.
	void displayDeck();

	//Shuffles the deck. Simulates a riffle shuffle by a person.
	void shuffleDeck();
	
	//Returns the Card at the given index.
	card getCard(int index);

	//Updates the current position of the top card in the deck.
	void updateDeckPos(int newPos);

	//Returns the current position of the top card in the deck.
	int getDeckPos();

	//Deals the top card off the deck.
	card dealCard();


	~deck();
};



