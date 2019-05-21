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
	if (ifWinner)
	{
		cout << "wygrywa grzacz " << gb.LastMove() << endl;
		return true;
	}
	return false;
}

void Game::ShowStatus()
{
	//to nie wszystko, jeszcze cos sie na pewno pojawi
	gb.ShowGameboard();
}

void Game::PlayerMove(int k) 
{
	cout << "RUCH GRACZA: " << k << endl;

}


//void Game::PlayerMove(Player& p)
//{
//p.changeCurrentLenght();
//}

