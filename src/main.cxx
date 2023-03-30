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
    int arg = -1;
    int state = 0; // execution state (0 for success)

    cxxopts::Options options("APCSP_Create_Task", "options for program");
    options.add_options()
        ("A,upper", "Include upper case alphabets")
        ("a,lower", "Include lower case alphabets")
        ("n,number","Include numbers")
        ("s,special", "Include special characters")
        ("g,gui", "Run the GUI version of program, other passed arguments are ignored")
        ("h,help", "Print help")
        ("l,length", "Set the length of password", cxxopts::value<int>())
    ;

    cxxopts::ParseResult result = options.parse(argc, argv);

    if (result.count("help")) {
        printHelp();
        return 0;
    }
    if (result.count("upper")) upAlphaFlag = true;
    if (result.count("lower")) lowAlphaFlag = true;
    if (result.count("number")) numFlag = true;
    if (result.count("special")) specialCharFlag = true;
    if (result.count("gui")) guiFlag = true;
    if (result.count("length") && !guiFlag) {
        try {
            length = result["length"].as<int>();
        } catch (const cxxopts::exceptions::exception &x) {
            printHelp();
            std::cerr << x.what();
            return 1;
        }
    } else if (!guiFlag) {
        printHelp();
        printLine("Error: no length argument");
    }

    // run GUI version if -g option is present
    if (guiFlag) {
        state = rungui(argc, argv);
    } else if (length >= 0 && checkFlags(upAlphaFlag, lowAlphaFlag, numFlag, specialCharFlag)){ // otherwise run CUI version
        state = runcui(length, upAlphaFlag, lowAlphaFlag, numFlag, specialCharFlag);
    } else { // if no argument specified, report error and set execution state 1 (failure)
        printHelp();
        printLine("Error: No argument specified");
        state = 1;
    }
    return state;
}
