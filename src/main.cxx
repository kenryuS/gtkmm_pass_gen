#include <iostream>
#include <unistd.h>
#include <string>
#include <utils.hxx>
#include <ui.hxx>

int main(int argc, char** argv) {
    // flags for program arguments
    bool upAlphaFlag = false;
    bool lowAlphaFlag = false;
    bool numFlag = false;
    bool specialCharFlag = false;
    int length = -1;
    int arg;
    int state = 0;

    // sets flags accordingly to the program arguments
    while ((arg = getopt (argc, argv, "Aanshl:")) != -1) {
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
            case 'l':
                length = std::atoi(optarg);
                break;
            case 'h':
                printhelp();
                return 0;
            case '?': // error handeling
                if (optopt == 'l') {
                    printLine("Error: No length specified");
                } else {
                    printhelp();
                    std::cout << "Error: Unknown Option: " << optopt << std::endl;
                }
                return 1;
            default:
                abort();
        }
    }

    // run GUI version if no argument is setted
    if (length < 0 && !(checkFlags(upAlphaFlag, lowAlphaFlag, numFlag, specialCharFlag))) {
        state = rungui(argc, argv);
    } else { // otherwise run CUI version
        state = runcui(length, upAlphaFlag, lowAlphaFlag, numFlag, specialCharFlag);
    }
    return state;
}
