﻿#pragma once
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include "Node.h"

using namespace std;

class Gameboard
{
	vector<Node> setX;		//struktura Node w Game.h
	int** distMatrix;
	int range;
	int sequenceLenght;
	int setCard;
	vector<vector<int>> hypergraph;



	int lastColoredField;

public:

	Gameboard(int sequenceLength = 4, int setCard = 100, int range = 1000);
	~Gameboard();		//dodalam usuwanie tablicy dynamicznej


	void generateDistMatrix();
	bool isValid();
	int LastMove();				// wyciaga jaki ruch byl ostatni (do strategi parujacej M-B(1))
	void ShowGameboard();

	//gety
	vector<Node> GetSetX() { return this->setX; }
	int GetSequenceLenght() { return this->sequenceLenght; }
	vector<vector<int>> GetHypergraph() { return this->hypergraph; }

	void colorField(int index, int colour)
	{
		lastColoredField = index;
		setX[index].colour = colour;
	};

private:

	bool isNext(int* tab, int x, int j);
	void generateSet();
	void getRandomNumbers();
	void generateHypergraph();
	int Abs(Node n, Node m)
	{
		if (n < m) return m - n;
		return n - m;
	}
	int getDistance(int x, int y)
	{
		return Abs(setX[x], setX[y]);		//przeci¹¿one odejmowanie (szczegoly w Game.h)
	}

};