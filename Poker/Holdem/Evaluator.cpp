#include "Evaluator.h"


Evaluator::Evaluator() 
{

}


void Evaluator::setBoard(const std::deque<card>& tableBoard)
{
	board = tableBoard;
	boardFlushAvail = testBoardForFlush();
	boardStraightAvail = testBoardForStraight();
}

bool Evaluator::testBoardForFlush() {
	int suitCounts[] = { 0, 0, 0, 0 };

	for (auto& boardCard : board) {
		if (++suitCounts[boardCard.getSuitValue()] >= 3) {
			return true;
		}
	}
	return false;
}

bool Evaluator::isFlushPossible()
{	
	return boardFlushAvail;
}

bool Evaluator::testBoardForStraight() {
	int gapCounter = 0;
	bool possible = false;

	for (int i = 2; i < board.size(); i++) {
		int spread = board[i].getRankValue() - board[i - 2].getRankValue();
		int internalspread = board[i].getRankValue() - board[i - 1].getRankValue();
		if (spread <= 3 && spread >= 2 && internalspread != 0) {
			return true;
		}
	}

	return false;

}

void Evaluator::resortForALow() {

}

bool Evaluator::isStraightPossible()
{
	return boardStraightAvail;
}

void Evaluator::sortBoard()
{
	int minIndex, startScan = 0;
	card minCard;
	minCard.setcard(0);

	for (startScan = 0; startScan < board.size(); startScan++) {
		minIndex = startScan;
		minCard = board[startScan];

		for (int index = startScan + 1; index < board.size(); index++) {
			if (board[index].getRankValue() < minCard.getRankValue()) {
				minCard = board[index];
				minIndex = index;
			}
		}
		board[minIndex] = board[startScan];
		board[startScan] = minCard;
	}

	for (auto& boardCard : board) {
		if (boardCard != board.front()) {
			std::cout << ", ";
		}
		std::cout << boardCard.showCard();
	}
	std::cout << "\n\n";
}
