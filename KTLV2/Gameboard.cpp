#include "Gameboard.h"
#include <time.h>

bool Gameboard::isNext(int* row, int x, int j)
{

	for (int i = j; i < setCard; ++i)
	{
		if (row[i] > x) break;
		if (row[i] == x) return true;
	}
	return false;
}

bool Gameboard::isValid()
{
	for (int i = 0; i < 2; i++)
	{
		int currentSize = 0;
		int multiplier = 1;
		for (int j = i + 1; j <setCard; ++j)
		{
			while (isNext(distMatrix[i], distMatrix[i][j] * multiplier, j))
			{
				currentSize++;
				multiplier++; 
			}
			if (currentSize > sequenceLenght) return true;// WARTOSC LOGICZNA DO PRZEMYSLENIA;
		}
	}
	return false;
}

Gameboard::Gameboard(int sequenceLength, int setCard, int range)
{
	this->sequenceLenght = sequenceLength;
	this->setCard = setCard;
	this->range = range;
	this->distMatrix = new int* [setCard];
	cout << "wszystko tutaj gra?";
	for (int i = 0; i < setCard; ++i)
	{
		distMatrix[i] = new int[setCard];
		
	}
	do
	{    
		int p = isValid();
		generateSet();
		cout << "isValid= " << p << endl;
		cout << "czy wygeneruje poprawny set";
	}
	while (!isValid());

	cout << "generuje hipergraf";
	generateHypergraph();
}

void Gameboard::generateSet()
{
	cout << "zaczynam generowac set";
	getRandomNumbers();
	sort(setX.begin(), setX.end());
	generateDistMatrix();
	cout << "wygenerowalam set" << endl;;
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
	cout << "wygenerowane randomowe liczby" << endl;
}

void Gameboard::generateDistMatrix()
{
	for (int i = 0; i < setCard; ++i)
	{
		for (int j = i; j < setCard; ++j)
		{
			distMatrix[i][j] = getDistance(i, j);
			cout << distMatrix[i][j]<<" ";
		}
		cout << endl;
	}
}

void Gameboard::generateHypergraph()
{
	cout << "zaczynam generowaæ hipergraf" << endl;
	int index = 0;
	vector<int> v;

	for (int i = 0; i < setCard; ++i)
	{
		int currentSize = 0;
		int multiplier = 1;
		for (int j = i + 1; j < setCard; ++j)
		{
			while (isNext(distMatrix[i], distMatrix[i][j] * multiplier, j))
			{
				currentSize++;
				multiplier++;
				v.push_back(setX[i].value);
			}
		if (currentSize > sequenceLenght)
		{
			hypergraph[index] = v;
			index++;
			
		}
		v.clear();
		}

	}


}

Gameboard::~Gameboard()
{

	for (int i = 0; i < setCard; ++i)
	{
		delete[] distMatrix[i];
		hypergraph[i].clear();
	}
}


int Gameboard::LastMove()
{
	return lastColoredField;
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
			cout << setX[i].value;
		}
		if (setX[i].colour == 2)

		{
			SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
			cout << setX[i].value;
		}
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	}
}
