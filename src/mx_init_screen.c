#include "header.h"

void mx_init_screen()
{
    initscr();
    noecho();
    curs_set(0);
    start_color();
    init_color(0, 0, 0, 0);
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_WHITE, COLOR_BLACK);
}

