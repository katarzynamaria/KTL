#include "Player.h"

Player::Player(Strategy* strategy, Gameboard* g, int colour) : strategy(strategy), gb(g), colour(colour) {}; 

bool sequenceForSure(vector<int> seq, int r, int k)		//funckja pomocnicza, sprawdza czy juz zebrane wierzcholki(seq) 
{														//faktycznie tworza c. arytmetyczny o roznicy r i dlugosci k
	int cs = 0;
	for (int i = 0; i < seq.size() - 1; i++)
	{
		if (seq[i + 1] - seq[i] == r) cs++;
	}
	if (cs >= k) return true;
	else return false;
}

bool Player::IsWinner()							//funckja sprawdza czy gracz juz wygral
{
	vector<vector<Node* >> h = gb->GetHypergraph();
	vector<Node> X = gb->GetSetX();
	
	for (int i = 0; i<h.size(); i++)
	{
		int cs = 0;
		vector<int> sequenceMaybe = vector<int>(X.size());
		for (int j = 0; j<h[i].size(); j++)
		{
			if (h[i][j]->colour == colour)
			{
				sequenceMaybe.push_back(h[i][j]->value);
				cs++;	
			}
		}
		if (cs == h[i].size())
		{	
			return true;
		}
		if (gb->GetSequenceLenght() <= cs)
		{
			
			int r = h[i][1] - h[i][0];
			if (sequenceForSure(sequenceMaybe, r, gb->GetSequenceLenght()))
			{
				return true;
			}
		}
	}
	return false;
}

void Player::TakeNode()	//odpowiada za wybrnie odpowiedniego wierzcholka
{
	vector<vector<Node*>> X = gb->GetHypergraph();
	gb->colorField(strategy->ChooseNode(X, gb), colour);
	strategy->ChangePotential(X, gb);
}

