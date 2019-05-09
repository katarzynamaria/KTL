#pragma once
#include "Strategy.h"

class Player
{
	vector<int> positions; //liczby ktore wybral
	int colour;
	Game* gra;
	Strategy* strategy;		//Maker, Breaker(1) lub (2) typu
	Gameboard gb;
public:
	Player(Strategy* s, Gameboard& g, int c);
	~Player();

	void GetGame();
	void ShowMove();
	void TakeNode();							//zmienia prametr colour w Node na swoj
	void ChangePotential(Node& moveMade);		//zmienia parametr potential w Node
	bool IsWinner();

};