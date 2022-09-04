#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <ncurses.h>
using namespace std;


/*
para compilar: 
gcc -lncurses archivo.cpp -o archivo
o sino usar "make"
*/


int main(int argc, char **argv)

{	
	initscr();
	//move(y,x): mueve el cursor (lugar donde se escribe
	int x, y;
	x= 10; y=10;
	move(y,x);



	printw("hola mundo");
	


	//refrezca la pantalla
	refresh();
	//espera al input del usuario
	int c =getch();

	move(30, 10);
	printw("%d", c);
	mvprintw(0, 0 , "texto movido e imprimido")	;

	//clear(): limpia la pantalla
	getch();

	endwin();
	return 0;
}
