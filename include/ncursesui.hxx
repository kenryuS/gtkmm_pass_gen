#ifndef NCURSESUI_HXX
#define NCURSESUI_HXX
#include <config.h>

#if USE_NCURSES == 1
#include <cstdlib>
#include <form.h>
#include <ncurses.h>
#include <menu.h>
#include <string>

#define WINDOW_WIDTH 45
#define WINDOW_HEIGHT 15

#define ARR_SIZE(a) (sizeof(a) / sizeof(a[0]))

namespace NcursesUI {
    auto ncursesMain() -> int;
    
    auto driver(int key_input, WINDOW* win, MENU* menu) -> void;

    auto createWindow(int width, int height, int startx, int starty) -> WINDOW*;
    auto destroyWindow(WINDOW* win) -> void;
}
#endif // USE_NCURSES == 1
#endif // NCURSESUI_HXX
