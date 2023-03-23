#ifndef UI
#define UI

#include <iostream>
#include <string>
#include <cstring>
#include <utils.hxx>
#include <passgen.hxx>
#include <gtkui.hxx>
using namespace PassGen;

int runcui(int len, bool up, bool low, bool num, bool special) {
    
    std::string input;

    if (len < 0) {
        printhelp();
        printf("\nError: Length not specified\n");
        return 1;
    }

    if (checkFlags(up, low, num, special) == false) {
        printhelp();
        printf("\nError: No character flag(s) specified\n");
        return 1;
    }

    if (up == true) {input += getUpperAlpha();}
    if (low == true) {input += getLowerAlpha();}
    if (num == true) {input += getNumber();}
    if (special == true) {input += getSpecialChars();}

    char *cInput = new char[input.length() + 1];
    strcpy(cInput, input.c_str());
    char *out = passGen(cInput, len);
    std::cout << out << std::endl;
    return 0;
}

int rungui(int argc, char** argv) {
    auto app = Gtk::Application::create("io.github.kenryus");
    return app->make_window_and_run<PassGenUI>(argc, argv);
}

#endif // UI
