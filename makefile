all: first
first: first.cpp
	gcc -lncurses first.cpp -o first

