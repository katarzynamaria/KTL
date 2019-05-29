#include "Player.h"

Player::Player(Strategy* strategy, Gameboard* g, int colour) : strategy(strategy), gb(g), colour(colour) {}; 


bool Player::IsWinner()							//funckja sprawdza czy gracz juz wygral
{
	vector<vector<Node* >> h = gb->GetHypergraph();
	vector<Node> X = gb->GetSetX();
	
	for (int i = 0; i < h.size(); i++)
	{
		int cs = 0;
		for (int j = 0; j < h[i].size(); j++)
		{
			if (h[i][j]->colour == colour) cs++;
		}
		if (cs == h[i].size()) return true;
	}
	return false;
}

void Player::TakeNode()	//odpowiada za wybrnie odpowiedniego wierzcholka
{
	vector<vector<Node*>> X = gb->GetHypergraph();
	gb->colorField(strategy->ChooseNode(X, gb), colour);
	strategy->ChangePotential(X, gb);
}

