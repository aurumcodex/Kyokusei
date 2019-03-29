// include.h
// need to put some prototypes in, at least.

#include <gba.h>

#ifndef INCLUDE_H
#define INCLUDE_H

typedef u16 COLOR;
#define INLINE      static inline
#define vid_mem     ((u16*)VRAM)

 COLOR RGB15(u32 red, u32 green, u32 blue);
 void m3_plot(int x, int y, COLOR color);

#endif