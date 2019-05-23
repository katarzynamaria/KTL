#include "Strategy.h"

int Maker::ChooseNode(vector<vector<Node*>>& H,Gameboard* gb)	//zwraca nie wartosc wierzcholka tylko indeks w X
{
	vector<Node> X = gb->GetSetX();
	double max = X[0].potential;
	int v=-1;
	int i = 0;
	while (v < 0 || i<X.size())
	{

		if (X[i].potential >= max && X[i].colour == 0 && X[i].visited == false)//jezeli niewybrany wierzcholek ma wiekszy potencjal niz max
		{


			max = X[i].potential;
			v = i;
		}
		i++;
	}
	X[v].visited = true;
	/*cout << "Before change potential" << endl;*/
	ChangePotential(X[v], H, gb);				//zmieniamy potencjal wszystkich wierzcholkow, ktore sa w jakims ciagu z X[v] 
	/*cout << "After change potential" << endl;*/
	return v;
}

void Maker::ChangePotential(Node& moveMade, vector<vector<Node*>>& hypegraph, Gameboard* gb)
{
	if (moveMade.potential < pow(2, gb->GetSequenceLenght()))
	{
		for (int i = 0; i < moveMade.degree.size(); ++i)
		{
			for (int j = 0; j < hypegraph[i].size(); j++)
			{
				/*cout << "Before getting nodes for i = "<< i << endl;
				cout << "Degree[i] = " << moveMade.degree[i] << endl;*/
				vector<Node*> nodes = hypegraph[moveMade.degree[i]];
				/*cout << "Got nodes!" << endl;*/
				nodes[j]->potential *= pow(2, -1);  //wiercholek wybral Maker-zwiekszamy potencjal
			}
		}
	}
	else for (int i = 0; i < moveMade.degree.size(); ++i)
	{
		for (int j = 0; j < hypegraph[i].size(); i++)
		hypegraph[moveMade.degree[i]][j]->potential = 1;
	}
	moveMade.visited = true;
}




int BreakerEasy::ChooseNode(vector<vector<Node*>>& X, Gameboard* gb)
{
	return 0;
}



void BreakerEasy::ChangePotential(Node& moveMade, vector<vector<Node*>>& X, Gameboard* gb)
{
	 for (int i = 0; i < moveMade.degree.size(); ++i)
	{
		 for (int j = 0; j < X[i].size(); j++)
		 X[moveMade.degree[i]][j] = 0;
	}
	moveMade.visited = true;
}


int BreakerHard::ChooseNode(vector<vector<Node*>>& H,Gameboard* gb)
{
	vector<Node> X = gb->GetSetX();
	double max = X[0].potential;
	int v = -1;
	int i = 0;
	while (v < 0 || i < X.size())
	{
		if (X[i].potential >= max && X[i].colour == 0 && X[i].visited == false) //jezeli niewybrany wierzcholek ma wiekszy potencjal niz max
		{


			max = X[i].potential;
			v = i;

		}
		i++;
	}
	X[v].visited = true;
	//cout << "Before change potential" << endl;
	ChangePotential(X[v], H, gb);				//zmieniamy potencjal wszystkich wierzcholkow, ktore sa w jakims ciagu z X[v] 
	//cout << "After change potential" << endl;
	return v;									//X[v] jest wybranym przez nas maksymalnym wierzcholkiwm
}

void BreakerHard::ChangePotential(Node& moveMade, vector<vector<Node*>>& hypergraph, Gameboard* gb)
{
	if (moveMade.potential < pow(2, gb->GetSequenceLenght()))
	{
		for (int i = 0; i < moveMade.degree.size(); ++i)
		{
			for (int j = 0; j < hypergraph[i].size(); j++)
			{
				cout << "Before getting nodes for i = "<< i << endl;
				cout << "Degree[i] = " << moveMade.degree[i] << endl;
				vector<Node*> nodes = hypergraph[moveMade.degree[i]];
				cout << "Got nodes!" << endl;
				nodes[j]->potential *= 0;  //wiercholek wybral Maker-zwiekszamy potencjal
			}
		}
	}
		moveMade.visited = true;
}
