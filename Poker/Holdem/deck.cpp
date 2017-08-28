#include "deck.h"


deck::deck(){
	srand(time(0));	//seeds rng
}


deck::~deck(){
}

void deck::makeDeck(){
	for (int i = 0; i < DECK_SIZE; i++) {
		dk[i].setcard((i % 13), ((int)floor(i / 13)));
	}
}

void deck::displayDeck() {
	for (int i = 0; i < DECK_SIZE; i++) {
		cout << dk[i].getRankChar() << " of " << dk[i].getSuitName() << "s." << endl;
	}
}

void deck::shuffleDeck() {
	//fragment later

	//calculate split location 1/2 +/-5

	int halfpoint = (DECK_SIZE / 2) + ((rand() % 10) - 5);
	cout << "DEBUG: Half point = " << halfpoint << endl;
	int UPPER_SIZE = halfpoint;
	int LOWER_SIZE = DECK_SIZE - halfpoint;

	//create sub decks  half1, half2 shuffled(integers for indecies of master)
	int shuffled[DECK_SIZE];
	card tempDeck[DECK_SIZE];
	
	//save original deck in temp location
	for (int i = 0; i < DECK_SIZE; i++) {
		tempDeck[i] = dk[i];
	}
	//coin flip which half goes first
	int start = rand() % 2;

	//shuffle halfs into shuffled 1-3 from each side alternating
	int index = 0;
	int upperIndex = 0;
	int lowerIndex = halfpoint;
	int clump;
	int clumpIndex;
	while (index < DECK_SIZE) {
		if (index == 0) {
			if (start = 1) {
				clump = rand() % 3;
				for (int i = 0; i <= clump; i++) {
					shuffled[index] = lowerIndex;
					index++;
					lowerIndex++;
				}
			}
			clump = rand() % 3;
			while((upperIndex < halfpoint)&&(clumpIndex <= clump)){
				shuffled[index] = upperIndex;
				index++;
				upperIndex++;
				clumpIndex++;
				}
			clumpIndex = 0;
			clump = rand() % 3;
			while((lowerIndex < DECK_SIZE)&&(clumpIndex <= clump)){
					shuffled[index] = lowerIndex;
					index++;
					lowerIndex++;
					clumpIndex++;
				}
			clumpIndex = 0;
		}
	}

	for (int i = 0; i < DECK_SIZE; i++) {
		dk[i] = tempDeck[shuffled[i]];
	}
	//??Reasign master based on indecies of shuffled or only return shuffled??






}

