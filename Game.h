#pragma once
#include "Gameboard.h"

struct Node
{
	int value;			//jego warto��
	int colour;			//przypisany kolor: domy�lnie 0
	double potential;	// funkcje potencjalu jeszcze wymyslimy ;)
	//int degree;		 // liczba ciagow do ktorych nalezy

	//konstruktory
	Node() : value(0), colour(0), potential(0) {};
	Node(int v, int col = 0, double pot = 0) : value(v), colour(col), potential(pot) {};

	//do porownywania wierzcholkow (do sorta)
	bool operator==(const Node &v) const {
		return v.value == value;
	}
	bool operator<(Node &rv) {
		return value < rv.value;
	}

	//do odejmowania warto�ci
	int operator-(Node &rv){
		return value - rv.value;
	}

};

class Game : public Gameboard	
{
	int strategy;
public:
	Game();
	~Game();

	void GameStart();			// zczytuje parametry od u�ytkownika, tworzy Gameboard, Gracza1, Gracza2
	//void ShowGameboard();		// wy�wietla wylosowan� plansze (wrzucona do Gameboard)
	bool EndOfGame();			// sprawdza czy ktorys z graczy nie wygral
	void ShowStatus();			// pokazuje statystyki gry w danym momencie
	void ShowWinner();			// (opcjonalnie) pokazuje zwyci�zce po zako�czeniu rozgrywki
	void PlayerMove(Player& p);  // wykonuje ruch gracza

	//moze cos jeszcze moze mniej ;)
};

