#ifndef UTILS
#define UTILS

#include <stdlib.h>

inline int strSize(char* a) {
    int out = 0;
    int i = 0;
    while (a[i] != 0) {
        i++;
        out++;
    }
    return out;
}

inline void printhelp() {
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

inline bool checkFlags(bool up, bool low, bool num, bool spec) {
    int count = 0;
    if (up == true) {count++;}
    if (low == true) {count++;}
    if (num == true) {count++;}
    if (spec == true) {count++;}
    return count > 0 ? true : false;
}

#endif // UTILS
