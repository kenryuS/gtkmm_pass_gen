#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <cstring>
#include <passgen.hxx>
using namespace PassGen;


void printhelp() {
    printf("APCSPCreateTask - Random Password Generator\n\n");
    printf("[Usage]: APCSPCreateTask [-A -a -n -s] -l <length>\n\n");
    printf("[Arguments]:\n\n");
    printf("\t-A : include upper case alphabets in password\n\n");
    printf("\t-a : include lower case alphabets in password\n\n");
    printf("\t-n : include numbers in password\n\n");
    printf("\t-s : include special characters in password\n\n");
    printf("\t-l <number> : set the length of the password\n\n");
    printf("\t-h : print this help\n\n");
}

bool checkFlags(bool up, bool low, bool num, bool spec) {
    int count = 0;
    if (up == true) {count++;}
    if (low == true) {count++;}
    if (num == true) {count++;}
    if (spec == true) {count++;}
    return count > 0 ? true : false;
}

int main(int argc, char** argv) {
    // flags for program arguments
    bool upAlphaFlag = false;
    bool lowAlphaFlag = false;
    bool numFlag = false;
    bool specialCharFlag = false;
    int length = -1;
    int arg;

    std::string input;

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

    if (length < 0 && checkFlags(upAlphaFlag, lowAlphaFlag, numFlag, specialCharFlag) == false) {
        printhelp();
        printf("\nError: No option specified\n");
        return 1;
    } 

    if (length < 0) {
        printhelp();
        printf("\nError: Length not specified\n");
        return 1;
    }

    if (checkFlags(upAlphaFlag, lowAlphaFlag, numFlag, specialCharFlag) == false) {
        printhelp();
        printf("\nError: No character flag(s) specified\n");
        return 1;
    }

    if (upAlphaFlag == true) {input += getUpperAlpha();}
    if (lowAlphaFlag == true) {input += getLowerAlpha();}
    if (numFlag == true) {input += getNumber();}
    if (specialCharFlag == true) {input += getSpecialChars();}

    char *cInput = new char[input.length() + 1];
    strcpy(cInput, input.c_str());
    char *out = passGen(cInput, length);
    std::cout << out << std::endl;

    return 0;
}
