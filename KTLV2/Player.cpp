#include "Player.h"


Player::Player(Strategy* s, Gameboard& g) : strategy(s), gb(g)
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

void Player::TakeNode()
{
	gb.colorField(strategy->ChooseNode(), colour);
}

void Player::ChangePotential()
{
}
