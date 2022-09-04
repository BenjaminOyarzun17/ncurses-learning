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
	cbreak();//permite que ctrl+C permita salir del programa
	//raw(): toma todo el input; no ejecuta ctrl+C, sino que solo lo lee como un caracter
	//noecho(): el input no aparece en la pantalla
	noecho();
	int height, width, start_y, start_x;

	height= 10;//lineas
	width= 20;
	start_y= start_x= 10;

	WINDOW * win = newwin (height, width, start_y, start_x);//ojo que es un puntero a una ventana
	refresh();//sincroniza los cambios con la pantalla
	//box(window, numero de caracter del borde de izq y derecha, numero de caracter del borde de arriba y abajo)
	box(win, 0, 0 );
	//otra opcion : box(win, (int)a, (int)b);
	mvwprintw(win, 1,1 ,"this is the box");//mueve el mensaje
	wrefresh(win);//refrezca la ventana
	int c =getch();

	getch();

	endwin();
	return 0;
}


