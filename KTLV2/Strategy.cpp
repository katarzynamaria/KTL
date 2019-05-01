#include "Strategy.h"
#include "Gameboard.h"

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
		for (int j = 0; h[i].size(); j++)
		{
			if (X[h[i][j]].colour = c) cs++;	//sprawdzamy ile elementow z danego ciagu nalezy do gracza
		}
		if (cs > currentLenght) currentLenght = cs;		
	}
	if (gb.GetSequenceLenght() == currentLenght) return true;
	else return false;
}

void Maker::ChangePotential(Node& moveMade, vector<Node>& X)
{
	int d = moveMade.degree;

}



int BreakerEasy::ChooseNode(vector<Node> X)
{
	
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
	if (k == (int)X.size() / 2) return true;		//breaker ma wszystkie swoje ruchy za soba
	else return false;
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
