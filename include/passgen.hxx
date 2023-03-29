#ifndef PASSGEN
#define PASSGEN

namespace PassGen {
    // declare functions (not defined yet)
    /**
     * @brief Get the list of upper alphabet letters
     * @return char* - List of upper alphabet letters
     */
    auto getUpperAlpha() -> char*;
    /**
     * @brief Get the list of lower alphabet letters
     * @return char* - List of lower alphabet letters
     */
    auto getLowerAlpha() -> char*;
    /**
     * @brief Get the list of numbers
     * @return char* - List of numbers
     */
    auto getNumber() -> char*;
    /**
     * @brief Get the list of special characters
     * @return char* - List of special characters
     */
    auto getSpecialChars() -> char*;
    /**
     * @brief generate the password from list of characters and specified length
     * @param charList list of characters (pure C string)
     * @param len length of password to be generated (int)
     * @return (char*) - generated password
     */
    auto passGen(const char *charList, int len) -> char*;
}

#endif // PASSGEN
