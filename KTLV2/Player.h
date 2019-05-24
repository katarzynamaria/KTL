#pragma once
#include "Strategy.h"

class Player
{
	int colour;
	Strategy* strategy;		//Maker, Breaker(1) lub (2) typu
	Gameboard* gb;
public:
	Player(Strategy* s, Gameboard* g, int c);
	~Player() {};


	void TakeNode();							//zmienia prametr colour w Node na swoj
	bool IsWinner();
};
	