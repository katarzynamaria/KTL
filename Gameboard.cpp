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
	int check;

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
		if (currentSize > sequenceLenght) return true;
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

Gameboard::~Gameboard()
{
}


Node Gameboard::LastMove()
{
	return Node();
}
