#pragma once
#include "Game.h"
#include "Strategy.h"


class Player //doszlam do wniosku ze moze Player gry nie potrzebuje
{
	Strategy& type;		//Maker, Breaker(1) lub (2) typu
	Gameboard& gb;
public:
	Player(Strategy& s, Gameboard& g) : type(s), gb(g) {};
	~Player();
	

	void ShowMove();

	void TakeNode();			//zmienia prametr colour w Node na swoj
	void ChangePotential();		//zmienia parametr potential w Node

	//moze cos wiecej moze cos mniej :)

};

