#include "Player.h"

Player::Player(Strategy* strategy, Gameboard* g, int colour) : strategy(strategy), gb(g), colour(colour)
{
}


Player::~Player()
{
}


bool Player::IsWinner()
{
	int k = 0;
	vector<Node> X = gb->GetSetX();
	for (int i = 0; i < X.size(); i++)
	{
		if (X[i].colour == colour) k++;
	}
	if (k == (int)(X.size() / 2)) return true;        //breaker ma wszystkie swoje ruchy za soba
	else return false;
	return true;
}

void Player::TakeNode()	//odpowiada za wybrnie odpowiedniego wierzcholka
{
	//cout << "Started taking node!" << endl;
	vector<vector<Node*>> X = gb->GetHypergraph();
	gb->colorField(strategy->ChooseNode(X, gb), colour);
	//cout << "Finished taking node!" << endl;
}

void Player::ChangePotential(Node& moveMade)
{
	vector<vector<Node*>> X = gb->GetHypergraph();
	strategy->ChangePotential(moveMade, X, gb);
}