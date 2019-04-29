#pragma once
#include "Game.h"
#include "Strategy.h"
#include "Gameboard.h"

class Player //doszlam do wniosku ze moze Player gry nie potrzebuje
{
	int colour;
	Strategy* strategy;		//Maker, Breaker(1) lub (2) typu
	Gameboard gb;
public:
	Player(Strategy* s, Gameboard& g);
	~Player();

	void ShowMove();

	void TakeNode();			//zmienia prametr colour w Node na swoj
	void ChangePotential();		//zmienia parametr potential w Node
	Node ChooseNode();
	//moze cos wiecej moze cos mniej :)

};
