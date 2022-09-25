#include "header.h"

t_rain_drop *mx_init_raindrops(int my)
{
    t_rain_drop *raindrops = malloc(sizeof(t_rain_drop) * my);

    if (raindrops == NULL)
    {
        exit(-1);
    }

    for (int i = 0; i < my; i++)
    {
        srand(time(NULL) + i);
        raindrops[i].len_empty = rand() % RAIN_DROP_LENGTH_RAND;
        srand(time(NULL) + (i + raindrops[i].len_empty));
        raindrops[i].len_rain = rand() % RAIN_DROP_LENGTH_RAND;

        raindrops[i].rain_offset = 0;
        raindrops[i].empty_offset = 0;
        raindrops[i].is_fell = false;
    }

    return raindrops;
}

