#include "header.h"

bool mx_input_manager_rain(int *speed, int *color)
{
    wtimeout(stdscr, *speed);

    char ch = getch();

    if (ch == 'q')
    {
        return true;
    }
    else if (ch == 'w')
    {
        *speed = 50;
    }
    else if (ch == 'e')
    {
        *speed = 500;
    }
    else if (ch == '1')
    {
        *color = 1;
    }
    else if (ch == '2')
    {
        *color = 2;
    }
    else if (ch == '3')
    {
        *color = 3;
    }

    return false;
}

bool mx_input_manager_intro(int timeout)
{
    wtimeout(stdscr, timeout);

    if (getch() == ' ')
    {
        clear();
        return true;
    }

    return false;
}

