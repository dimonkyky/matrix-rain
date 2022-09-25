#include "header.h"

static void print_raindrop(t_rain_drop *raindrops, int i, int *color)
{
    int rand_ch;

    if (raindrops[i].len_rain <= 0)
    {
        mvaddch(raindrops[i].empty_offset, i, ' ');
        raindrops[i].empty_offset++;
    }

    if (raindrops[i].is_fell)
        return;

    if (raindrops[i].rain_offset > 0)
    {
        rand_ch = mvinch(raindrops[i].rain_offset - 1, i);

        attron(COLOR_PAIR(*color));
        mvprintw(raindrops[i].rain_offset - 1, i, "%lc", rand_ch);
        attroff(COLOR_PAIR(*color));
    }

    rand_ch = rand() % PRINT_CHARACTERS;
    mvprintw(raindrops[i].rain_offset, i, "%lc", rand_ch);
}

void mx_raindrop_algorithm(int mx, int my, t_rain_drop *raindrops, int *color)
{
    for (int i = 0; i < my; i++)
    {
        if (i % 2 != 0)
            continue;

        if (raindrops[i].len_empty <= 0)
        {
            print_raindrop(raindrops, i, color);

            raindrops[i].rain_offset++;
            raindrops[i].len_rain--;

            if (raindrops[i].empty_offset + (raindrops[i].rain_offset - raindrops[i].empty_offset) > mx)
            {
                raindrops[i].is_fell = true;
            }

            if (raindrops[i].empty_offset >= mx)
            {
                raindrops[i].is_fell = false;
                raindrops[i].rain_offset = 0;
                raindrops[i].empty_offset = 0;
                raindrops[i].len_rain = rand() % RAIN_DROP_LENGTH_RAND;
            }
        }
        else
        {
            raindrops[i].len_empty--;
        }

        refresh();
    }
}

