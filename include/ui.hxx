#ifndef UI_HXX
#define UI_HXX

// enumeration of states of program
enum PROGRAMSTATE : int {
    SUCCESS, // 0
    FAIL // 1
};

#include <string>
#include <cstring>
#include <utils.hxx>
#include <passgen.hxx>
#include <gtkui.hxx>

/**
* @brief runs the CUI version of program
* @param len length of the password (int)
* @param upper boolean flag for upper case alphabets
* @param lower boolean flag for lower case alphabets
* @param num boolean flag for numbers
* @param special boolean flag for special characters
* @return (int) - execution state of program
*/
inline auto runcui(const unsigned int& len, const bool& upper, const bool& lower, const bool& num, const bool& special) -> int {
    // appends letters to input
    std::string input;
    try {
        if (upper) {input += PassGen::getUpperAlpha();}
        if (lower) {input += PassGen::getLowerAlpha();}
        if (num) {input += PassGen::getNumber();}
        if (special) {input += PassGen::getSpecialChars();}
    }
    // print out error when any of getChars threw exception
    catch (PassGen::exceptions::memoryAllocationFailiure &err) {
        printLine(err.what());
        return FAIL;
    }

    // converts to std::string to pure C string
    char *cInput = new char[input.length() + 1];
    strcpy(cInput, input.c_str());

    // generate password, report error and exit with status of 1 (failiure) if any caught
    char *out = nullptr;
    try {
        out = PassGen::passGen(cInput, len);
    }
    // print out error when PassGen::passGen threw exception
    catch (PassGen::exceptions::memoryAllocationFailiure &err) {
        printLine(err.what());
        return FAIL;
    }
    catch (PassGen::exceptions::noCharList &err) {
        printLine(err.what());
        return FAIL;
    }
    catch (...) {
        PassGen::exceptions::exception error = PassGen::exceptions::unknownError();
        printLine(error.what());
        return FAIL;
    }

    // prints password, and exit with status of 0 (success)
    std::cout << out << std::endl;
    return SUCCESS;
}

/**
* @brief runs the GUI version of program
* @return (int) - execution state of program
*/
inline auto rungui() -> int {
    // run the GTK application
    auto app = Gtk::Application::create("apcsp.passgen");
    return app->make_window_and_run<PassGenUI>(0,nullptr); // run GTK app with no arguments
}

#endif // UI_HXX
