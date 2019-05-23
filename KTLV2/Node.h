#pragma once
#include <vector>
#include <iostream>
using namespace std;

struct Node
{

	int value;			 //jego warto??
	int colour;			 //przypisany kolor: domy?lnie 0
	vector<int> degree;	 // indeksy wierszy z hipergrafu w których dany node si? znajduje
	bool visited;		 //	czy dany wierzcholek zostal wybrany
	double gValue;		 //suma potencjalow wszystkich ciagow w do ktorych nalezy wierzcholek
						 
						 
						 //konstruktory
	Node() : value(0), colour(0), gValue(0), visited(0) {};
	Node(int v, int col = 0) : value(v), colour(col), gValue(0), visited(0) {};

	//do porownywania wierzcholkow (do sorta)
	bool operator==(const Node& v) const {
		return v.value == value;
	}
	bool operator<(Node& rv) {
		return value < rv.value;
	}

	//do odejmowania warto?ci
	int operator-(Node& rv)
	{
		return value - rv.value;
	}
	void setDegree(vector<Node*>* values, int iter)
	{
		vector<Node*> v = *values;
		for (int i = 0; i < values->size(); ++i)
		{

			if (v[i]->value == this->value) degree.push_back(iter);
		}
	}//jezeli dana wartosc jest równa wierzcholkowi to zapisujemy wiersz w degree}

	

	void setgValue(vector<double>& potential)
	{
		double k = 0;
		for (int i = 0; i < degree.size(); i++)
		{
			k += potential[degree[i]];
		}
		gValue = k;
	}
};