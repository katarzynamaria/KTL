#pragma once
#include "Gameboard.h"

class Strategy
{
public:

	virtual int ChooseNode(vector<vector<Node*>>&, Gameboard*) = 0;				//zwracamy indeks w setX;
	virtual void ChangePotential(vector<vector<Node*>>& hyp, Gameboard*) = 0;	//zmiana potencjalu zalezy od strategii (jak maker to wzrasta o 1/2^k, jak breaker to maleje o tyle samo lub 0)
};

class Maker : public Strategy
{
public:

	virtual int ChooseNode(vector<vector<Node*>>&, Gameboard*);
	virtual void ChangePotential(vector<vector<Node*>>& hyp, Gameboard*);

};

class BreakerEasy : public Strategy							//breaker strategii parujacej
{
public:
	virtual int ChooseNode(vector<vector<Node*>>&, Gameboard*);
	virtual void ChangePotential(vector<vector<Node*>>& hyp, Gameboard*);

};

class BreakerHard : public Strategy							//strategii potencjalow
{
public:
	virtual int ChooseNode(vector<vector<Node*>>&, Gameboard*);
	virtual void ChangePotential(vector<vector<Node*>>& hyp, Gameboard*);

};