#pragma once

#define PRINT_CHARACTERS 15 + 12784
#define RAIN_DROP_LENGTH_RAND 15 + 3

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>
#include <ncurses.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>

typedef struct s_rain_drop
{
    int len_rain;
    int len_empty;

    int rain_offset;
    int empty_offset;

    bool is_fell;
} t_rain_drop;

t_rain_drop *mx_init_raindrops(int my);

int mx_strlen(const char *s);

bool mx_input_manager_intro(int timeout);
bool mx_input_manager_rain(int *speed, int *color);

void mx_intro(char const *argv);
void mx_init_screen();
void mx_printerr(const char *s);
void mx_raindrop_algorithm(int mx, int my, t_rain_drop *raindrops, int *color);

