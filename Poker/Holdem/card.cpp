#include "card.h"

card::card() {
	rank = -1;
	suit = -1;
}

card::card(int value) {
	rank = value % 13;
	suit = (int)floor(value / 13);
}


void card::setcard(int rnk, int st) {
	rank = rnk;
	suit = st;

}

void card::setcard(int mixedValue) {
	rank = mixedValue % 13;
	suit = (int)floor(mixedValue / 13);

}

void  card::operator=(const card& C) {
	this->rank = C.rank;
	this->suit = C.suit;

}

bool card::operator==(const card& C) {
	return this->rank == C.rank && this->suit == C.suit;
}

bool card::operator!=(const card& C) {
	return this->rank != C.rank || this->suit != C.suit;
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
	char rankchar[14] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
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
