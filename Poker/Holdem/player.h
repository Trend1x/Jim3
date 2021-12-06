#pragma once

#include <iostream>
#include "card.h"
#include <string>

class player
{
private:
	std::string name;
	card holeCard[2];

public:
	player();
	void setCard(int holeCardNum, card deltCard);
	void setPlayerName(std::string playerName);
	card getHoleCard(int holeCardNum);
	void showHoleCards();
	std::string getPlayerName();


	~player();
};

