#include "player.h"



player::player(){
}

void player::setCard(int holeCardNum, card deltCard){
	holeCard[holeCardNum] = deltCard;
}

void player::setPlayerName(std::string playerName){
	name = playerName;
}

card player::getHoleCard(int holeCardNum){
	return holeCard[holeCardNum];
}

void player::showHoleCards() {
	std::cout << name << " has " << holeCard[0].showCard() << " \tand " << holeCard[1].showCard() << std::endl;
	

}

std::string player::getPlayerName()
{
	return name;
}

player::~player(){
}
