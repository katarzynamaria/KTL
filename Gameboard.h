#pragma once
#include "Player.h"
#include "Game.h"
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Gameboard		//zmienilam na pisane wszystko z malej litery - w mojej glowie ma to wiecej sensu, ale nie bede sie klocic jesli zmieni ktos xd
{
	vector<Node> setX;		//struktura Node w Game.h
	int** distMatrix;
	int range;
	int sequenceLenght;
	int setCard;
	//vector<vector<int>> hypergraph;	//albo vector<Node> jeszcze nie przemyslalam
	//vector<int> setX;
public:
	
	Gameboard(int sequenceLength = 0, int setCard = 0, int range = 1000);
	~Gameboard();		//dodalam usuwanie tablicy dynamicznej


	void generateDistMatrix();
	bool isValid();
	Node LastMove(); // wyciaga jaki ruch byl ostatni (do strategi parujacej M-B(1))
	void ShowGameboard();

	//gety
	vector<Node> GetSetX() { return this->setX;}
	int GetSequenceLenght() { return this->sequenceLenght;}
	int** GetDistMatrix() { return this->distMatrix; }


private:

	bool isNext(int* tab, int x, int j);
	void generateSet();
	void getRandomNumbers();

	int getDistance(int x, int y)
	{
		return setX[x] - setX[y];		//przeci¹¿one odejmowanie (szczegoly w Game.h)
	}

};

