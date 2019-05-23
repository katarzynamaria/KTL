#include "Game.h"
#include <iostream>

using namespace std;

Game::Game(int x, int k, int strategy, Gameboard* g)
{
	gb = g;
	this->strategy = strategy;

	cout << "skonczylem tworzyc plansze" << endl;
}

Game::~Game()
{
}

bool Game::isWinner(int k)  //sprawdza czy dany gracz jest zwyciezca
{
	return players[k]->IsWinner();
}


bool Game::EndOfGame()  //konczy gre jezeli ktorys z graczy jest zwyciezca +trzeba koñczyæ jezeli ju¿ nie ma ruchów
{

	if (isWinner(0) || isWinner(1))
	{
		cout << "Wygrywa gracz " << gb->LastColour + 1 << endl;
		return true;
	}

	if (gb->seqYetToChoose == 0)
	{
		cout << "Koniec ciagow " << endl;
		system("pause");
		return true;
	}
	return false;
}

void Game::ShowStatus()   //wypisuje plansze
{
	gb->ShowGameboard();
}

void Game::PlayerMove(int k) //gracz-0 lub 1
{
	players[k]->TakeNode();
	cout << "RUCH GRACZA: " << k + 1 << endl;
	cout << gb->LastMove() << endl;
	system("pause");

}

void Game::AddPlayer(Strategy* st, int colour) //dodaje graczy do Gry
{
	Player* player = new Player(st, gb, colour);
	players.push_back(player);
}
