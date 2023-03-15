#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <passgen.hxx>
using namespace PassGen;

#define print(x) std::cout << x << std::endl

void printhelp() {
    print("test");
}

int main(int argc, char** argv) {
    // flags for program arguments
    bool upAlphaFlag = false;
    bool lowAlphaFlag = false;
    bool numFlag = false;
    bool specialCharFlag = false;
    int length;
    int arg;

    while ((arg = getopt (argc, argv, "Aansh:")) != -1) {
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
            case 'h':
                printf("Test");
                break;
            case '?':
                print("Other args");
                break;
            default:
                abort();
        }
    }

    std::cout << "A: " << upAlphaFlag << " a: " << lowAlphaFlag << " n: " << numFlag << " s: " << specialCharFlag << std::endl;

    std::cout << getUpperAlpha() << std::endl;
    char* num = getNumber();
    std::cout << num[5] << std::endl;
    std::cout << getSpecialChars() << std::endl;
    return 0;
}
