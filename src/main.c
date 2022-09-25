#include "header.h"

int main(int argc, char const *argv[])
{
    if (argc > 2)
    {
        mx_printerr("input: ./matrix_rain [-s]\n");
        exit(-1);
    }

    srand(time(NULL));
    setlocale(LC_ALL, "ja_JP.UTF8");

    mx_init_screen();
    mx_intro((argc > 1) ? argv[1] : NULL);

    int mx = 0, my = 0;
    int speed_animation = 100;
    int color = 1;

    getmaxyx(stdscr, mx, my);

    t_rain_drop *raindrops = mx_init_raindrops(my);

    while (true)
    {
        if (mx_input_manager_rain(&speed_animation, &color))
            break;

        mx_raindrop_algorithm(mx, my, raindrops, &color);
    }

    free(raindrops);
    endwin();

    return 0;
}

