#pragma once

#include <iostream>
#include <string>
#include "card.h"
#include "deck.h"
#include "player.h"

using namespace std;

class table
{

private:
	player seat[9];
	deck mainDeck;
	card flop[3];
	card turn;
	card river;
	card board[5];
	int numPlayers;
	void burn();
	

public:
	table();
	~table();
	
	//deck things
	void dealCards();
	void dealFlop();
	void dealTurn();
	void dealRiver();
	
	//void showFlop();
	//void showTurn();
	//void showRiver();

	void showBoard(string street);

	void shuffleCards(int shuffleCount);

	//player things
	int playerCount();
	void setPlayer(int seatNum, string playerName);
	void playerCards(int seatNum);

};

