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
	noecho();
	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);
	

	WINDOW * inputwin = newwin(3, xMax-12, yMax-5, 5);

	box(inputwin, 0, 0 );
	refresh();

	wrefresh(inputwin);
	keypad(inputwin, true);//permite la lectura de las arrows
	int c = wgetch(inputwin);
	switch(c){
		case 'j':
			mvwprintw(inputwin, 1,1,"you pressed j!");
			wrefresh(inputwin);
			break;
		case 'k':
	
			mvwprintw(inputwin, 1,1,"you pressed k!");
			wrefresh(inputwin);
		case KEY_UP:

			mvwprintw(inputwin, 1,1,"you pressed up arrow!");
			wrefresh(inputwin);
		default: 

			
			mvwprintw(inputwin, 1,1,"I dont recognize that character...");
		
	}
	getch();

	endwin();
	return 0;
}




