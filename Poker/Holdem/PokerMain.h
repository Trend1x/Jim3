#pragma once


#include "Shuffle.h"
#include "card.h"
#include "deck.h"
#include <iostream>
#include "player.h"

using namespace std;

int dealCards(deck deck1, player position[], int numPlayers);

int dealFlop(int deckPos, deck deck1);