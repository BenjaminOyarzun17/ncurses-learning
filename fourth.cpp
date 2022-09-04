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
	cbreak();
	if(!has_colors()){
		printw("la terminal no soporta colores");
		getch();
		return -1;
	}
	int height, width, start_y, start_x;
	attron(A_REVERSE);//revierte colores del texto y bg
	printw("texto revertido");
	attron(A_STANDOUT);
	//attron edita basicamente el texto. depende mucho de la terminal que se esta usando. 
	//stdscr es la window default
	int y,x, yBeg, xBeg, yMax, xMax;
	
	getyx(stdscr, y, x);//obtiene la posicion del cursor actual. le asigna los respectivos valores a y y a x.
	getbegyx(stdscr,yBeg, xBeg);//obtiene la esquina superior 
	getmaxyx(stdscr, yMax, xMax);//obtiene height y width 
	printw("%d %d", y, x);


	height= 10;
	width= 20;
	start_y= start_x= 10;

	WINDOW * win = newwin (height, width, start_y, start_x);//ojo que es un puntero a una ventana
	refresh();//sincroniza los cambios con la pantalla
	box(win, 0, 0 );
	mvwprintw(win, 1,1 ,"this is the box");
	wrefresh(win);
	int c =getch();

	getch();

	endwin();
	return 0;
}



