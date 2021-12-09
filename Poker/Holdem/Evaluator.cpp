#include "Evaluator.h"


Evaluator::Evaluator() 
{

}


void Evaluator::setBoard(const std::deque<card>& tableBoard)
{
	board = tableBoard;
	//boardFlushAvail = testBoardForFlush();
	//boardStraightAvail = testBoardForStraight();
}



bool Evaluator::isFlushPossible()
{	
	return boardFlushAvail;
}


void Evaluator::resortForALow() {

}

bool Evaluator::isStraightPossible()
{
	return boardStraightAvail;
}


std::deque<card> Evaluator::insertHoleCards(const std::deque<card>& holeCards) {
	std::deque<card> fullHand(board);
	for (auto card : holeCards) {
		for (auto it = fullHand.begin(); it != fullHand.end(); it++) {
			if (card.getRankValue() > fullHand.back().getRankValue())
			{
				fullHand.emplace_back(card);
				break;
			}
			else if (card.getRankValue() <= it->getRankValue()) {
				it = fullHand.insert(it, card);
				break;
			}
		}
	}

	//std::cout << "Player hole cards inserted:\n";
	for (auto& boardCard : fullHand) {
		if (boardCard != fullHand.front()) {
			std::cout << ", ";
		}
		std::cout << boardCard.showCard();
	}
	std::cout << "\n";


	return fullHand;


}




void Evaluator::evaluatePlayerHand(const std::deque<card>& holeCards)
{
	std::deque<card> fullHand = insertHoleCards(holeCards);
	if (IsFlush(fullHand))
	{
		std::cout << "Flush\n";
	}
	if (IsStraight(fullHand))
	{
		std::cout << "Straight\n";
	}

	GroupHands(fullHand);
	std::cout << "\n";

}

bool Evaluator::IsFlush(std::deque<card>& fullHand) {
	int suitCounts[] = { 0, 0, 0, 0 };

	for (auto& boardCard : fullHand) 
	{
		suitCounts[boardCard.getSuitValue()]++;
	}

	for (auto& suit : suitCounts)
	{
		if (suit >= 5) {
			return true;
		}
	}
	return false;
}



bool Evaluator::IsStraight(std::deque<card>& fullHand)
{
	int sequenceCounter = 0;
	card highcard;
	bool straightFound = false;
	for (int i = 1; i < fullHand.size(); i++) {
		if (fullHand[i].getRankValue() - fullHand[i - 1].getRankValue() == 1) {
			sequenceCounter++;
			highcard = fullHand[i];
		}
		else if (fullHand[i].getRankValue() - fullHand[i - 1].getRankValue() == 0) {
			continue;
		}
		else {
			sequenceCounter = 0;
		}
		if (sequenceCounter == 4) {
			straightFound = true;
		}

	}

	return straightFound;

}


void Evaluator::GroupHands(std::deque<card>& fullHand)
{
	card currentCard;
	card lastCard;
	int currentCardValue;
	int lastCardValue;

	std::vector<int> matches;
	matches.push_back(0);
	for (int i = 1; i < fullHand.size(); i++)
	{
		lastCard = fullHand[i - 1];
		lastCardValue = lastCard.getRankValue();
		currentCard = fullHand[i];
		currentCardValue = currentCard.getRankValue();

		
		if (currentCardValue == lastCardValue) 
		{
			matches.back()++;
		}
		else
		{
			if (matches.back() > 0)
			{
				matches.push_back(0);
			}
		}
	}

	std::cout << "Matches:";

	for (auto& match : matches)
	{
		std::cout << match << ", ";
	}
	
	std::cout << std::endl;
	bool quads = false;
	bool fullhouse = false;
	bool trips = false;
	bool twoPair = false;
	bool onePair = false;

	for (auto& match : matches)
	{
		if (match == 3) 
		{
			quads = true;

			//set others to false b/c quads overrides
			fullhouse = false;
			trips = false;
			twoPair = false;
			onePair = false;

		}
		else if (match == 2)
		{
			if (onePair || twoPair) {
				fullhouse = true;

				trips = false;
				twoPair = false;
				onePair = false;
				
			}
			else 
			{
				trips = true;
			}

		}
		else if (match == 1) {
			if (onePair || twoPair) {
				twoPair = true;
				
				onePair = false;
			}
			else
			{
				onePair = true;
			}
		}
		
	}
	if (quads)
	{
		std::cout << "QUADS!\n";
	}
	if (fullhouse)
	{
		std::cout << "Full House!\n";
	}
	if (trips)
	{
		std::cout << "Trips!\n";
	}
	if (twoPair)
	{
		std::cout << "Two Pair!\n";
	}
	if (onePair)
	{
		std::cout << "One Pair!\n";
	}


}