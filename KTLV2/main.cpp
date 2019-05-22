#include "Game.h"
#include <time.h>
#include "Strategy.h"
using namespace std;

int main(){

	srand(time(NULL));

	int x=0, k=0, strategy;
	
	cout << "----------- START GRY -----------" << endl;
	while (x <= 2 * k + 1)
	{
		cout << "Moc zbioru X: ";
		cin >> x;
		cout << "Dlugosc ciagu: ";
		cin >> k;
		if (x <= 2 * k + 1) cout << "Niepoprawne dane. Wpisz jeszcze raz"<<endl;
	}
		cout << "Strategie gracza: " << endl;
		cout << "1 - agresywny vs agresywny" << endl;
		cout << "2 - agresywny vs defensywny(naiwny)" << endl;
		cout << "3 - agresywny vs defensywny" << endl;
		cout << "Wybrana strategia: ";
		cin >> strategy;
	
	Game gra(x, k, strategy);
	gra.AddPlayer(new Maker(), 0);
	gra.AddPlayer(new BreakerHard(), 1);

	//system("pause");

	while (true)
	{
		gra.PlayerMove(0);
		if (gra.EndOfGame()) break;
		gra.PlayerMove(1);
		if (gra.EndOfGame()) break;
		gra.ShowStatus();


	}

	
	return 0;
}
