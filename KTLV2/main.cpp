#include "Game.h"
#include <time.h>
#include "Strategy.h"
using namespace std;

int main() {

	srand(time(NULL));

	int x = 0, k = 0, strategy;

	cout << "----------- START GRY -----------" << endl;
	while (x <= 2 * k + 1)
	{
		cout << "Moc zbioru X: ";
		cin >> x;
		cout << "Dlugosc ciagu: ";
		cin >> k;
		if (x <= 2 * k + 1) cout << "Niepoprawne dane. Wpisz jeszcze raz" << endl;
	}
	cout << "Strategie gracza: " << endl;
	cout << "1 - agresywny vs agresywny" << endl;
	cout << "2 - agresywny vs defensywny(naiwny)" << endl;
	cout << "3 - agresywny vs defensywny" << endl;
	cout << "Wybrana strategia: ";
	cin >> strategy;


	Game gra(x, k, strategy, new Gameboard(k, x, k*x));
	gra.AddPlayer(new Maker(), 1);
	gra.AddPlayer(new BreakerEasy(), 2);

	//system("pause");

	while (true)
	{
		gra.PlayerMove(0);
		gra.ShowStatus();
		if (gra.EndOfGame()) break;
		gra.PlayerMove(1);
		gra.ShowStatus();
		if (gra.EndOfGame()) break;
		//gra.ShowStatus();


	}

	system("pause");
	
}