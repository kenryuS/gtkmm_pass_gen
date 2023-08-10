#ifndef UI_HXX
#define UI_HXX

// enumeration of states of program
enum PROGRAMSTATE : int {
    SUCCESS, // 0
    FAIL // 1
};

// include libraries for string operations
#include <string>
#include <cstring>
// include utilities, passgen functions, and GUI app
#include <utils.hxx>
#include <passgen.hxx>
#include <main.hxx>
#include <config.h>

/**
* @brief runs the CUI version of program
* @param len length of the password (int)
* @param flg structure with flags, defined in main.hxx
* @return (int) - execution state of program
*/
inline auto runcui(const unsigned int& len, const flags flg) -> int {
    // appends letters to input
    std::string input;
    try {
        if (flg.upAlphaFlag) {input += PassGen::getUpperAlpha();}
        if (flg.lowAlphaFlag) {input += PassGen::getLowerAlpha();}
        if (flg.numFlag) {input += PassGen::getNumber();}
        if (flg.specialCharFlag) {input += PassGen::getSpecialChars();}
    }
    // print out error when any of getChars threw exception
    catch (PassGen::exceptions::memoryAllocationFailiure &err) {
        printErr(err.what());
        return FAIL;
    }

    // converts to std::string to pure C string
    char *cInput = new char[input.length() + 1]; // allocate memory for length of input and 1 terminate character
    strcpy(cInput, input.c_str()); // copy the input to cInput

    // generate password, report error and exit with status of 1 (failiure) if any caught
    char *out = nullptr; // initialize with nullptr
    try {
        out = PassGen::passGen(cInput, len); // generate password
    }
    // print out error when PassGen::passGen threw exception
    catch (PassGen::exceptions::memoryAllocationFailiure &err) {
        printErr(err.what());
        return FAIL;
    }
    catch (PassGen::exceptions::noCharList &err) {
        printErr(err.what());
        return FAIL;
    }
    catch (...) {
        PassGen::exceptions::exception error = PassGen::exceptions::unknownError();
        printErr(error.what());
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
#if USE_GTK == 1
#include <gtkui.hxx>
inline auto rungui() -> int {
    // run the GTK application
    auto app = Gtk::Application::create("apcsp.passgen"); // create instance of application
    return app->make_window_and_run<PassGenUI>(0,nullptr); // run GTK app with no arguments
}
#endif // USE_GTK == 1

#endif // UI_HXX
