﻿#pragma once
#include "Game.h"

class Strategy
{
public:
	virtual int ChooseNode(vector<Node>) = 0;				//zwracamy indeks w setX;
	virtual bool End(Gameboard, int) = 0;			//warunek wygranej w zale¿noœci od strategii
	virtual void ChangePotential(Node&, vector<Node>&) = 0;			//zmiana potencjalu zalezy od strategii (jak maker to wzrasta o 1/2^k, jak breaker to moze byc rózna)
};

class Maker : public Strategy
{
public:

	virtual int ChooseNode(vector<Node>);
	virtual bool End(Gameboard, int);
	virtual void ChangePotential(Node&, vector<Node>&);

	bool seqenceForSure(vector<int>, int, int);		//sprawdza czy zbior dlugosci k faktycznie jest ciagiem
};

class BreakerEasy : public Strategy //breaker strategii parujacej
{
public:
	virtual int ChooseNode(vector<Node>);
	virtual bool End(Gameboard, int);
	virtual void ChangePotential(Node&, vector<Node>&);
};

class BreakerHard : public Strategy //strategii potencjalow
{
public:
	virtual int ChooseNode(vector<Node>);
	virtual bool End(Gameboard, int);
	virtual void ChangePotential(Node&, vector<Node>&,Gameboard);
};