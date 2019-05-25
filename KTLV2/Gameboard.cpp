#include "Gameboard.h"
#include <time.h>

void Gameboard::colorField(int index, int colour)
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
	cout << "CRITICAL FAIL - can't find " << value << " in setX";
	return -1;
}
int Gameboard::isNext(int* row, int x, int j)
{
	for (int i = j; i < setCard; ++i)
	{
		//if (row[i] > x) break;
		if (row[i] == x) return setX[i].value;
	}
	return -1;
}
bool Gameboard::isValid()
{
	vector<int> validSequence;
	for (int i = 0; i < setCard; i++)
	{
		int currentSize = 0;
		int multiplier = 1;
		for (int j = i + 1; j < setCard; ++j)
		{
			validSequence.push_back(setX[i].value);
			if (distMatrix[i][j] == 0) continue;
			while (isNext(distMatrix[i], distMatrix[i][j] * multiplier, j) != -1)
			{
				validSequence.push_back(isNext(distMatrix[i], distMatrix[i][j] * multiplier, j));
				currentSize++;
				multiplier++;
				if (currentSize == sequenceLenght) break;
			}
			if (currentSize == sequenceLenght)
			{
				cout << "Wygenerowano poprawny zbiór z ciagiem: " << endl;
				for (int i = 0; i < currentSize; i++)
				{
					cout << validSequence[i] << " ";
				
				}
				cout<<endl;
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
	for (int i = 0; i < hypergraph.size(); ++i)
	{
		Potential.push_back(pow(2, -sequenceLenght));
	}

}

Gameboard::Gameboard(int sequenceLength, int setCard, int range)
{
	this->sequenceLenght = sequenceLength;
	this->setCard = setCard;
	this->range = range;
	this->distMatrix = new int* [setCard];

	cout << "Prosze czekac. Generowanie poprawnego zbioru..." << endl;
	int j = 0;
	bool czy_dalej = 0;
	for (int i = 0; i < setCard; ++i)
	{
		distMatrix[i] = new int[setCard];

	}
	do
	{
		j++;
		if (j == 1000) {
			cout << endl;
			cout << "Nie udalo sie wylosowac poprawnego zbioru po 1000 probach. Czy chcesz kontynuowac?" << endl;
			cout << "1-TAK" << endl;
			cout << "0-NIE" << endl;
			cin >> czy_dalej;
			if (czy_dalej != 1)
			{
				conti = 0;
				break;
			}
			j = 0;
		}
		cout << ".";
		generateSet();


	} while (!isValid());

	if (conti == 0) exit;
	else {
		ShowGameboard();

		cout << "Prosze czekac. Generowanie hipergrafu..." << endl;
		generateHypergraph();
		showHypergraph();
		SetPotential();
		setPotentials();
	}
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


	Node v = *new Node();
	for (int i = 0; i < setCard; i++)
	{
		int index = rand() % notYetGenerated.size();
		v.value = notYetGenerated[index];
		notYetGenerated.erase(notYetGenerated.begin() + index);
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

void Gameboard::generateHypergraph()					//generuje hipergraf
{

	int index = 0;
	vector<Node*>* v = new vector<Node*>();

	for (int i = 0; i < setCard; ++i)
	{
		int currentSize = 0;
		int multiplier = 1;
		for (int j = i + 1; j < setCard;++j)
		{
			v->push_back(&setX[i]);
			currentSize++;
			while (true)
			{
				int value = isNext(distMatrix[i], distMatrix[i][j] * multiplier, j); //nastepny wyraz na podstawie IsNext
				if (value == -1) break;
				currentSize++;
				multiplier++;
				Node* node = findNodeWithValue(value);
				v->push_back(node);
				if (currentSize == sequenceLenght) break;
			}
			if (currentSize == sequenceLenght) //jezeli wybrany wyzej ciag jest dlugosci k to go dodajemy do hipergrafu
			{
				hypergraph.push_back(*v);
				setDegrees(*v, hypergraph.size() - 1);
			}
			v = new vector<Node*>();
			currentSize = 0;
			multiplier = 1;
		}
		cout << "...";
	}
	seqYetToChoose = hypergraph.size();
	cout << endl;
}

void Gameboard::showHypergraph() //wypisuje hipergraf
{
	cout << "Wylosowano nastepujace ciagi: " << endl;

	for (int i = 0; i < hypergraph.size(); ++i)

	{
		for (int j = 0; j < hypergraph[i].size(); ++j)
		{
			cout << hypergraph[i][j]->value << " ";
		}
		cout << endl;
	}
	cout << "-------------------------------------------------" << endl;
}

Gameboard::~Gameboard()			//destruktor do zwolnienia pamieci
{

	for (int i = 0; i < setCard; ++i)
	{
		delete[] distMatrix[i];
	}
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
			cout << setX[i].value << " ";
		}
		else if (setX[i].colour == 2)

		{
			SetConsoleTextAttribute(hOut, FOREGROUND_BLUE);
			cout << setX[i].value << " ";
		}
		else
		{
			SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
			cout << setX[i].value << " ";
		}

		SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	}
	cout << endl;
}