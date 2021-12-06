#pragma once

#include <string>

class card
{
private:
	int rank;
	int suit;

public:
	card();
	card(int value);
	void operator=(const card& C);
	bool operator==(const card& C);
	bool operator!=(const card& C);
	

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


