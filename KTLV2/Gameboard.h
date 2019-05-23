#pragma once
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
	vector<Node> setX;//struktura Node w Game.h
	int** distMatrix;		//macierz odległośći
	int range;				//przedzial z którego losujemy liczby	
	int sequenceLenght;		// długość ciągu arytmetycznego
	int setCard;			// moc zbioru, który bedzimy kolorować
	vector<vector<Node*>> hypergraph; //hipergraf przechowujący ciągi arytmetyczne w grze
	int lastColoredField;	//przechowuje ostatni wierzchołek wykorzystany w grze

public:
	int LastColour;
	Gameboard(int sequenceLength = 4, int setCard = 30, int range = 100);
	void setDegrees(vector<Node*>&, int);
	~Gameboard();


	void generateDistMatrix();		//generuje macierz odległośći na podstawie danych wstepnych
	bool isValid();					//sprawdza czy dany zbior spełnia warunki aby rozpoczęła się gra
	int LastMove();				    // wyciaga jaki ruch byl ostatni (do strategi parujacej M-B(1))
	void ShowGameboard();			//pokazuje aktualny stan gry
									//gety- do wydobywania prywatnych wartości
	vector<Node> GetSetX() { return this->setX; }

	int GetSequenceLenght() { return this->sequenceLenght; }

	vector<vector<Node*>> GetHypergraph() { return this->hypergraph; }

	void colorField(int index, int colour);
	int findIndexOf(int value);
	vector<int> sequencePotetial;
private:
	int isNext(int* tab, int x, int j); //sprawdza czy kolejny wierzchołek jest kolejnym elementem ciągu arytmetycznego, dla którego x jest poprzednim wyrazem 
	void generateSet();					// generuje zbiór liczb do kolorowania
	void getRandomNumbers();			//do tworzenia ciągów liczb losowych
	void generateHypergraph();			// tworzy hipergraf
	
	int Abs(Node n, Node m)
	{
		if (n < m) return m - n;
		return n - m;
	}

	int getDistance(int x, int y)
	{
		return Abs(setX[x], setX[y]);		//przeciazone odejmowanie (szczegoly w Game.h)
	}

	void showHypergraph();
	void setPotentials();
	Node* findNodeWithValue(int value);
};

