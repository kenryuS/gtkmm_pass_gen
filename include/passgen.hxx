#ifndef PASSGEN_HXX
#define PASSGEN_HXX

#include <cstdlib>
#include <ctime>
#include <exception>

namespace PassGen {
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
    auto passGen(const char *charList, const unsigned int& len) -> char*;

    // exceptions for the functions in PassGen namespace
    namespace exceptions {
        // base exception class
        class exception : public std::exception {
            public:
                // constructor (sets m_message from msg argument)
                explicit exception(char* msg) {m_message = msg;};
                /**
                * @brief show the content of the error message
                * @return (char*) pure C string of error message
                */
                auto what() -> char* {return m_message;};
            private:
                char* m_message = nullptr; // error message (init with nullptr)
        };

        // exception to be thrown when something is failed to allocate its memory
        class memoryAllocationFailiure : public exception {
            public:
                explicit memoryAllocationFailiure() : exception((char*)"Couldn't allocate memory space!") {};
                // call construct from the base class supplied with specified error message
        };

        // exception to be thrown when there is no content in charList (PassGen::passgen())
        class noCharList : public exception {
            public:
                explicit noCharList() : exception((char*)"No character list specified!") {};
                // call construct from the base class supplied with specified error message
        };

        // exception to be used when unknown error occured
        class unknownError : public exception {
            public:
                explicit unknownError() : exception((char*)"Unknown Error Caught : Mark me 0 :(") {};
                // call construct from the base class supplied with specified error message
        };
    } // PassGen::exceptions
} // PassGen

#endif // PASSGEN_HXX
