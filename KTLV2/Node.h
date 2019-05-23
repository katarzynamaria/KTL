#pragma once
#include <vector>
#include <iostream>
using namespace std;

struct Node
{

	int value;			 //jego warto??
	int colour;			 //przypisany kolor: domy?lnie 0
	double potential;	 // funkcje potencjalu jeszcze wymyslimy ;)
	vector<int> degree;	 // indeksy wierszy z hipergrafu w których dany node si? znajduje
	bool visited;		 //	czy dany wierzcho³ek zosta³ wybrany
						 //konstruktory
	Node() : value(0), colour(0), potential(0), visited(0) {};
	Node(int v, int col = 0) : value(v), colour(col), potential(0), visited(0) {};

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
	void setDegree(vector<int>* values, int iter)
	{
		vector<int> v = *values;
		for (int i = 0; i < values->size();++i)
		{

			if (v[i] == this->value) degree.push_back(iter);
		}
	}//je¿eli dana wartoœæ jest równa wierzcho³kowi to zapisujemy wiersz w degree}
	
	void setPotential() 
	{ 
		if (this->degree.size() != 0) potential = pow(2, -1 * (int)(this->degree.size()));
	}
};
