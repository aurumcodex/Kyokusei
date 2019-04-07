#include <gba.h>

#ifndef GBA_SPRITES_H
#define GBA_SPRITES_H

OBJATTR obj_buffer[128];

void updatePos(int i, int x, int y);
void setupSprite(int i, int x, int y, int index, int palette);
void setupSprite64x64(int i, int x, int y, int index, int palette);
void setupSprite64x32(int i, int x, int y, int index, int palette);
void setupSprite16x16(int i, int x, int y, int index, int palette);

#endif