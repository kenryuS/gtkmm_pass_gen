#include <cxxopts.hpp> // command line argument parser library written by jarro2783 (https://github.com/jarro2783/cxxopts)
#include <main.hxx>
#include <ui.hxx>
#include <utils.hxx>

auto main(int argc, char** argv) -> int{
    // flags for program arguments
    flags* flgs = nullptr;
    flgs = new flags;
    if (flgs == nullptr) {
        printErr("Error: Memory Allocation Failure");
        return FAIL;
    }

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
        #if USE_GTK == 1
        ("g,gui", "Run the GUI version of program, other passed arguments are ignored")
        #endif // USE_GTK == 1
        #if USE_NCURSES == 1
        ("t,tui", "Run the TUI version of program, other passed arguments are ignored")
        #endif // USE_NCURSES == 1
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

    if (result.arguments().empty()) {
        std::cout << options.help() << std::endl;
        printErr("Error: No arguments specified");
        return FAIL;
    }

    // sets flags and option value from options(argc and argv)
    // help flag (show help doc and exit)
    if ((bool)result.count("help")) {
        std::cout << options.help() << std::endl;
        return SUCCESS;
    }

    // build option information
    if ((bool)result.count("build-info")) {
        printBuildOpt();
        return SUCCESS;
    }

    // GUI flag
    #if USE_GTK == 1
    flgs->guiFlag = (bool)result.count("gui");
    #endif // USE_GTK == 1

    // TUI flag
    #if USE_NCURSES == 1
    flgs->tuiFlag = (bool)result.count("tui");
    #endif

    // char flags
    flgs->upAlphaFlag = (bool)result.count("upper");
    flgs->lowAlphaFlag = (bool)result.count("lower");
    flgs->numFlag = (bool)result.count("number");
    flgs->specialCharFlag = (bool)result.count("special");
    flagEnabled = checkFlags(*flgs);

    // length option
    if ((bool)result.count("length") && !flgs->guiFlag && flagEnabled) {
        length = result["length"].as<int>();
    } else if (!flgs->guiFlag && flagEnabled) {
        // print out error when no character flag is enabled but only length option specified
        std::cout << options.help() << std::endl;
        printErr("Error: no length argument");
        return FAIL;
    }

    // check if both flags are enabled
    if (flgs->guiFlag && flgs->tuiFlag) {
        printErr("You cannot use GUI flag and TUI flag together");
        state = FAIL;
    }
    // run GUI version if -g option is present
    else if (flgs->guiFlag) {
        #if USE_GTK == 1
            state = rungui();
        #else
            printErr("GTK is disabled in this build. Please rebuild package with USE_GTK flag in cmake");
            state = FAIL;
        #endif
    } else if (flgs->tuiFlag) {
        // run TUI version if -t option is present
        #if USE_NCURSES == 1
            state = runtui();
        #else
            printErr("Ncurses is disabled in this build. Please rebuild package with USE_NCURSES flag in cmake");
            state = FAIL;
        #endif
    } else if (length > 0 && flagEnabled){
        // otherwise run CUI version
        state = runcui(length, *flgs);
    } else {
        // if no argument specified, report error and set execution state 1 (failure)
        std::cout << options.help() << std::endl;
        printErr("Error: No argument specified");
        state = FAIL;
    }
    return state;
}
