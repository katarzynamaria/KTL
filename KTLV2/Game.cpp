#include "Game.h"
#include <iostream>

using namespace std;

Game::Game(int x, int k, int strategy) : gb(k, x, k*x)
{	
	this->strategy = strategy;
	cout << "skonczylem tworzyc plansze" << endl;
}

Game::~Game()
{
}

bool Game::isWinner(int k)
{
	return players[k]->IsWinner();
}

void Game::GameStart(int &k, int &x, int& strategy)
{ 
	cout << "----------- START GRY -----------" << endl;
	cout << "Moc zbioru X: ";
	cin >> x;
	cout << "Dlugosc ciagu: ";
	cin >> k;
	cout << "Strategie gracza: " << endl;
	cout << "1 - agresywny vs agresywny" << endl;
	cout << "2 - agresywny vs defensywny(naiwny)" << endl;
	cout << "3 - agresywny vs defensywny" << endl;
	cout << "Wybrana strategia: ";
	cin >> strategy;

	cout << "skonczylem tworzyc plansze" << endl;
}



bool Game::EndOfGame()
{

	if (isWinner(0) || isWinner(1) )
{	cout << "Wygrywa gracz " << gb.LastColour << endl;
	return true;
}
	return false;
}

void Game::ShowStatus()
{
	//to nie wszystko, jeszcze cos sie na pewno pojawi  CIEKAWWE KIEDY x

	gb.ShowGameboard();
}

void Game::PlayerMove(int k) //gracz-0 lub 1
{
	players[k]->TakeNode();
	cout << "RUCH GRACZA: " << k+1 << endl;
	cout << gb.LastMove() << endl;

}

void Game::AddPlayer(Strategy* st,int colour)
{
	Player* player = new Player(st, gb,colour);
	players.push_back(player);
}



