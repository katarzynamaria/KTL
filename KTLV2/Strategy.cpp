#include "Strategy.h"

int Maker::ChooseNode(vector<Node> X)
{
	int max = X[0].potential;
	int v = X[0].value;;
	for (int i = 1; i < X.size(); i++)
	{
		if (X[i].potential > max)
		{
			max = X[i].potential;
			v = X[i].value;
		}
	}
	return v;
}

bool Maker::End(Gameboard gb, int c)
{
	vector<vector<int>> h = gb.GetHypergraph;		//hipergraf jako zbior ciagow
	vector<Node> X = gb.GetSetX();

	for (int i = 0; h.size(); i++)
	{
		int cs = 0;
		vector<int> sequenceMaybe = vector<int>(X.size());
		for (int j = 0; h[i].size(); j++)
		{
			if (X[h[i][j]].colour = c)
			{
				sequenceMaybe.push_back(h[i][j]);
				cs++;	//sprawdzamy ile elementow z danego ciagu nalezy do gracza
			}
		}
		int r = h[i][1] - h[i][0]; //do jakiej krawedzi multigrafu naleza
		if (gb.GetSequenceLenght <= cs)
		{
			if (seqenceForSure(sequenceMaybe, r, gb.GetSequenceLenght())) return true;
			else sequenceMaybe.clear();
		}
	}
	return false;
}

void Maker::ChangePotential(Node& moveMade, vector<Node>& X)
{
	int d = moveMade.degree;
	moveMade.potential = 0;
	//mam wykminiony potencjal tylko nie wiem jeszcze jak zaimplementowac mozliwe ze ogarne do 03.05
}

bool Maker::seqenceForSure(vector<int> seq, int r, int k)
{
	int cs = 0;
	for (int i = 0; i < seq.size() - 1; i++)
	{
		if (seq[i + 1] - seq[i] == r) cs++;
	}
	if (cs >= k) return true;
	else return false;
}



int BreakerEasy::ChooseNode(vector<Node> X)
{
	//jeszcze sie uzupelni
	return 0;
}

bool BreakerEasy::End(Gameboard gd, int c)
{
	int k = 0;
	vector<Node> X = gd.GetSetX();
	for (int i = 0; i < X.size(); i++)
	{
		if (X[i].colour == c) k++;
	}
	if (k == (int)(X.size() / 2)) return true;		//breaker ma wszystkie swoje ruchy za soba
	else return false;
}

void BreakerEasy::ChangePotential(Node &, vector<Node>&)
{
	//taki sam jak przy BreakerHard
}

int BreakerHard::ChooseNode(vector<Node> X)
{
	int max = X[0].potential;
	int v = X[0].value;;
	for (int i = 1; i < X.size(); i++)
	{
		if (X[i].potential > max)
		{
			max = X[i].potential;
			v = X[i].value;
		}
	}
	return v;
}

bool BreakerHard::End(Gameboard gd, int c)
{
	int k = 0;
	vector<Node> X = gd.GetSetX();
	for (int i = 0; i < X.size(); i++)
	{
		if (X[i].colour == c) k++;
	}
	if (k == (int)X.size() / 2) return true;
	else return false;
}

void BreakerHard::ChangePotential(Node &, vector<Node>&)
{
}