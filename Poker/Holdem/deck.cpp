#include "deck.h"




deck::deck(){
	srand(time(0));	//seeds rng
	deckPos = 0;
}


deck::~deck(){
}

void deck::makeDeck(){
	for (int i = 0; i < DECK_SIZE; i++) {
		dk[i].setcard(i);
	}
}

void deck::displayDeck() {
	for (int i = 0; i < DECK_SIZE; i++) {
		cout << dk[i].showCard() << "." << endl;
	}
}



void deck::shuffleDeck() {
	//fragment later

	//calculate split location 1/2 +/-5
	int halfpoint = (DECK_SIZE / 2) + ((rand() % 10) - 5);
	int UPPER_SIZE = halfpoint;
	int LOWER_SIZE = DECK_SIZE - halfpoint;

	//create sub decks  half1, half2 shuffled(integers for indecies of master)
	int shuffled[DECK_SIZE];
	card tempDeck[DECK_SIZE];

	//save original deck in temp location
	for (int i = 0; i < DECK_SIZE; i++) {
		//cout << "DEBUG: Saving original deck index " << i << endl;
		tempDeck[i] = dk[i];
	}
	//coin flip which half goes first
	int start = rand() % 2;

	//shuffle halfs into shuffled 1-3 from each side alternating
	int index = 0;
	int upperIndex = 0;
	int lowerIndex = halfpoint;
	while (index < DECK_SIZE) {
		if (index == 0 && start == 1) {
			clumpDrop(index, lowerIndex, DECK_SIZE, tempDeck);
			/*check the coinflip to see which side goes first, IF the start is 1, the lower half goes first
			then the pattern begins with the upper and lower alternating. IF the start is 0, then jump straight
			alternating pattern*/
		}
		clumpDrop(index, upperIndex, halfpoint, tempDeck);
		clumpDrop(index, lowerIndex, DECK_SIZE, tempDeck);

		deckPos = 0;
	}
}

void deck::clumpDrop(int &currentIndex, int &halfIndex, int endPoint, card refrenceDeck[])
{
	int clump = rand() % 3;
	int clumpIndex = 0;
	while ((halfIndex < endPoint) && (clumpIndex++ <= clump)) {
		dk[currentIndex++] = refrenceDeck[halfIndex++];
	}
}

card deck::getCard(int index)
{
	return dk[index];
}

void deck::updateDeckPos(int newPos)
{
	//add some error checking and bounds later
	deckPos = newPos;
}

int deck::getDeckPos()
{
	return deckPos;
}

