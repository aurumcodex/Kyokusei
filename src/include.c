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

void draw_line(u32 x, u32 y, u32 length, u8 direction, COLOR color)
{
    if (direction == 0) {
        for (int i = 0; i < length; i++) {
            m3_plot(i, y, color);
        }
    }
    if (direction == 1) {
        for (int i = 0; i < length; i++) {
            m3_plot(x, i, color);
        }
    }
    if (direction == 2) {
        for (int i = 0; i < length; i++) {
            m3_plot(x+i, y+i, color);
        }
    }
    if (direction == 3) {
        for (int i = 0; i < length; i++) {
            m3_plot(x, y-i, color);
        }
    }
}

void m3_fill(COLOR color)
{
    int ii;
    u32 *dst = (u32*)vid_mem;
    u32 wd = (color<<16) | color;

    for (ii = 0; ii < M3_SIZE/4; ii++) {
        *dst++= wd;
    }
}