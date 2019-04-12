// include.h
// need to put some prototypes in, at least.

#include <gba.h>
// #include <tonc.h>

#ifndef INCLUDE_H
#define INCLUDE_H

typedef u16 COLOR;
#define INLINE      static inline
#define vid_mem     ((u16*)VRAM)
#define M3_SIZE     0x12c00

#define PALETTESIZE   16
#define PALETTELEN    8
#define TILEBG0LEN    664
#define BGMAPLEN      1024

COLOR RGB15(u32 red, u32 green, u32 blue);
void m3_plot(int x, int y, COLOR color);

void draw_line(u32 x, u32 y, u32 length, u8 direction, COLOR color);
void m3_fill(COLOR color);

#endif