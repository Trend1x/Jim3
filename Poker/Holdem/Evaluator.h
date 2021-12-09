#pragma once

#include <iostream>
#include <string>
#include "card.h"
#include "deck.h"
#include "player.h"
#include <deque>
#include <vector>


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

    bool IsFlush(std::deque<card>& fullHand);
    bool IsStraight(std::deque<card>& fullHand);

    void GroupHands(std::deque<card>& fullHand);

    void resortForALow();
    std::deque<card> insertHoleCards(const std::deque<card>& holeCards);

public:
	Evaluator();
	void setBoard(const std::deque<card>& tableBoard);
    bool isFlushPossible();
    bool isStraightPossible();

    void evaluatePlayerHand(const std::deque<card>& holeCards);
    
};


