#include "Player.h"


Player::Player(Strategy* s, Gameboard& g, int c) : strategy(s), gb(g), colour(c)
{
}


Player::~Player()
{
}

void Player::ShowMove()
{
}

bool Player::IsWinner()
{
	gra->ifWinner = strategy->End(gb, colour);
	return gra->ifWinner;		//winner w zalezosci od strategii
}

void Player::TakeNode()
{
	vector<Node> X = gb.GetSetX();
	gb.colorField(strategy->ChooseNode(X), colour);
}

void Player::ChangePotential(Node& moveMade)
{
	vector<Node> X = gb.GetSetX();
	strategy->ChangePotential(moveMade, X);
}