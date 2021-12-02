#pragma once

#include <iostream>
#include <string>
#include "card.h"
#include "deck.h"
#include "player.h"

using namespace std;


class Evaluator
{
private:
	card board[5];

public:
	Evaluator();

	void preCheckBoard(card tableBoard[]);

	bool isFlushPossible(card unsorted[]);
};

