#include "Strategy.h"

int Maker::ChooseNode(vector<Node> X)	//zwraca nie wartosc wierzcholka tylko indeks w X
{
	int max = X[0].potential;
	cout << "max " << max << endl;
	int v = 0;
	for (int i = 1; i < X.size(); i++)
	{
		cout << "potencjal " << X[i].potential;
		if (X[i].potential > max && X[i].colour == 0)
		{
			max = X[i].potential;
			v = i;
		}
		cout << "wierzcholek wybrany " << v << endl;
	}
	return v;
}

void Maker::ChangePotential(Node& moveMade, vector<Node>& X, Gameboard gb)
{
	//int d = moveMade.;
	//moveMade.potential = 0;

}

/*bool Maker::seqenceForSure(vector<int> seq, int r, int k)
{
int cs = 0;
for (int i = 0; i < seq.size() - 1; i++)
{
if (seq[i + 1] - seq[i] == r) cs++;
}
if (cs >= k) return true;
else return false;
}*/



int BreakerEasy::ChooseNode(vector<Node> X)
{
	return 0;
}



void BreakerEasy::ChangePotential(Node& moveMade, vector<Node>& X, Gameboard gb)
{
	//if (moveMade.potential >= pow(2, gb.GetSequenceLenght()))
	//	for (int i = 0; i < moveMade.degree.size(); ++i)
	//		moveMade.degree[i] *= pow(2, pow(-1, gb.LastMove()));  //potencja³ siê zmniejsza je¿eli wybra³ go gracz 1- u nas Breaker
	//else for (int i = 0; i < moveMade.degree.size(); ++i)
	//	moveMade.degree[i] = 1 - gb.LastMove();
}

int BreakerHard::ChooseNode(vector<Node> X)
{
	int p = X.size();
	int max = X[0].potential;
	int v = X[0].value;;
	for (int i = 1; i < p; i++)
	{
		if (X[i].potential > max)
		{
			max = X[i].potential;
			v = X[i].value;
		}
	}
	return v;
}

void BreakerHard::ChangePotential(Node& moveMade, vector<Node>& X, Gameboard gb)
{
	//if (moveMade.potential >= pow(2, gb.GetSequenceLenght()))
	//for(int i=0; i< moveMade.degree.size();++i)
	//*= pow(2, pow(-1,gb.LastColour));  //potencja³ siê zmniejsza je¿eli wybra³ go gracz 1- u nas Breaker
	//else for (int i = 0; i < moveMade.degree.size(); ++i)
	//= 1-gb.LastColour;

}