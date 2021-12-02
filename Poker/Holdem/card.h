#pragma once

#include <string>



class card
{
private:
		int rank;
		int suit;

public:
		bool isValidCard();
		std::string getSuitName();
		int getSuitValue();
		char getRankChar();
		int getRankValue();
		void setcard(int rnk, int st);
		void setcard(int mixedValue);
		std::string showCard();
		~card();

};


