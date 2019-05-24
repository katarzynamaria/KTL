#include "Gameboard.h"
#include <time.h>

void Gameboard::colorField(int index, int colour) //przypisuje wartosc ostatniego pomalowanego wierzcholka zmennej lastColoredFiled 
{
	lastColoredField = setX[index].value;
	LastColour = colour;
	setX[index].colour = colour;
}
int Gameboard::findIndexOf(int value)
{
	for (int i = 0; i < setX.size(); ++i)
	{
		if (setX[i] == value) return i;
	}
	cout << "CRITICAL FAIL - CAN't find" << value << " in setX";		//CRITICAL FAIL XDDDDDDDDDDD
	return -1;
}
;



int Gameboard::isNext(int* row, int x, int j)				//szuka nastepnego wyrazu ciagu
{
	for (int i = j; i < setCard; ++i)
	{
		if (row[i] > x) break;
		if (row[i] == x) return setX[i].value;
	}
	return -1;
}

bool Gameboard::isValid()								//sprawdza czy dany set ma ciag arytmetyczny w sobie
{
	vector<int> validSequence;
	for (int i = 0; i < 2; i++)
	{
		int currentSize = 0;
		int multiplier = 1;
		for (int j = i + 1; j <setCard; ++j)
		{
			if (distMatrix[i][j] == 0) continue;
			while (isNext(distMatrix[i], distMatrix[i][j] * multiplier, j) != -1)
			{
				validSequence.push_back(isNext(distMatrix[i], distMatrix[i][j] * multiplier, j));
				currentSize++;
				multiplier++;
			}
			if (currentSize >= sequenceLenght)
			{
				cout << "Valid sequence is: " << endl;
				for (int h = 0; h < validSequence.size(); ++h)
				{
					cout << validSequence[h] << " ";
				}
				return true;
			}
			validSequence.clear();
			currentSize = 0;
			multiplier = 1;
		}
	}
	return false;
}



void Gameboard::SetPotential()
{
	cout << "setting potentials" << endl;
	int k = 0;
	for (int i = 0; i < hypergraph.size(); ++i)

	{
		k = hypergraph[i].size();
		Potential.push_back(pow(2, -k));
	}

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
	{
		//cout << "Generating set" << endl;
		generateSet();

	} while (!isValid());

	//cout << endl << "Valid set generated" << endl;
	generateHypergraph();
	//ShowDegrees();

	SetPotential();
	setPotentials();
	ShowGameboard();

	showHypergraph();
}


void Gameboard::setDegrees(vector<Node*>& hiperval, int iter) //ustawia degrees dla wszystkich wierzcholkow w setX
{
	for (int i = 0; i < setX.size(); ++i)
	{
		setX[i].setDegree(&hiperval, iter);
	}
}
void Gameboard::setPotentials()							//ustawia potencial dla wszystkich wierzcholkow w setX
{
	for (int i = 0; i < setX.size(); ++i)
	{
		setX[i].setgValue(Potential);
	}
}

Node* Gameboard::findNodeWithValue(int value)
{
	for (int i = 0; i < setX.size(); ++i)
	{
		if (setX[i].value == value) return &setX[i];
	}
	cout << "CRITICAL FAILURE! CAN'T FIND VALUE " << value << " IN setX" << endl;
	return nullptr;
}

void Gameboard::generateSet()						//generuje randowmowy zbior x
{
	getRandomNumbers();
	sort(setX.begin(), setX.end());
	generateDistMatrix();

}

void Gameboard::getRandomNumbers() //Tworzymy zbiór randomowych liczb 
{
	setX.clear();
	vector<int> notYetGenerated(range);

	iota(begin(notYetGenerated), end(notYetGenerated), 1);


	Node v = *new Node();									//tutaj dostosowalam do nowego setX
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

void Gameboard::generateDistMatrix()			//generuje macierz odleglosci miedzy wierzcholkami
{
	for (int i = 0; i < setCard; ++i)
	{
		for (int j = i; j < setCard; ++j)
		{
			distMatrix[i][j] = getDistance(i, j);

		}

	}
}
//void Gameboard::ShowDegrees() { for (int i = 0; i < setX.size(); ++i) cout << "size: " << setX[i].degree.size(); }


void Gameboard::generateHypergraph()					//generuje hipergraf
{
	int index = 0;
	vector<Node*>* v = new vector<Node*>();

	for (int i = 0; i < setCard; ++i)
	{
		int currentSize = 0;
		int multiplier = 1;
		for (int j = i + 1; j < setCard; ++j)
		{
			while (true)
			{
				int value = isNext(distMatrix[i], distMatrix[i][j] * multiplier, j); //nastepny wyraz na podstawie IsNext
				if (value == -1) break;
				currentSize++;
				multiplier++;
				Node* node = findNodeWithValue(value);
				v->push_back(node);

			}
			if (currentSize >= sequenceLenght) //jezeli wybrany wyzej ciag jest dlugosci wiekszej niz k to go dodajemy do hipergrafu
			{
				hypergraph.push_back(*v);
				setDegrees(*v, hypergraph.size() - 1);
			}
			v = new vector<Node*>();
			currentSize = 0;
			multiplier = 1;
		}
	}
	seqYetToChoose = hypergraph.size();
}

void Gameboard::showHypergraph() //wypisuje hipergraf
{
	cout << "Hipergraf: " << endl;

	for (int i = 0; i < hypergraph.size(); ++i)

	{
		for (int j = 0; j < hypergraph[i].size(); ++j)
		{
			cout << hypergraph[i][j]->value << " ";
		}
		cout << endl;
	}
}

Gameboard::~Gameboard()			//destruktor do zwolnienia pamieci
{

	for (int i = 0; i < setCard; ++i)
	{
		delete[] distMatrix[i];
	}
}


int Gameboard::LastMove()		//przechowuje informacje o graczu który ostatnio wykona? ruch
{
	return lastColoredField;
}



void Gameboard::ShowGameboard() //w zale?no?ci od tego jaki gracz wykona? ruch kolorujemy liczby na czerwonno lub niebiesko
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int i = 0; i < setCard; ++i)
	{
		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

		if (setX[i].colour == 1)
		{
			SetConsoleTextAttribute(hOut, FOREGROUND_RED);
			cout << setX[i].value << "." << setX[i].gValue << " ";
		}
		else if (setX[i].colour == 2)

		{
			SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
			cout << setX[i].value << "." << setX[i].gValue << " ";
		}
		else
		{
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << setX[i].value << "." << setX[i].gValue << " ";
		}

		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	}
	cout << endl;
}