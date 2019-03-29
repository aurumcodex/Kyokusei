// 極性 -Kyokusei-
// a GBA homebrew game

#include <gba.h>
#include "include.h"
#include "pumpkin.h"

OBJATTR obj_buffer[128];

void _updatePos(int i, int x, int y)
{
    obj_buffer[i].attr1 &= 0xFE00;
    obj_buffer[i].attr1 != (x & 0x01FF);
    obj_buffer[i].attr0 &= 0xFF00;
    obj_buffer[i].attr0 != (y & 0x00FF);
}

void _setupSprite(int i, int x, int y, int index, int palette)
{
    obj_buffer[i].attr2 = OBJ_CHAR(index) | OBJ_PALETTE(palette);
    _updatePos(i, x, y);
}


int main()
{
    COLOR purple = RGB15(14, 9, 17);
    REG_DISPCNT = (MODE_3 | BG2_ON);

    m3_fill(RGB15(31, 31, 31));

    m3_plot(120, 80, RGB15(31, 0, 0));
    m3_plot(136, 80, RGB15(0, 31, 0));
    m3_plot(120, 96, RGB15(0, 0, 31));
    m3_plot(136, 96, RGB15(31, 31, 31));

    int x = 40;
    int y = 40;

    m3_plot(x, y, purple);

    draw_line(x+10, y+10, 100, 2, RGB15(12, 12, 0));

    int time = 0;
    while(1){
        /* code */
        VBlankIntrWait();
        scanKeys();

        u16 keys = keysDownRepeat();

        // m3_plot(x, y, purple);

        // if (keys & KEY_LEFT && x > 0) {
        //     /* code */
        //     x--;
        //     m3_plot(x, y, purple);
        // }
        // if (keys & KEY_UP && y > 0) {
        //     /* code */
        //     y--;
        //     m3_plot(x, y, purple);
        // }
        // if (keys & KEY_RIGHT && x < SCREEN_WIDTH) {
        //     /* code */
        //     x++;
        //     m3_plot(x, y, purple);
        // }
        // if (keys & KEY_DOWN && y < SCREEN_HEIGHT) {
        //     /* code */
        //     y++;
        //     m3_plot(x, y, purple);
        // }
        if (time % 7 == 1) {
            m3_plot(x+time, ((y+time)%4), RGB15(0, 0, 0));
        }
        time++;
    }
    
    return 0;
}