#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <passgen.hxx>
using namespace PassGen;


void printhelp() {
    printf("APCSPCreateTaks - Random Password Generator\n\n");
    printf("\t[Arguments]:\n\n");
    printf("\t-A : include upper case alphabets in password\n\n");
    printf("\t-a : include lower case alphabets in password\n\n");
    printf("\t-n : include numbers in password\n\n");
    printf("\t-s : include special characters in password\n\n");
}

int main(int argc, char** argv) {
    // flags for program arguments
    bool upAlphaFlag = false;
    bool lowAlphaFlag = false;
    bool numFlag = false;
    bool specialCharFlag = false;
    int length = -1;
    int arg;

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
                break;
            case '?':
                if (optopt == 'l') {
                    printf("Error: no length specified");
                }
                return 1;
            default:
                abort();
        }
    }

    std::cout << "A: " << upAlphaFlag << " a: " << lowAlphaFlag << " n: " << numFlag << " s: " << specialCharFlag << std::endl;
    if (upAlphaFlag == true) {std::cout << getUpperAlpha() << std::endl;}
    if (lowAlphaFlag == true) {std::cout << getLowerAlpha() << std::endl;}
    if (numFlag == true) {std::cout << getNumber() << std::endl;}

    char* out = passGen(getUpperAlpha(), 12);
    std::cout << out << std::endl;

    return 0;
}
