#pragma once
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class GameBoard
{
	int sequenceLenght;
	int setCard;
	int range;
	vector<int> setX;
	int** distMatrix;
public:
	bool isValid();

	GameBoard(int sequenceLength, int setCard, int range=1000);
	~GameBoard();
private:
	bool isNext(int* tab, int x, int j);
	void generateSet();

	void getRandomNumbers();

	int getDistance(int x, int y)
	{
		return setX[x] - setX[y];
	}

	void generateDistMatrix();

	

};

