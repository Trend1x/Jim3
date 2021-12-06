#pragma once

#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
#include "card.h"
#include "deck.h"
#include "player.h"
#include "Evaluator.h"

class table
{

private:
	player seat[9];
	deck mainDeck;
	std::deque<card> boardDeque;
	Evaluator eval;
	
	int numPlayers;
	void burn();
	void sortBoard();
	

public:
	table();
	~table();
	
	//Deals hole cards to the players.
	void dealPlayerHoleCards();

	//Burn a card and then deal the indicated number of cards to the board.
	void dealBoard(int numberOfCards);

	//Displays the board following the provided message to the console.
	void showBoard(std::string message);

	//Suffles the deck the provided number of times.
	void shuffleCards(int shuffleCount);

	//Returns the number of players at the table.
	int playerCount();

	// Sets the name of the player in a seat at the table.
	void setPlayer(int seatNum, std::string playerName);

	// Displays the hole cards of the indicated seated player to the console
	void showTablePlayerHoleCards(int seatNum);

	//Evaluate the board.
	void evaluateBoard();

};

