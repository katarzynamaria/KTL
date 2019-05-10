#pragma once
#include "Gameboard.h"

class Game
{

public:
	Game();
	~Game();

	void GameStart(int&, int&, int&);			// zczytuje parametry od użytkownika, tworzy Gameboard, Gracza1, Gracza2
	bool EndOfGame();			// sprawdza czy ktorys z graczy nie wygral (w zależności od strategii gracza)
	void ShowStatus(Gameboard&);							// pokazuje statystyki gry w danym momencie	
															//	void PlayerMove(Player& p);  // wykonuje ruch gracza (do napisania)

};