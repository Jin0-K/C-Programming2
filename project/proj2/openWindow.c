
#include <stdio.h>
#include <ncurses.h>

int main(void) {
	int height, width, start_y, start_x;
	WINDOW *my_win;

	initscr();

	height = 10;
	width = 20;
	start_y = start_x = 10;

	my_win = newwin(height, width, start_y, start_x);
	refresh();

	wprintw(my_win, "0, 0 is here");
	mvwprintw(my_win, 1, 0, "Test printing\n");
	wrefresh(my_win);

	getch();
	endwin();

	return 0;
}
