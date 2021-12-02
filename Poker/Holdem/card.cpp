#include "card.h"

void card::setcard(int rnk, int st) {
	rank = rnk;
	suit = st;

}

void card::setcard(int mixedValue) {
	rank = mixedValue % 13;
	suit = (int)floor(mixedValue / 13);

}


std::string card::showCard(){
	std::string temp;
	temp += getRankChar();
	temp += " of ";
	temp += getSuitName();
	temp += "s";
	//dk[i].getRankChar() << " of " << dk[i].getSuitName() << "s." << endl;
	return temp;
}


char card::getRankChar() {
	char rankchar[13] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };
	return rankchar[rank];
}

int card::getRankValue(){
	return rank;
}


/**
* Returns true if the card has a valid rank and suit
*/
bool card::isValidCard()
{
	return rank >= 0 && rank < 13 && suit >= 0 && suit < 4;
}

std::string card::getSuitName() {
	std::string suitname[4] = { "Spade" , "Heart", "Club", "Diamond" };
	return suitname[suit];
}

int card::getSuitValue() {
	return suit;
}


card::~card()
{
}
