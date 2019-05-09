#include "Strategy.h"

using namespace std;

int main(){

	Game gra;
	int k=0;
	int x=0;
	int strategy=0;
	gra.GameStart(k,x, strategy);
	Gameboard plansza(3,15,30);
	//Player* gracz1 = new Player(new Maker, plansza, 1);

	cout << "skonczylem tworzyc plansze" << endl;
	plansza.ShowGameboard();
	
	system("pause");
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
	system("Pause");
}
