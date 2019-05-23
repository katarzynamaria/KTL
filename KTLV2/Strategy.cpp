#include "Strategy.h"

int Maker::ChooseNode(vector<Node>& X,Gameboard* gb)	//zwraca nie wartosc wierzcholka tylko indeks w X
{

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
	ChangePotential(X[v], X, gb);
	return v;
}

void Maker::ChangePotential(Node& moveMade, vector<Node>& X, Gameboard* gb)
{


	if (moveMade.potential < pow(2, gb->GetSequenceLenght()))
		for (int i = 0; i < moveMade.degree.size(); ++i)
		{
			X[moveMade.degree[i]].potential *= pow(2, 1);  //wiercholek wybral Maker-zwiekszamy potencjal
		}										
	else for (int i = 0; i < moveMade.degree.size(); ++i)
		X[moveMade.degree[i]].potential = 1 ;
	moveMade.visited = true;
}




int BreakerEasy::ChooseNode(vector<Node>& X, Gameboard* gb)
{
	return 0;
}



void BreakerEasy::ChangePotential(Node& moveMade, vector<Node>& X, Gameboard* gb)
{
	if (moveMade.potential >= pow(2, gb->GetSequenceLenght()))
		for (int i = 0; i < moveMade.degree.size(); ++i)
		{
			X[moveMade.degree[i]].potential *= pow(2,-1);  //wybral Breaker->zmniejszamy potencjal wszystkich wierzcholkow z ciagu w ktorym jest moveMade
		}											
	else for (int i = 0; i < moveMade.degree.size(); ++i)
		X[moveMade.degree[i]].potential = 0;
	moveMade.visited = true;
}

bool BreakerEasy::isStillGoodSequence(vector<Node> setXelem, Gameboard* gb)
{ 
	if (setXelem.size() < gb->GetSequenceLenght()) return false;
	int p = setXelem[1].value - setXelem[0].value;
	for (int i = 1; i < setXelem.size(); ++i)
	{
		{
			if (p != setXelem[i + 1].value - setXelem[i].value) return false;
		}
	}
	return true;
}

int BreakerHard::ChooseNode(vector<Node>& X,Gameboard* gb)
{
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
	ChangePotential(X[v], X, gb);				//zmieniamy potencjal wszystkich wierzcholkow, ktore sa w jakims ciagu z X[v] 
	return v;									//X[v] jest wybranym przez nas maksymalnym wierzcholkiwm
}

bool BreakerHard::isStillGoodSequence(vector<Node> setXelem, Gameboard* gb)
{
	if (setXelem.size() < gb->GetSequenceLenght()) return false;
	int p = setXelem[1].value - setXelem[0].value;
	for (int i = 1; i < setXelem.size(); ++i)
	{
		{
			if (p != setXelem[i + 1].value - setXelem[i].value) return false;
		}
	}
	return true;
}
void BreakerHard::ChangePotential(Node& moveMade, vector<Node>& X, Gameboard* gb)
{
	cout << "BreakerHardChangePotential:   " << endl;

	if (moveMade.potential < pow(2, gb->GetSequenceLenght()))
		for (int i = 0; i < moveMade.degree.size(); ++i)
		{
			X[moveMade.degree[i]].potential *= pow(2, -1);
			cout << "zmieniony potencial: " << X[moveMade.degree[i]].potential << endl;
		}												//potencja³ siê zmniejsza je¿eli wybra³ go gracz 1- u nas Breaker
	else
	{
		for (int i = 0; i < moveMade.degree.size(); ++i)
			X[moveMade.degree[i]].potential = 0;
	}
}