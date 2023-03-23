#include <stdio.h>
#include <stdlib.h>
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
            case '?':
                if (optopt == 'l') {
                    printf("Error: No length specified\n");
                } else if (isprint(optopt)){
                    printf("Error: Unknown option: -%c\n", optopt);
                } else {
                    printf("Error: Unknown value: -%c\n", optopt);
                }
                return 1;
            default:
                printhelp();
                abort();
        }
    }

    state = runcui(length, upAlphaFlag, lowAlphaFlag, numFlag, specialCharFlag);
    return state;
}
