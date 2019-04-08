// 極性 -Kyokusei-
// a GBA homebrew game

#include <gba.h>
#include <gba_sprites.h>
// #include <lua.h>
// #include <lualib.h>
// #include <luaxlib.h>
#include "include.h"
#include "pumpkin.h"


int main()
{
    // lua thing
    // lua_State* lua = luaL_newstate();
    // luaL_openlibs(lua);
    // luaL_dotfile(lua, "script.lua");


    COLOR purple = RGB15(14, 9, 17);
    
    irqInit();
    REG_IME = 1;

    REG_DISPCNT = (MODE_0 | OBJ_ON | OBJ_1D_MAP | BG0_ON | BG1_ON | BG2_ON);

    setRepeat(1, 1);

    m3_plot(120, 80, RGB15(31, 0, 0));
    m3_plot(136, 80, RGB15(0, 31, 0));
    m3_plot(120, 96, RGB15(0, 0, 31));
    m3_plot(136, 96, RGB15(31, 31, 31));

    // int x = 40;
    // int y = 40;

    // m3_plot(x, y, purple);

    // draw_line(x+10, y+10, 100, 2, RGB15(12, 12, 0));

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
            // m3_plot(x+time, ((y+time)%4), RGB15(0, 0, 0));
        }
        time++;
    }

    return 0;
}