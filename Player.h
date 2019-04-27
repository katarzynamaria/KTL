#pragma once
#include "Game.h"

class Player : public Game, public Gameboard
{
	int type;		//Maker, Breaker(1) lub (2) typu
public:
	Player();
	~Player();
	
	void ShowMove();

	Node ChooseNode();			//zwraca najlepszy ruch w danym momencie
	void TakeNode();			//zmienia prametr colour w Node na swoj
	void ChangePotential();		//zmienia parametr potential w Node

	//moze cos wiecej moze cos mniej :)

};

