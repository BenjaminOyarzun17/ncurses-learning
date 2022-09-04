#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <ncurses.h>
using namespace std;

int main(int argc, char **argv)

{	

	initscr();
	cbreak();
	noecho();
	int yM , xM;
	getmaxyx(stdscr, yM, xM);
	WINDOW * inputwin=newwin(6, xM-12, yM-8, 5);
	box(inputwin, 0, 0);
	refresh();
	wrefresh(inputwin);
	keypad(inputwin, true);

	string opciones[3]={"walk", "jog", "run"};

	int c;
	int selected=0;


	while(1){
		for(int i= 0 ; i< 3 ;i++){
			if(i==selected){
				wattron(inputwin, A_REVERSE);
				mvwprintw(inputwin,i+1, 1, opciones[i].c_str() );
				wattroff(inputwin, A_REVERSE);
			}
		}
		c= wgetch(inputwin);

		switch (c){
			case KEY_UP:
				selected--;
				if(selected==-1)selected= 0;
				break;
			case KEY_DOWN:
				selected++;
				if(selected==3)selected=2;
				break;
			default:
				break;
			
		}
		if(c==10)break;//10 es enter
	}
	printw("finalizado");
	getch();
	endwin();

	return 0;
}






