#pragma once
#include <vector>
#include <iostream>
using namespace std;

#pragma once
#include <vector>
#include <iostream>
using namespace std;

struct Node
{

	int value;			 //jego wartosc
	int colour;			 //przypisany kolor: domyslnie 0
	vector<int> degree;	 // indeksy wierszy z hipergrafu w których dany node sie znajduje
	double gValue;		 //suma potencjalow wszystkich ciagow w do ktorych nalezy wierzcholek


						 //konstruktory
	Node() : value(0), colour(0), gValue(0) {};
	Node(int v, int col = 0) : value(v), colour(col), gValue(0) {};

	//do porownywania wierzcholkow
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
	}
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