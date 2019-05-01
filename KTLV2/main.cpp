#include "Game.h"
#include "Player.h"
#include "Gameboard.h"
#include <iostream>

using namespace std;

int main(){

	Game gra;
	int k=0;
	int x=0;
	int strategy=0;
	gra.GameStart(k,x, strategy);
	Gameboard plansza(k, x);
	Player* gracz1 = new Player(new Maker, plansza, 1);

	/*switch (strategy)
	{
	case 1:
		Player* gracz1 = new Player(new Maker, plansza, 1);
		Player* gracz2 = new Player(new Maker, plansza, 2);
		break;

	case 2:
		Player* gracz1 = new Player(new Maker, plansza, 1);
		Player* gracz2 = new Player(new BreakerEasy, plansza, 2);
		break;

	case 3:
		Player* gracz1 = new Player(new Maker, plansza, 1);
		Player* gracz2 = new Player(new BreakerHard, plansza, 2);
		break;
	}*/
	plansza.ShowGameboard();
	
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
