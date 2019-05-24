#pragma once
#include "Player.h"
class Game
{
	int range;				 //przedzial z którego losujemy liczby	
	int sequenceLenght;		 //dlugosc ciagu arytmetycznego
	int setCard;			 //
	int strategy;			 // moc zbioru
	Gameboard* gb;
	vector<Player*> players;
public:
	Game(int x, int k, int strategy, Gameboard* gb);
	~Game();
	int  LastColour;
	bool isWinner(int k);                         
	bool EndOfGame();						    // sprawdza czy ktorys z graczy nie wygral
	void ShowStatus();							// pokazuje statystyki gry w danym momencie	
	void PlayerMove(int k);						// wykonuje ruch gracza
	void LastPlayer() { gb->LastColour = gb->GetSetX()[gb->LastMove()].colour; } //kto ostatni gral
	void AddPlayer(Strategy*, int colour);		// zajmuje sie dodaniem Graczy do gry
};