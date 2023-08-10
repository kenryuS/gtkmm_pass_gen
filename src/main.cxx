#include "utils.hxx"
#include <cxxopts.hpp> // command line argument parser library written by jarro2783 (https://github.com/jarro2783/cxxopts)
#include <main.hxx>
#include <ui.hxx>

auto main(int argc, char** argv) -> int{
    // flags for program arguments
    flags flgs = {0};

    // other variable change by the flags
    unsigned int length = 0;
    // execution state (-1 for init value)
    int state = -1;
    bool flagEnabled = false;

    // specifies options
    cxxopts::Options options("APCSP Create Task", "Random Password Generator");
    options.add_options()
        ("A,upper", "Include upper case alphabets")
        ("a,lower", "Include lower case alphabets")
        ("n,number","Include numbers")
        ("s,special", "Include special characters")
        ("l,length", "Set the length of password", cxxopts::value<int>())
        ("g,gui", "Run the GUI version of program if built with USE_GTK flag, other passed arguments are ignored")
        ("h,help", "Print help")
        ("b,build-info","Print build option values used in this build")
    ;

    // parse options from argv with fail safe
    cxxopts::ParseResult result;
    try {
        result = options.parse(argc, argv);
    } catch (const cxxopts::exceptions::parsing &e) {
        std::cout << options.help() << std::endl;
        printErr(e.what());
        return FAIL;
    }

    // sets flags and option value from options(argc and argv)
    // help flag (show help doc and exit)
    if (result.count("help")) {
        std::cout << options.help() << std::endl;
        return SUCCESS;
    }

    // build option information
    if (result.count("build-info")) {
        printBuildOpt();
        return SUCCESS;
    }

    // GUI flag
    flgs.guiFlag = result.count("gui");

    // char flags
    flgs.upAlphaFlag = result.count("upper");
    flgs.lowAlphaFlag = result.count("lower");
    flgs.numFlag = result.count("number");
    flgs.specialCharFlag = result.count("special");
    flagEnabled = checkFlags(flgs);

    // length option
    if (result.count("length") && !flgs.guiFlag && flagEnabled) {
        length = result["length"].as<int>();
    } else if (!flgs.guiFlag && flagEnabled) {
        // print out error when no character flag is enabled but only length option specified
        std::cout << options.help() << std::endl;
        printErr("Error: no length argument");
        return FAIL;
    }

    // run GUI version if -g option is present
    if (flgs.guiFlag) {
        #if USE_GTK == 1
            state = rungui();
        #else
            printErr("GTK is disabled in this build. Please rebuild package with USE_GTK flag in cmake");
            state = FAIL;
        #endif
    } else if (length > 0 && flagEnabled){
        // otherwise run CUI version
        state = runcui(length, flgs);
    } else {
        // if no argument specified, report error and set execution state 1 (failure)
        std::cout << options.help() << std::endl;
        printErr("Error: No argument specified");
        state = FAIL;
    }
    return state;
}
