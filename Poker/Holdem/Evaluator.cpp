#include "Evaluator.h"


Evaluator::Evaluator() 
{



}

void Evaluator::preCheckBoard(card tableBoard[]) {

}

bool Evaluator::isFlushPossible(card unsorted[])
{	
	int spadeCount = 0;
	int heartCount = 0;
	int diamondCount = 0;
	int clubCount = 0;
	int suitCounts[] = { 0, 0, 0, 0 };
	for (int i = 0; i < 5; i++) {
		suitCounts[unsorted[i].getSuitValue()]++;
	}
	for (int j = 0; j < 4; j++) {
		if (suitCounts[j] >= 3)
			return true;
	}

	return false;

}