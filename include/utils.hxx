#ifndef UTILS_HXX
#define UTILS_HXX

#include <iostream>
#include <main.hxx>
#include <config.h>

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
template<typename T>
inline auto printLine(T object) -> void {
    std::cout << object << std::endl;
}

/**
* @brief print the passed in argument as cerr
* @param object takes any type of input that is able to stdout to the console
* @return (void) - console output of the object
*/
template<typename T>
inline auto printErr(T object) -> void {
    std::cerr << object << std::endl;
}

/**
 * @brief print cmake build flags used in the build
 * @return (void) - console output of each value
 **/
inline auto printBuildOpt() -> void {
    printLine("Build Options Specified in CMake build:");
    std::cout << "USE_GTK: " << (bool)IS_USING_GTK << std::endl;
}

/**
* @brief checks if any flag is enabled
* @param upper boolean flag for upper case letters
* @param lower boolean flag for lower case letters
* @param num boolean flag for numbers
* @param special boolean flag for special characters
* @return (bool) - returns true if one of any flag is enabled
*/
inline auto checkFlags(flags flg) -> bool {
    bool isEnabled = (flg.upAlphaFlag || flg.lowAlphaFlag || flg.numFlag || flg.specialCharFlag);
    return isEnabled;
}

#endif // UTILS_HXX
