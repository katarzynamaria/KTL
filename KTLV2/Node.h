#pragma once
#include <vector>
using namespace std;

struct Node
{

	int value;			 //jego wartoœæ
	int colour;			 //przypisany kolor: domyœlnie 0
	double potential;	 // funkcje potencjalu jeszcze wymyslimy ;)
	vector<int> degree;	 // indeksy wierszy z hipergrafu w których dany node siê znajduje

					 //konstruktory
	Node() : value(0), colour(0), potential(0){};
	Node(int v, int col = 0) : value(v), colour(col){};

	//do porownywania wierzcholkow (do sorta)
	bool operator==(const Node& v) const {
		return v.value == value;
	}
	bool operator<(Node& rv) {
		return value < rv.value;
	}

	//do odejmowania wartoœci
	int operator-(Node& rv)
	{
		return value - rv.value;
	}
	void setPotential() { potential=pow(2, -1*(this->degree.size())); }
	//int setDegree(int ,vector<vector<int>> h);
	//void setPotential(int);
};
