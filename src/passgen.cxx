#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <utils.hxx>
#include <passgen.hxx>

// getSpecialChars - get the lower case alphabets
// void : takes nothing
// return (char*) : the string with all lower case alphabets in standard ASCII
char* PassGen::getLowerAlpha() {
    char* output = new char[26]; // 26 letters
    if (output == NULL) {return 0;} // check if memory allocation is failed
    int offset = 97; // 97th letter in ASCII (a)
    for (int i = 0; i < 26; i++) {
        output[i] = offset + i;
    }
    return output;
}

// getUpperAlpha - get the upper case alphabets
// void : takes nothing
// return (char*) : the string with all upper case alphabets in standard ASCII
char* PassGen::getUpperAlpha() {
    char* output = new char[26]; // 26 letters
    if (output == NULL) {return 0;} // check if memory allocation is failed
    int offset = 65; // 65th letter in ASCII (A)
    for (int i = 0; i < 26; i++) {
        output[i] = offset + i;
    }
    return output;
}

// getSpecialChars - get the numbers
// void : takes nothing
// return (char*) : the string with all numbers in standard ASCII
char* PassGen::getNumber() {
    char* output = new char[10]; // 10 letters
    if (output == NULL) {return 0;} // check if memory allocation is failed
    int offset = 48; // 48th letter in ASCII (0)
    for (int i = 0; i < 10; i++) {
        output[i] = offset + i;
    }
    return output;

}

// getSpecialChars - get the special characters
// void : takes nothing
// return (char*) : the string with all special characters in standard ASCII
char* PassGen::getSpecialChars() {
    char* output = new char[42]; // 42 symbols
    if (output == NULL) {return 0;} // check if memory allocation is failed
    int offset = 33; // 33rd letter in ASCII (!)
    int listOffset = 0;
    int i;
    // ASCII range of 33 - 64 (32 symbols)
    for (i = 0; i < 32; i++) {
        output[i] = offset + i;
    }
    listOffset = 32;
    offset = 91;
    // ASCII range of 91 - 96 (6 symbols)
    for (i = 0; i < 6; i++) {
        output[i + listOffset] = offset + i;
    }
    listOffset = 38;
    offset = 123;
    // ASCII range of 123 - 126 (4 symbols)
    for (i = 0; i < 4; i++) {
        output[i + listOffset] = offset + i;
    }
    return output;
}

// passGen - Password Generator
// charList (char*) : list of char to be used in password generation
// len (int) : length of password
// return (char*) : the generated password
char* PassGen::passGen(char* charList, const int len) {
    std::srand(time(nullptr));
    unsigned int index;
    char* output = new char[len+1]; // length of password + 1 terminating char
    if (output == NULL) {return 0;} // return 0 on the failiure of memory allocation
    for (int i = 0; i <= len; i++) {
        if (i == len) {output[i] = charList[strSize(charList)];}
        else {
        index = std::rand()%(strSize(charList));
        output[i] = charList[index];
        }
    }
    return output;
}
