// 極性 -Kyokusei-
// a GBA homebrew game

#include <gba.h>
#include "include.h"



int main()
{

    REG_DISPCNT = (MODE_3 | BG2_ON);

    m3_plot(120, 80, RGB15(31, 0, 0));
    m3_plot(136, 80, RGB15(0, 31, 0));
    m3_plot(120, 96, RGB15(0, 0, 31));
    m3_plot(136, 96, RGB15(31, 31, 31));

    do
    {
        /* code */
    } while (1);
    
    return 0;
}