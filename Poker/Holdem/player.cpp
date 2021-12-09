#include "player.h"



player::player(){
}

void player::dealPlayerHoleCard(card deltCard){
	holeCard.emplace_back(deltCard);
}

void player::setPlayerName(std::string playerName){
	name = playerName;
}

card player::getHoleCard(int holeCardNum){
	return holeCard[holeCardNum];
}

std::deque<card> player::getHoleCards() {
	return holeCard;
	
}


void player::showHoleCards() {
	std::cout << name << " has " << holeCard[0].showCard() << " \tand " << holeCard[1].showCard() << std::endl;
}

void player::clearPlayerHoleCards() {
	holeCard.clear();
}


std::string player::getPlayerName()
{
	return name;
}

player::~player(){
}
