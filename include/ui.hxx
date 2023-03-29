#ifndef UI_HXX
#define UI_HXX

#include <string>
#include <cstring>
#include <span>
#include <utils.hxx>
#include <passgen.hxx>
#include <gtkui.hxx>
using namespace PassGen;

/**
* @brief runs the CUI version of program
* @param len length of the password (int)
* @param upper boolean flag for upper case alphabets
* @param lower boolean flag for lower case alphabets
* @param num boolean flag for numbers
* @param special boolean flag for special characters
* @return (int) - execution state of program
*/
auto runcui(const unsigned int& len, const bool& upper, const bool& lower, const bool& num, const bool& special) -> int {
    std::string input;

    if (len < 0) {
        printHelp();
        printLine("\nError: Length has to be larger than 0");
        return 1;
    }

    if (!checkFlags(upper, lower, num, special)) {
        printHelp();
        printLine("\nError: No character flag(s) specified");
        return 1;
    }

    // appends letters to input
    if (upper) {input += getUpperAlpha();}
    if (lower) {input += getLowerAlpha();}
    if (num) {input += getNumber();}
    if (special) {input += getSpecialChars();}

    // converts to std::string to pure C string
    char *cInput = new char[input.length() + 1];
    strcpy(cInput, input.c_str());

    // generate and prints password
    char *out = passGen(cInput, len);
    std::cout << "Generated Password: " << out << std::endl;
    return 0;
}

/**
* @brief runs the GUI version of program
* @param argc argument count (int)
* @param argv arguments (List of pure C strings)
* @return (int) - execution state of program
*/
auto rungui(int argc, char** argv) -> int {
    // run the GTK application
    auto app = Gtk::Application::create("apcsp.passgen");
    return app->make_window_and_run<PassGenUI>(argc, argv);
}

#endif // UI_HXX
