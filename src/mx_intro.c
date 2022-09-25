#include "header.h"

void mx_intro(char const *argv)
{
    if (argv != NULL)
    {
        if (mx_strlen(argv) > 2 || argv[0] != '-' || argv[1] != 's')
        {
            endwin();
            mx_printerr("input: ./matrix_rain [-s]\n");
            exit(-1);
        }

        if (argv[1] == 's')
            return;
    }

    char *intro[] = {
        "Wake up , Neo..",
        "The Matrix has you..",
        "Follow the white rabbit",
        "Knock, knock, Neo"};

    for (int i = 0; i < 4; i++)
    {
        refresh();
        for (int j = 0; j < mx_strlen(intro[i]); j++)
        {
            attron(COLOR_PAIR(1));
            mvaddch(5, j + 4, intro[i][j]);
            attroff(COLOR_PAIR(1));

            refresh();

            if (mx_input_manager_intro(200))
                return;
        }
        if (mx_input_manager_intro(1000))
            return;

        clear();
    }
}

