#include "Gameboard.h"
#include <time.h>

int Gameboard::isNext(int* row, int x, int j)
{
	for (int i = j; i < setCard; ++i)
	{
		if (row[i] > x) break;
		if (row[i] == x) return setX[i].value;
	}
	return -1;
}

bool Gameboard::isValid()
{
	for (int i = 0; i < 2; i++)
	{
		int currentSize = 0;
		int multiplier = 1;
		for (int j = i + 1; j <setCard; ++j)
		{
			if (distMatrix[i][j] == 0) continue;
			while (isNext(distMatrix[i], distMatrix[i][j] * multiplier, j)!=-1)
			{
				currentSize++;
				multiplier++;
			}
			if (currentSize >= sequenceLenght) return true;// WARTOSC LOGICZNA DO PRZEMYSLENIA;
		}
	}
	return false;
}

Gameboard::Gameboard(int sequenceLength, int setCard,int range)
{
	this->sequenceLenght = sequenceLength;
	this->setCard = setCard;
	this->range =range;
	this->distMatrix = new int*[setCard];


	for (int i = 0; i < setCard; ++i)
	{
		distMatrix[i] = new int[setCard];

	}
	do
	{
		cout << "Generating set" << endl;
		generateSet();

	} while (!isValid());

	cout << "Valid set generated" << endl;
	ShowGameboard();
	generateHypergraph();
	showHypergraph();
}

void Gameboard::generateSet()
{

	getRandomNumbers();
	sort(setX.begin(), setX.end());
	generateDistMatrix();

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
		notYetGenerated.erase(notYetGenerated.begin() + index);
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
	vector<int>* v = new vector<int>();

	for (int i = 0; i < setCard; ++i)
	{
		int currentSize = 0;
		int multiplier = 1;
		for (int j = i + 1; j < setCard; ++j)
		{
			while (true)
			{
				int next = isNext(distMatrix[i], distMatrix[i][j] * multiplier, j);
				if (next == -1) break;
				currentSize++;
				multiplier++;
				v->push_back(next);
			}
			if (currentSize > sequenceLenght)
			{
				hypergraph.push_back(*v);
			}
			v = new vector<int>();
			currentSize = 0;
			multiplier = 1;
		}
	}
}

void Gameboard::showHypergraph()
{
	cout << "Hipergraf: " << endl;

	for (int i = 0; i < hypergraph.size(); ++i)

	{
		for (int j = 0; j < hypergraph[i].size(); ++j)
		{
			cout << hypergraph[i][j] << " ";
		}
		cout << endl;
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
			cout << setX[i].value << "  ";
		}
		else if (setX[i].colour == 2)

		{
			SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
			cout << setX[i].value << "  ";
		}
		else
		{
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << setX[i].value << " ";
		}
	}
	cout << endl;
}

void Gameboard::Degree(Node n)
{
	//pewnie to zmienie jeszcze
	vector<vector<int>> h = hypergraph;
	int k = sequenceLenght;
	//int m = 0;
	for (int i = 0; i < h.size(); i++)
	{
		int m = h.size() - sequenceLenght;
		while (m > 0)
		{
			for (int j = m; j < k; j++)
			{
				if (h[i][j] == n.value) n.degree++;
			}
			m--;
		}
	}
}

void Gameboard::Degrees()
{
	for (int i = 0; i < setX.size(); i++)
	{
		Degree(setX[i]);
	}
}