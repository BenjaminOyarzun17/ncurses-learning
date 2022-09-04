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
	int height, width, start_y, start_x;
	height= 10;//lineas
	width= 20;
	start_y= start_x= 10;

	WINDOW * win = newwin (height, width, start_y, start_x);//ojo que es un puntero a una ventana
	refresh();//sincroniza los cambios con la pantalla
	box(win, 0, 0 );
	mvwprintw(win, 1,1 ,"this is the box");//mueve el mensaje
	wrefresh(win);//refrezca la ventana
	int c =getch();

	getch();

	endwin();
	return 0;
}

