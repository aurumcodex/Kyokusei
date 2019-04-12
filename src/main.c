// 極性 -Kyokusei-
// a GBA homebrew game

#include <gba.h>
// #include <tonc.h>
#include <gba_sprites.h>
// #include <lua.h>
// #include <lualib.h>
// #include <luaxlib.h>
#include <stdio.h>

#include "include.h"
#include "spr_pumpkin.h"

u8 txt_scrolly = 8;

const char *names[] = 
{ "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B " };

void note_prep(int octave) {
    char str[32];
    snprintf(str, "[  %+2d]", octave);
    se_puts(8, txt_scrolly, str, 0x1000);
}

int main()
{
    // lua things
    // lua_State* lua = luaL_newstate();
    // luaL_openlibs(lua);
    // luaL_dotfile(lua, "script.lua");


    COLOR purple = RGB15(14, 9, 17);
    
    // irqInit();
    // REG_IME = 1;

    // REG_DISPCNT = (MODE_0 | OBJ_ON | OBJ_1D_MAP | BG0_ON | BG1_ON | BG2_ON);

    REG_DISPCNT = (MODE_3 | BG2_ON);

    setRepeat(1, 1);

    m3_plot(120, 80, RGB15(31, 0, 0));
    m3_plot(136, 80, RGB15(0, 31, 0));
    m3_plot(120, 96, RGB15(0, 0, 31));
    m3_plot(136, 96, RGB15(31, 31, 31));

    // REG_BG0CNT = BG_16_COLOR | BG_MAP_BASE(31) | BG_TILE_BASE(0) | BG_WRAP | BG_SIZE_0 | 0;
    // REG_BG1CNT = BG_16_COLOR | BG_MAP_BASE(29) | BG_TILE_BASE(1) | BG_WRAP | BG_SIZE_0 | 1;
    // REG_BG2CNT = BG_16_COLOR | BG_MAP_BASE(27) | BG_TILE_BASE(1) | BG_WRAP | BG_SIZE_0 | 2;

    int x = 40;
    int y = 40;

    // m3_plot(x, y, purple);

    draw_line(x-10, y+10, 100, 2, RGB15(31, 21, 11));
    draw_line(x-10, y+10, 100, 1, RGB15(31, 12, 0));
    draw_line(x+10, y-5, 100, 2, RGB15(12, 9, 9));
    draw_line(x+5, y+10, 100, 0, RGB15(12, 21, 21));
    draw_line(x*2, y-10, 100, 3, RGB15(12, 12, 12));
    draw_line(x+10, y*2, 100, 3, RGB15(12, 12, 31));

    // u16* bgpal = BG_PALETTE;
    // for (int i = 0; i < PALETTESIZE; i++) {
    //     *bgpal++ == ((u16*)spr_pumpkinPal)[i];
    // }

    // CpuFastSet(spr_pumpkinTiles, CHAR_BASE_ADR(0), COPY32 | TILEBG0LEN);
    // CpuFastSet(spr_pumpkinMap, CHAR_BASE_ADR(31), COPY32 | BGMAPLEN);

    // updateOAM(128);

    int time = 0;
    while(1){
        /* code */
        VBlankIntrWait();
        scanKeys();

        u16 keys = keysDownRepeat();

        m3_plot(x, y, purple);

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