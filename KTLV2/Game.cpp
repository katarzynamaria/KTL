#include "Game.h"
#include <iostream>

using namespace std;

Game::Game()
{
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

}



bool Game::EndOfGame()
{
	if (p1.IsWinner())
	{
		cout << "--------KONIEC GRY---------" << endl;
		cout << "wygrywa gracz 1" << endl;
		return true;
	}
	if (p2.IsWinner() && !p1.IsWinner())	//jesli breaker ma juz wszystkie ruchy za soba, a Maker dalej nie wygral
	{									//albo jesli drugi tez jest Makerem to logiczne ze pierwszy nie wygrywa ;)
		cout << "--------KONIEC GRY---------" << endl;
		cout << "wygrywa gracz 2" << endl;
		return true;
	}
	return false;
}

void Game::ShowStatus(Gameboard& gb)
{
	//to nie wszystko, jeszcze cos sie na pewno pojawi
	gb.ShowGameboard();
}


//void Game::PlayerMove(Player& p)
//{
//p.changeCurrentLenght();
//}

void Node::setDegree(Gameboard& g)
{
	//pewnie to zmienie jeszcze
	vector<vector<int>> h = g.GetHypergraph();
	int n = g.GetSequenceLenght();
	//int m = 0;
	for (int i = 0; i < h.size(); i++)
	{
		int m = h.size() - g.GetSequenceLenght();
		while (m > 0)
		{
			for (int j = m; j < n; j++)
			{
				if (h[i][j] == value) degree++;
			}
			m--;
		}
	}
}

void Node::setPotential(int p)
{
	if (potential == 0)
	{
		potential = (double)(degree / pow(2, p));
		return;
	}
	potential = p;
}