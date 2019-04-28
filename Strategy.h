#pragma once
#include "Game.h"
#include "Player.h"
#include "Gameboard.h"

class Strategy
{
public:
	virtual Node ChooseNode() = 0;
};

class Maker : public Strategy
{
public:
	virtual Node ChooseNode()
	{
		//do wypelnienia
		return Node();
	}
};

class BreakerEasy : public Strategy //breaker strategii parujacej
{
public:
	virtual Node ChooseNode()
	{
		//do wypelnienia
		return Node();
	}
};

class BreakerHard : public Strategy //strategii potencjalow
{
public:
	virtual Node ChooseNode()
	{
		//do wypelnienia
		return Node();
	}
};
