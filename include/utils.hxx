#ifndef UTILS_HXX
#define UTILS_HXX

#include <iostream>

/**
* @brief return the size(length) of string (pure C char list)
* @param str pure C string to be measured
* @return (int) - size(length) of string
*/
inline auto strSize(const char *str) -> int {
    int out = 0;
    int index = 0;
    while (str[index] != 0) {
        index++;
        out++;
    }
    return out;
}

/**
* @brief print the passed in argument
* @param object takes any type of input that is printable
* @return (void) - console output the object
*/
template<class T>
inline auto printLine(T object) -> void {
    std::cout << object << std::endl;
}

/**
* @brief prints the help for the console application
* @return (void) - console output of help document
*/
inline auto printhelp() -> void {
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

/**
* @brief checks if any flag is enabled
* @param upper boolean flag for upper case letters
* @param lower boolean flag for lower case letters
* @param num boolean flag for numbers
* @param special boolean flag for special characters
* @return (bool) - returns true if one of any flag is enabled
*/
inline auto checkFlags(bool upper, bool lower, bool num, bool special) -> bool {
    int count = 0;
    if (upper) {count++;}
    if (lower) {count++;}
    if (num) {count++;}
    if (special) {count++;}
    return count > 0;
}

#endif // UTILS_HXX
