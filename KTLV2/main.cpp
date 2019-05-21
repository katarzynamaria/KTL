#include "Game.h"
#include "Strategy.h"
using namespace std;

int main(){
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
	
	//Gameboard plansza(k,x,30);

	//Player* gracz1 = new Player(new Maker, plansza, 1);
	

	
	//system("pause");
	//smiecie,smiecie
	
	

	//while (!gra.EndOfGame(gracz2))
	//{
	//	gra.PlayerMove(gracz1);
	//	gra.PlayerMove(gracz2);
	//	gra.ShowStatus();

		//tutaj moze ty wygladac inaczej w zale¿noœci od tego czy bêdziemy sprawdzaæ kryterium zwyciestwa
		//po ka¿dym ruchu, czy po ka¿dej 'turze' (tj. dwóch ruchach)

	//}
	//Gra.ShowWinner();	
	
	return 0;
}
