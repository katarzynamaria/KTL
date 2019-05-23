#pragma once
#include "Gameboard.h"

class Strategy
{
public:

	virtual int ChooseNode(vector<Node>&, Gameboard*) = 0;				//zwracamy indeks w setX;
															//virtual bool End(Gameboard, int) = 0;					//warunek wygranej w zale¿noœci od strategii
	virtual void ChangePotential(Node&, vector<Node>&, Gameboard*) = 0;	//zmiana potencjalu zalezy od strategii (jak maker to wzrasta o 1/2^k, jak breaker to maleje o tyle samo lub 0)
};

class Maker : public Strategy
{
public:

	virtual int ChooseNode(vector<Node>&, Gameboard*); 
	virtual void ChangePotential(Node&, vector<Node>&, Gameboard*);

};

class BreakerEasy : public Strategy							//breaker strategii parujacej
{
public:
	virtual int ChooseNode(vector<Node>&,Gameboard*);
	virtual void ChangePotential(Node&, vector<Node>&, Gameboard*);
	bool isStillGoodSequence(vector<Node> setXelem, Gameboard*);
};

class BreakerHard : public Strategy							//strategii potencjalow
{
public:
	virtual int ChooseNode(vector<Node>&,Gameboard*);
	virtual void ChangePotential(Node&, vector<Node>&, Gameboard*);
	bool isStillGoodSequence(vector<Node>,Gameboard*);
};