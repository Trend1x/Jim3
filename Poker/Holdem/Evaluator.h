#pragma once

#include <iostream>
#include <string>
#include "card.h"
#include "deck.h"
#include "player.h"
#include <deque>


enum HandRank
{
    ROYAL_FLUSH,
    STRAIGHT_FLUSH,
    FOUR_OF_A_KIND,
    FULL_HOUSE,
    FLUSH,
    STRAIGHT,
    THREE_OF_A_KIND,
    TWO_PAIR,
    PAIR,
    HIGH_CARD
};

class Evaluator
{
private:
	std::deque<card> board;
	bool boardFlushAvail;
    bool boardStraightAvail;

    bool testBoardForFlush();
    bool testBoardForStraight();

    void resortForALow();

public:
	Evaluator();
	void setBoard(const std::deque<card>& tableBoard);

	bool isFlushPossible();
    
    bool isStraightPossible();
    void sortBoard();
};

