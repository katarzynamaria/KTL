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

Node Player::ChooseNode()
{
	return Node();
}

bool Player::IsWinner()
{
	return strategy->End(gb, colour);		//winner w zalezosci od strategii
}

void Player::TakeNode()
{
	gb.colorField(strategy->ChooseNode(), colour);
}

void Player::ChangePotential(Node& moveMade)
{
	vector<Node> X = gb.GetSetX();
	strategy->ChangePotential(moveMade, X);
}