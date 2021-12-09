#pragma once

#include <iostream>
#include "card.h"
#include <string>
#include <deque>
#include <array>

class player
{
private:
	std::string name;
	std::deque<card> holeCard;
	std::array<card, 2> holeCardArray;

public:
	player();
	void dealPlayerHoleCard(card deltCard);
	void setPlayerName(std::string playerName);
	card getHoleCard(int holeCardNum);
	void showHoleCards();
	std::string getPlayerName();
	void clearPlayerHoleCards();
	std::deque<card> getHoleCards();

	~player();
};

