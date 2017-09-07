#pragma once

#include <iostream>
#include "card.h"
#include <string>

using namespace std;
class player
{
private:
	string name;
	card holeCard[2];

public:
	player();
	void setCard(int holeCardNum, card deltCard);
	void setPlayerName(string playerName);
	card getHoleCard(int holeCardNum);
	void showHoleCards();
	string getPlayerName();


	~player();
};

