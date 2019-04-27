#pragma once
#include "Player.h"
#include "Game.h"
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Gameboard		//zmienilam na pisane wszystko z malej litery - w mojej glowie ma to wiecej sensu, ale nie bede sie klocic jesli zmieni ktos xd
{
	int sequenceLenght;
	int setCard;
	int range;
	//vector<int> setX;
	vector<Node> setX;		//struktura Node w Game.h
	int** distMatrix;
	//vector<vector<int>> hypergraph;	//albo vector<Node> jeszcze nie przemyslalam

public:
	bool isValid();

	Gameboard(int sequenceLength= 0, int setCard = 0, int range = 1000);
	~Gameboard();
	void generateDistMatrix();

	Node LastMove(); // wyciaga jaki ruch byl ostatni (do strategi parujacej M-B(1))


private:

	bool isNext(int* tab, int x, int j);
	void generateSet();
	void getRandomNumbers();

	int getDistance(int x, int y)
	{
		return setX[x] - setX[y];		//przeci¹¿one odejmowanie (szczegoly w Game.h)
	}

};

