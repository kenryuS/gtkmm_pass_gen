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
* @param object takes any type of input that is able to stdout to the console
* @return (void) - console output of the object
*/
template<class T>
inline auto printLine(T object) -> void {
    std::cout << object << std::endl;
}

/**
* @brief prints the help for the console application
* @return (void) - console output of help document
*/
inline auto printHelp() -> void {
    printLine("APCSPCreateTask - Random Password Generator\n");
    printLine("[Usage]: APCSPCreateTask [-A -a -n -s -g] -l <length>\n");
    printLine("[Options]:\n");
    printLine("\t-A, --upper : include upper case alphabets in password\n");
    printLine("\t-a, --lower : include lower case alphabets in password\n");
    printLine("\t-n, --number : include numbers in password\n");
    printLine("\t-s, --special  : include special characters in password\n");
    printLine("\t-l, --length <number> : set the length of the password\n");
    printLine("\t-g, --gui : run in GUI regardless of the previous options\n");
    printLine("\t-h, --help : print this help\n");
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
    bool isEnabled = (upper || lower || num || special);
    return isEnabled;
}

#endif // UTILS_HXX
