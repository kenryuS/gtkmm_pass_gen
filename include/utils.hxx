#ifndef UTILS_HXX
#define UTILS_HXX

#include <iostream>

// strSize - return the size(length) of string (pure C char list)
// str (char*) : string to be measured
// return (int) : size(length) of string
inline int strSize(char* str) {
    int out = 0;
    int index = 0;
    while (str[index] != 0) {
        index++;
        out++;
    }
    return out;
}

// printLine - print the passed in argument
// in (Template<class T>) : takes any type of input
// return (void) : returns nothing, console output
template<class T>
inline void printLine(T in) {
    std::cout << in << std::endl;
}

// printhelp - prints the help for the console application
// void : takes nothing
// return (void) : returns nothing, console output
inline void printhelp() {
    printLine("APCSPCreateTask - Random Password Generator\n");
    printLine("[Usage]: APCSPCreateTask [-A -a -n -s] -l <length>\n");
    printLine("[Arguments]:\n");
    printLine("\t-A : include upper case alphabets in password\n");
    printLine("\t-a : include lower case alphabets in password\n");
    printLine("\t-n : include numbers in password\n");
    printLine("\t-s : include special characters in password\n");
    printLine("\t-l <number> : set the length of the password\n");
    printLine("\t-h : print this help\n");
}

// checkFlags - checks if any flag is enabled
// upper (bool) - flag for upper case letters
// lower (bool) - flag for lower case letters
// num (bool) - flag for numbers
// special (bool) - flag for special characters
// reutnr (bool) - returns true if one of any flag is enabled
inline bool checkFlags(bool upper, bool lower, bool num, bool special) {
    int count = 0;
    if (upper) {count++;}
    if (lower) {count++;}
    if (num) {count++;}
    if (special) {count++;}
    return count > 0;
}

#endif // UTILS_HXX
