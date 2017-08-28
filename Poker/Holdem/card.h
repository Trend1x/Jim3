#pragma once

#include <string>

class card
{
private:
		int rank;
		int suit;

	
public:
		std::string getSuitName();
		char getRankChar();
		void setcard(int rnk, int st);
		
		~card();

};


