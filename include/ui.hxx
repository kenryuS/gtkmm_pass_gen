#ifndef UI_HXX
#define UI_HXX

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
        printLine("\nError: Length not specified");
        return 1;
    }

    if (checkFlags(up, low, num, special) == false) {
        printhelp();
        printLine("\nError: No character flag(s) specified");
        return 1;
    }

    // appends letters to input
    if (up) {input += getUpperAlpha();}
    if (low) {input += getLowerAlpha();}
    if (num) {input += getNumber();}
    if (special) {input += getSpecialChars();}

    // converts to std::string to pure C string
    char *cInput = new char[input.length() + 1];
    strcpy(cInput, input.c_str());

    // generate and prints password
    char *out = passGen(cInput, len);
    printLine(out);
    return 0;
}

int rungui(int argc, char** argv) {
    // run the GTK application
    auto app = Gtk::Application::create("io.apcsp.passgen");
    return app->make_window_and_run<PassGenUI>(argc, argv);
}

#endif // UI_HXX
