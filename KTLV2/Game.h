#pragma once
#include "Gameboard.h"

class Game
{
	int range;				//przedzial z kt�rego losujemy liczby	
	int sequenceLenght;		// d�ugo�� ci�gu arytmetycznego
	int setCard;			//
	int strategy;						// moc zbiotu
	Gameboard gb;
public:
	Game(int x, int k, int strategy);
	~Game();
	
	void GameStart(int&, int&, int&);			// zczytuje parametry od u�ytkownika, tworzy Gameboard, Gracza1, Gracza2
	bool ifWinner;                              //czy mamy ju� zwyci�zce
	bool EndOfGame();				  // sprawdza czy ktorys z graczy nie wygral (w zale�no�ci od strategii gracza)
	void ShowStatus();			// pokazuje statystyki gry w danym momencie	
	void PlayerMove(int k);										//	void PlayerMove(Player& p);  // wykonuje ruch gracza (do napisania)

};