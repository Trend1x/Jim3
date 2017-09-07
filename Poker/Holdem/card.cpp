#include "card.h"

void card::setcard(int rnk, int st) {
	rank = rnk;
	suit = st;

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

std::string card::getSuitName() {
	std::string suitname[4] = { "Spade" , "Heart", "Club", "Diamond" };
	return suitname[suit];
}


card::~card()
{
}
