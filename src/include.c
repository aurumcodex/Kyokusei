// include.h
// need to put some function bodies in, at least.

#include <gba.h>
#include "include.h"

COLOR RGB15(u32 red, u32 green, u32 blue)
{
    return red | (green<<5) | (blue<<10);
}

void m3_plot(int x, int y, COLOR color)
{
    vid_mem[y*SCREEN_WIDTH+x] = color;
}