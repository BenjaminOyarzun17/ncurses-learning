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

void change(char c, int &y, int &x){
	switch (c){
		case 'j':
			y++;
			break;
		case 'k':
			y--;
			break;
		case 'h':
			x--;
			break;
		case 'l':

			x++;
			break;
	}
}






int main(int argc, char **argv)

{	

	initscr();
	cbreak();
	noecho();
	int yM, xM;
	int iwy, iwx, iwy0, iwx0;

	int wx, wy;

	getmaxyx(stdscr, yM, xM);
	iwy=iwy0=yM/3;

	iwx=iwx0=xM/3;
	WINDOW * inputwin = newwin(iwy, iwx, iwy0, iwx0);
	box(inputwin,0, 0);
	wx = 1; wy =1;
	wmove(inputwin,wy ,wx);

	wrefresh(inputwin);
	keypad(inputwin, true);
	int c = wgetch(inputwin);
	while(c!='q'){
		switch(c){
			case 'j':
				change(c, wy, wx);
				wmove(inputwin,wy ,wx);
				wrefresh(inputwin);
				break;

			case 'h':

				change(c, wy, wx);
				wmove(inputwin,wy ,wx);
				wrefresh(inputwin);
				break;

			case 'l':
				change(c, wy, wx);
				wmove(inputwin,wy ,wx);
				wrefresh(inputwin);
				break;
			case 'k':
				change(c, wy, wx);
				wmove(inputwin,wy ,wx);
				wrefresh(inputwin);
				break;
			case 'q':
				
				mvwprintw(inputwin, 1,1,"exiting...");
				wrefresh(inputwin);
				wgetch(inputwin);
				endwin();
				break;
			default: 
				mvwprintw(inputwin, 1,1,"I dont recognize that character...");
		
		}
		c = wgetch(inputwin);

	}

	return 0;
}





