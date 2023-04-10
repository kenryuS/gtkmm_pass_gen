#include <cxxopts.hpp> // command line argument parser library written by jarro2783 (https://github.com/jarro2783/cxxopts)
#include <ui.hxx>

auto main(int argc, char** argv) -> int{
    // flags for program arguments
    bool upAlphaFlag = false;
    bool lowAlphaFlag = false;
    bool numFlag = false;
    bool specialCharFlag = false;
    bool guiFlag = false;

    // other variable change by the flags
    unsigned int length = 0;
    int state = -1; // execution state (-1 for init value)
    bool flagEnabled = false;

    // specifies options
    cxxopts::Options options("APCSP Create Task", "Random Password Generator");
    options.add_options()
        ("A,upper", "Include upper case alphabets")
        ("a,lower", "Include lower case alphabets")
        ("n,number","Include numbers")
        ("s,special", "Include special characters")
        ("g,gui", "Run the GUI version of program, other passed arguments are ignored")
        ("h,help", "Print help")
        ("l,length", "Set the length of password", cxxopts::value<int>())
    ;

    // parse options from argv with fail safe
    cxxopts::ParseResult result;
    try {
        result = options.parse(argc, argv);
    } catch (const cxxopts::exceptions::parsing &e) {
        printHelp();
        std::cerr << e.what() << "\n"; // show error
        return FAIL;
    }

    // sets flags and option value from options(argc and argv)
    // help flag (show help doc and exit)
    if (result.count("help")) {
        printHelp();
        return SUCCESS;
    }

    // GUI flag
    if (result.count("gui")) guiFlag = true;

    // char flags
    if (result.count("upper")) upAlphaFlag = true;
    if (result.count("lower")) lowAlphaFlag = true;
    if (result.count("number")) numFlag = true;
    if (result.count("special")) specialCharFlag = true;
    flagEnabled = checkFlags(upAlphaFlag, lowAlphaFlag, numFlag, specialCharFlag);

    // length option
    if (result.count("length") && !guiFlag && flagEnabled) {
        length = result["length"].as<int>();
    } else if (!guiFlag && flagEnabled) { // print out error when no character flag is enabled but only length option specified
        printHelp();
        printLine("Error: no length argument");
        return FAIL;
    }

    // run GUI version if -g option is present
    if (guiFlag) {
        state = rungui();
    } else if (length > 0 && flagEnabled){ // otherwise run CUI version
        state = runcui(length, upAlphaFlag, lowAlphaFlag, numFlag, specialCharFlag);
    } else { // if no argument specified, report error and set execution state 1 (failure)
        printHelp();
        printLine("Error: No argument specified");
        state = FAIL;
    }
    return state;
}
