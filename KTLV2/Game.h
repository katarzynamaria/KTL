#pragma once

struct Node
{
	int value;			//jego wartoœæ
	int colour;			//przypisany kolor: domyœlnie 0
	double potential;	// funkcje potencjalu jeszcze wymyslimy ;)
	int degree;		 // liczba ciagow do ktorych nalezy

						//konstruktory
	Node() : value(0), colour(0), potential(0), degree(0) {};
	Node(int v, int col = 0, double pot = 0) : value(v), colour(col), potential(pot) {};

	//do porownywania wierzcholkow (do sorta)
	bool operator==(const Node& v) const {
		return v.value == value;
	}
	bool operator<(Node& rv) {
		return value < rv.value;
	}

	//do odejmowania wartoœci
	int operator-(Node& rv) {
		return value - rv.value;
	}

	void setDegree(Gameboard&);
	void setPotential(int);

};

class Game
{
public:
	Game();
	~Game();

	void GameStart(int&, int&, int&);			// zczytuje parametry od u¿ytkownika, tworzy Gameboard, Gracza1, Gracza2
												// wyœwietla wylosowan¹ plansze (wrzucona do Gameboard)
	bool EndOfGame(Player&, Player&);			// sprawdza czy ktorys z graczy nie wygral (w zale¿noœci od strategii gracza)
	void ShowStatus(Gameboard&);							// pokazuje statystyki gry w danym momencie	
//	void PlayerMove(Player& p);  // wykonuje ruch gracza
	
};
