#include "Gameboard.h"
#include <time.h>

bool Gameboard::isNext(int* row, int x, int j)
{

	for (int i = j; i <= setCard; ++i)
	{
		if (row[i] == x) return true;
	}
	return false;
}

bool Gameboard::isValid()
{

	for (int i = 0; i < setCard; ++i)
	{
		int currentSize = 0;
		int multiplier = 1;
		for (int j = i + 1; j < setCard; ++j)
		{
			if (isNext(distMatrix[i], distMatrix[i][j] * multiplier, j))
			{
				currentSize++;
				multiplier++;
			}
		}
		if (currentSize > sequenceLenght) return true;// WARTOSC LOGICZNA DO PRZEMYSLENIA;
	}

	return false;
}

Gameboard::Gameboard(int sequenceLength, int setCard, int range)
{
	this->sequenceLenght = sequenceLength;
	this->setCard = setCard;
	this->range = range;
	this->distMatrix = new int*[setCard];

	for (int i = 0; i < setCard; ++i)
	{
		distMatrix[i] = new int[setCard];
	}
	do
		generateSet();
	while (!isValid());
	generateDistMatrix();
	generateHypergraph();
}

void Gameboard::generateSet()
{
	getRandomNumbers();
	sort(setX.begin(), setX.end());
}

void Gameboard::getRandomNumbers() //Tworzymy zbiór randomowych liczb 
{
	vector<int> notYetGenerated(range);

	iota(begin(notYetGenerated), end(notYetGenerated), 1);

	srand(time(NULL));

	Node v;									//tutaj dostosowalam do nowego setX
	for (int i = 0; i < setCard; i++)
	{
		int index = rand() % notYetGenerated.size();
		//int number = notYetGenerated[index];
		v.value = notYetGenerated[index];
		notYetGenerated.erase(notYetGenerated.begin() + index - 1);
		//setX.push_back(number);
		setX.push_back(v);

	}
}

void Gameboard::generateDistMatrix()
{
	for (int i = 0; i < setCard; ++i)
	{
		for (int j = i; j < setCard; ++j)
		{
			distMatrix[i][j] = getDistance(i, j);
		}
	}
}

void Gameboard::generateHypergraph()
{
	int index = 0;
	vector<int> v;

	for (int i = 0; i < setCard; ++i)
	{
		int currentSize = 0;
		int multiplier = 1;
		for (int j = i + 1; j < setCard; ++j)
		{
			if (isNext(distMatrix[i], distMatrix[i][j] * multiplier, j))
			{
				currentSize++;
				multiplier++;
				v.push_back(setX[i].value);
			}
		}
		if (currentSize > sequenceLenght)
		{
			hypergraph[index] = v;
			index++;
			v.clear;
		};
	}


}

Gameboard::~Gameboard()
{

	for (int i = 0; i < setCard; ++i)
	{
		delete[] distMatrix[i];
		hypergraph[i].clear;
	}
}


Node Gameboard::LastMove()
{
	return Node();
}



void Gameboard::ShowGameboard()
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	 SetConsoleTextAttribute(hOut, FOREGROUND_RED);
	 SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);

	 for (int i = 0; i < setCard; ++i)
	 {
		 if (setX[i].colour == 1)
		 {
			 SetConsoleTextAttribute(hOut, FOREGROUND_RED);
			 cout<< setX[i].value;
		 }
		 if(setX[i].colour == 2)

		 {
			 SetConsoleTextAttribute(hOut, FOREGROUND_RED);
			 cout << setX[i].value;
		 }
		 
	 }
}
