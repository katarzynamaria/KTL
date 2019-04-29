#pragma once
#include "Game.h"

class Strategy
{
public:
	virtual int ChooseNode() = 0;  //zwracamy indeks w setX;
};

class Maker : public Strategy
{
public:
	Maker() {};

	virtual int ChooseNode()
	{
		//do wypelnienia
		return 0;
	}
};

class BreakerEasy : public Strategy //breaker strategii parujacej
{
public:
	virtual int ChooseNode()
	{
		//do wypelnienia
		return 0;
	}
};

class BreakerHard : public Strategy //strategii potencjalow
{
public:
	virtual int ChooseNode()
	{
		//do wypelnienia
		return 0;
	}
};


