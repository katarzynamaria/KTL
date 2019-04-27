#include "Game.h"
#include "Player.h"
#include "Gameboard.h"
#include <iostream>

using namespace std;

int main(){

	Game Gra;
	Gra.GameStart();

	//gracze tutaj tylko roboczo zeby na mnie kompilator nie krzyczal :p
	Player Gracz1;
	Player Gracz2; 

	Gra.ShowGameboard();
	while (!Gra.EndOfGame())
	{
		Gra.PlayerMove(Gracz1);
		Gra.PlayerMove(Gracz2);
		Gra.ShowStatus();

		//tutaj moze ty wygladac inaczej w zale�no�ci od tego czy b�dziemy sprawdza� kryterium zwyciestwa
		//po ka�dym ruchu, czy po ka�dej 'turze' (tj. dw�ch ruchach)

	}
	Gra.ShowWinner();	
}