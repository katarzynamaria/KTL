#include "GameBoard.h"
#include <time.h>

bool GameBoard::isNext(int* row, int x,int j)
{

	for (int i = j; i <= setCard; ++i)
	{
		if (row[i] == x) return true;
	}
	return false;
}

bool GameBoard::isValid()
{
	int check;
	
	for (int i = 0; i < setCard; ++i)
	{
		int currentSize=0;
		int multiplier=1;
		for (int j = i + 1; j < setCard; ++j)
		{
			if (isNext(distMatrix[i], distMatrix[i][j]*multiplier, j))
			{
				currentSize++;
				multiplier++;
			}
		}
		if (currentSize > sequenceLenght) return true;
	}
	
	return false;
}

GameBoard::GameBoard(int sequenceLength, int setCard,int range)
{
	this->sequenceLenght = sequenceLength;
	this->setCard = setCard;
	this->range = range;
	this->distMatrix = new int*[setCard];

	for (int i = 0; i < setCard; ++i)
	{
		distMatrix[i] = new int[setCard];
	}
	generateSet();
	generateDistMatrix();
}






void GameBoard::generateSet()
{
	getRandomNumbers();
	sort(setX.begin(), setX.end());
	

}

void GameBoard::getRandomNumbers() //Tworzymy zbiór randomowych liczb 
{
	vector<int> notYetGenerated(range);

	iota(begin(notYetGenerated), end(notYetGenerated), 1);

	srand(time(NULL));

	for (int i = 0; i < setCard; i++)
	{
		int index = rand() % notYetGenerated.size();
		int number = notYetGenerated[index];
		notYetGenerated.erase(notYetGenerated.begin()+index-1);
		setX.push_back(number);

	}
}

void GameBoard::generateDistMatrix()
{
	for (int i = 0; i < setCard; ++i)
	{
		for (int j = i; j < setCard; ++j)
		{
			distMatrix[i][j] = getDistance(i, j);
		}
	}
}


GameBoard::~GameBoard()
{
}