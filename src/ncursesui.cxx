#include <config.h>
#include <ncursesui.hxx>

#if USE_NCURSES == 1
auto NcursesUI::ncursesMain() -> int {
    // Variables / Constants
    int rows = 0;
    int cols = 0;
    WINDOW* window = nullptr;
    int startx = 0;
    int starty = 0;
    int c = 0;

    std::string choices[] = {
        "Test 1",
        "Test 2",
        "Test 3",
        "Exit",
    };
    MENU* my_menu = (MENU*)nullptr;
    ITEM* cur_item = (ITEM*)nullptr;
    ITEM** my_items = (ITEM**)nullptr;
    int n_items = 0;

    // Initialization
    initscr();
    clear();
    noecho();

    getmaxyx(stdscr, rows, cols);
    startx = (cols - WINDOW_WIDTH) / 2;
    starty = (rows - WINDOW_HEIGHT) / 2;
    window = createWindow(WINDOW_WIDTH, WINDOW_HEIGHT, startx, starty);
    keypad(window, TRUE);
    
    n_items = ARR_SIZE(choices);
    my_items = (ITEM**)calloc(n_items + 1, sizeof(ITEM*));
    for (int i = 0; i < n_items; i++) {
        my_items[i] = new_item(choices[i].c_str(), choices[i].c_str());
    }
    my_items[n_items] = new_item((char*)NULL, (char*)NULL);

    my_menu = new_menu(my_items);
    
    set_menu_win(my_menu, window);
    set_menu_sub(my_menu, derwin(window, WINDOW_HEIGHT - 4, WINDOW_WIDTH - 4, starty - 1, startx - 3));
    set_menu_mark(my_menu, " * ");
    box(window, 0,0);

    refresh();
    post_menu(my_menu);
    wrefresh(window);
    
    // Window Update
    while ((c = wgetch(window)) != KEY_F(1)) {
        driver(c, window, my_menu);
    }
    
    // Clean Up
    unpost_menu(my_menu);
    free_menu(my_menu);
    for (int i = 0; i < n_items + 1; i++) {
        free_item(my_items[i]);
    }
    destroyWindow(window);
    endwin();
    return 0;
}

auto NcursesUI::driver(int key_input, WINDOW* win, MENU* menu) -> void {
    switch (key_input) {
        case KEY_UP:
            menu_driver(menu, REQ_UP_ITEM);
            break;
        case KEY_DOWN:
            menu_driver(menu, REQ_DOWN_ITEM);
            break;
    }
    wrefresh(win);
}

auto NcursesUI::createWindow(int width, int height, int startx, int starty) -> WINDOW* {
    WINDOW* resWin;
    resWin = newwin(height, width, starty, startx);
    box(resWin, 0, 0);
    wrefresh(resWin);
    return resWin;
}

auto NcursesUI::destroyWindow(WINDOW* win) -> void {
    wborder(win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    wrefresh(win);
    delwin(win);
}
#endif // USE_NCURSES == 1
