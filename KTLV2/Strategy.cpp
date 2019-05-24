#include "Strategy.h"

//ofensywny
int Maker::ChooseNode(vector<vector<Node*>>& H, Gameboard* gb)		//wybiera wierzcholek strategia Makera
{
	vector<Node> X = gb->GetSetX();
	double max = 0;
	int v = -1;
	int i = 0;
	while (i < X.size())
	{
		if (X[i].gValue >= max && X[i].colour == 0) 
		{
			max = X[i].gValue;
			v = i;
		}
		i++;
	}
			
	return v;
}

void Maker::ChangePotential(vector<vector<Node*>>& h, Gameboard* gb)	//zmienia potencjal
{
	
	Node* lmove = gb->findNodeWithValue(gb->LastMove());
	
	vector<int> seqIndex = lmove->degree;
	for (int k = 0; k < seqIndex.size(); k++)
	{
		gb->Potential[k] *= 2;
	}
	gb->setPotentials();

}

//defensywny naiwny
int BreakerEasy::ChooseNode(vector<vector<Node*>>& hyp, Gameboard* gb)	
{
	Node* w = gb->findNodeWithValue(gb->LastMove()); 
	vector<Node> X = gb->GetSetX();
	int i = 0;
	int v = 0;
	while (i < w->degree.size())	
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
		if (v != 0) break;
		else i++;
	}
	if (v == 0 || i== w->degree.size())
	{
		for (int k = 0; k < X.size(); k++)
		{
			if (X[k].colour == 0)
			{
				v = X[k].value;
				break;
			}
		}
	}
	Node* z = gb->findNodeWithValue(v);
	int index = gb->findIndexOf(v);
	return index;
}



void BreakerEasy::ChangePotential(vector<vector<Node*>>& hyp, Gameboard* gb)
{
	Node* lmove = gb->findNodeWithValue(gb->LastMove());
	vector<int> seqIndex = lmove->degree;
	for (int i = 0; i < seqIndex.size(); i++)
	{
		vector<Node*> nodes = hyp[seqIndex[i]];
		int n = 0;
		for (int k = 0; k < nodes.size(); k++)
		{
			if (nodes[k]->colour == 0) n++;
		}
		if (n < gb->GetSequenceLenght()) gb->Potential[i] *= 0;
		else gb->Potential[i] *= 1 / 2;
	}
	
	gb->setPotentials();

}

//defensywny
int BreakerHard::ChooseNode(vector<vector<Node*>>& H, Gameboard* gb)
{
	vector<Node> X = gb->GetSetX();
	double max = 0;
	int v = -1;
	int i = 0;
	while (i < X.size())
	{
		if (X[i].gValue >= max && X[i].colour == 0)
		{


			max = X[i].gValue;
			v = i;

		}
		i++;
	}
	return v;
}

void BreakerHard::ChangePotential(vector<vector<Node*>>& hyp, Gameboard* gb)
{
	Node* lmove = gb->findNodeWithValue(gb->LastMove());
	
	vector<int> seqIndex = lmove->degree;
	for (int i = 0; i < seqIndex.size(); i++)
	{
		vector<Node*> nodes = hyp[seqIndex[i]];
		int n = 0;
		for (int k = 0; k < nodes.size(); k++)
		{
			if (nodes[k]->colour == 0) n++;
		}
		if (n < gb->GetSequenceLenght()) gb->Potential[i] *= 0;
		else gb->Potential[i] *= 1 / 2;
	}

	gb->setPotentials();

}