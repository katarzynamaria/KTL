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
	vector<Node> setX;		
	int** distMatrix;		//macierz odległośći (pomocnicza)
	int range;				//przedzial z którego losujemy liczby	
	int sequenceLenght;		// długość ciągu arytmetycznego
	int setCard;			// moc zbioru, który bedzimy kolorować
	vector<vector<Node*>> hypergraph; //hipergraf przechowujący ciągi arytmetyczne w grze
	int lastColoredField;	//przechowuje ostatni wierzchołek wykorzystany w grze
public:
	int LastColour;
	int seqYetToChoose;
	vector<double> Potential;
	bool conti = 1;
	

	//konstruktory
	Gameboard(int sequenceLength = 4, int setCard = 30, int range = 100);
	void setDegrees(vector<Node*>&, int);
	~Gameboard();

	void SetPotential();
	void generateDistMatrix();		//generuje macierz odległośći na podstawie danych wstepnych
	bool isValid();					//sprawdza czy dany zbior spełnia warunki aby rozpoczęła się gra
	void setPotentials();

	//gety- do wydobywania prywatnych wartości
	vector<Node> GetSetX() { return this->setX; }
	int LastMove() {return lastColoredField;}
	int GetSequenceLenght() { return this->sequenceLenght; }
	vector<vector<Node*>> GetHypergraph() { return this->hypergraph; }

	void colorField(int index, int colour);		//przypisuje wartosc ostatniego pomalowanego wierzcholka zmennej lastColoredFiled 
	int findIndexOf(int value);					//znajduje pozycje elementu o wartosci value w zbiorze X 			
	Node* findNodeWithValue(int value);			//znajduje parametry wierzcholka o wartosci value
	void ShowGameboard();						//pokazuje aktualny stan gry

private:
	int isNext(int* tab, int x, int j); //sprawdza czy kolejny wierzchołek jest kolejnym elementem ciągu arytmetycznego, dla którego x jest poprzednim wyrazem 
	void generateSet();					// generuje zbiór liczb do kolorowania
	void getRandomNumbers();			//do tworzenia ciągów liczb losowych
	void generateHypergraph();			// tworzy hipergraf
	void showHypergraph();
	

	//pomocnicze
	int Abs(Node n, Node m)
	{
		if (n < m) return m - n;
		return n - m;
	}

	int getDistance(int x, int y)
	{
		return Abs(setX[x], setX[y]);		//przeciazone odejmowanie
	}

	

};