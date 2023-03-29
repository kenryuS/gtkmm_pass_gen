#include <unistd.h>
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

    // sets flags accordingly to the program arguments
    while ((arg = getopt (argc, argv, "Aanshgl:")) != -1) {
        switch (arg) {
            case 'A':
                upAlphaFlag = true;
                break;
            case 'a':
                lowAlphaFlag = true;
                break;
            case 'n':
                numFlag = true;
                break;
            case 's':
                specialCharFlag = true;
                break;
            case 'g':
                guiFlag = true;
                break;
            case 'l':
                length = std::atoi(optarg);
                break;
            case 'h':
                printHelp();
                return 0;
            case '?': // error handeling
                if (optopt == 'l') {
                    printLine("Error: No length specified");
                } else {
                    printHelp();
                    std::cout << "Error: Unknown Option: -" << (char)optopt << std::endl;
                }
                return 1;
            default:
                abort();
        }
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
