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
	return strategy->End(gb, colour);		//winner w zalezosci od strategii
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