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

	plansza.ShowGameboard();

	//smiecie,smiecie
	
	//while (!gra.EndOfGame(gracz2))
	//{
	//	gra.PlayerMove(gracz1);
	//	gra.PlayerMove(gracz2);
	//	gra.ShowStatus();

		//tutaj moze ty wygladac inaczej w zale�no�ci od tego czy b�dziemy sprawdza� kryterium zwyciestwa
		//po ka�dym ruchu, czy po ka�dej 'turze' (tj. dw�ch ruchach)

	//}
	//Gra.ShowWinner();	
	system("Pause");
}
