#include "Strategy.h"

int Maker::ChooseNode(vector<vector<Node*>>& H, Gameboard* gb)	
{
	vector<Node> X = gb->GetSetX();
	double max = 0;
	int v = -1;
	int i = 0;
	while (i < X.size())
	{
		if (X[i].gValue >= max && X[i].colour == 0 ) //&& X[i].visited == false) //jest juz niepotrzebne
		{
			max = X[i].gValue;
			v = i;
			cout << X[i].value <<".potential " << X[i].gValue << endl;
		}
		i++;
	}
		
	/*cout << "Before change potential" << endl;*/
	ChangePotential(X[v], H, gb);				//zmieniamy potencjal wszystkich wierzcholkow, ktore sa w jakims ciagu z X[v] 
												/*cout << "After change potential" << endl;*/
	return v;
}

void Maker::ChangePotential(Node& moveMade, vector<vector<Node*>>& hypegraph, Gameboard* gb)
{
	if (moveMade.gValue<1)
	{
		for (int i = 0; i < moveMade.degree.size(); ++i)
		{
			vector<Node*> nodes = hypegraph[moveMade.degree[i]];
			gb->Potential[moveMade.degree[i]] *= pow(2, 1);
			for (int j = 0; j < hypegraph[moveMade.degree[i]].size(); j++)
			{
				//nodes[j]->setgValue[gb->Potential];
				
			}
		}
		
	}
	else 
	{
		

	}
	moveMade.visited = true;
}




int BreakerEasy::ChooseNode(vector<vector<Node*>>& hyp, Gameboard* gb)
{
	Node* w = gb->findNodeWithValue(gb->LastMove()); //Node ostatniego ruchu
	int i = 0;
	int v = 0;
	while (v = 0)			//zawsze musi byc jakis nie wybrany wierzcholke w ciagu, inaczej wygrana Makera
	{
		int seqIndex = w->degree[i];
		for (int j = 0; j < hyp[seqIndex].size(); j++)
		{
			if (hyp[seqIndex][j]->colour == 0)
			{
				v = hyp[seqIndex][j]->value;
				break;
			}
		}
		i++;
	}
	int index = gb->findIndexOf(v);
	return index;
}



void BreakerEasy::ChangePotential(Node& moveMade, vector<vector<Node*>>& X, Gameboard* gb)
{
	for (int i = 0; i < moveMade.degree.size(); ++i)
	{
		//for (int j = 0; j < X[i].size(); j++)
		// X[moveMade.degree[i]][j] = 0;              tutaj tez trzeba zmienic
	}
	moveMade.visited = true;
}


int BreakerHard::ChooseNode(vector<vector<Node*>>& H, Gameboard* gb)
{
	vector<Node> X = gb->GetSetX();
	double max = 0;
	int v = -1;
	int i = 0;
	while (i < X.size())
	{
		if (X[i].gValue >= max && X[i].colour == 0) //jezeli niewybrany wierzcholek ma wiekszy potencjal niz max
		{


			max = X[i].gValue;
			v = i;

		}
		i++;
	}
	X[v].visited = true;
	
	ChangePotential(X[v], H, gb);				//zmieniamy potencjal wszystkich wierzcholkow, ktore sa w jakims ciagu z X[v] 
												
	return v;									//X[v] jest wybranym przez nas maksymalnym wierzcholkiwm
}

void BreakerHard::ChangePotential(Node& moveMade, vector<vector<Node*>>& hypergraph, Gameboard* gb)
{
		for (int i = 0; i < moveMade.degree.size(); ++i)
		{
			vector<Node*> nodes = hypergraph[moveMade.degree[i]];
			gb->Potential[moveMade.degree[i]] = 0;
			for (int j = 0; j < hypergraph[moveMade.degree[i]].size(); j++)
			{
				//TUTAJ COŚTAM
			}
		}
	


	moveMade.visited = true;
	gb->seqYetToChoose--;
}