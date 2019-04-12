#include <gba.h>
#include "sprites.h"

void updateOAM(int count) {
    for (int i = 0; i < count * sizeof(OBJATTR) / 4; i++) {
        ((u32*)OAM)[i] = ((u32*)obj_buffer)[i];
    }
}

void updatePos(int i, int x, int y)
{
    obj_buffer[i].attr1 &= 0xFE00;
    obj_buffer[i].attr1 |= (x & 0x01FF);
    obj_buffer[i].attr0 &= 0xFF00;
    obj_buffer[i].attr0 |= (y & 0x00FF);
}

void setupSprite(int i, int x, int y, int index, int palette)
{
    obj_buffer[i].attr2 = OBJ_CHAR(index) | OBJ_PALETTE(palette);
    updatePos(i, x, y);
}

void setupSprite64x64(int i, int x, int y, int index, int palette)
{
    obj_buffer[i].attr0 = OBJ_16_COLOR | OBJ_SQUARE;
    obj_buffer[i].attr1 = ATTR1_SIZE_64;
    setupSprite(i, x, y, index, palette);
}

void setupSprite64x32(int i, int x, int y, int index, int palette)
{
    obj_buffer[i].attr0 = OBJ_16_COLOR | OBJ_WIDE;
    obj_buffer[i].attr1 = ATTR1_SIZE_64;
    setupSprite(i, x, y, index, palette);
}

void setupSprite16x16(int i, int x, int y, int index, int palette)
{
    obj_buffer[i].attr0 = OBJ_16_COLOR | OBJ_SQUARE;
    obj_buffer[i].attr1 = ATTR1_SIZE_16;
    setupSprite(i, x, y, index, palette);
}