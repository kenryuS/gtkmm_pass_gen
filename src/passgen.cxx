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
    char* output = new char[14+7+6+4]; // 31 symbols
    if (output == NULL) {return 0;} // check if memory allocation is failed
    int ind = 0;
    for (int i = 33; i < 127; i++) {
        if ((i >= 48 && i <= 57) || (i >= 65 && i <= 90) || (i >= 97 && i <= 122)) {
            continue;
        }
        output[ind] = i;
        ind++;
    }
    return output;
}

// passGen - Password Generator
// charList (char*) : list of char to be used in password generation
// len (int) : length of password
// return (char*) : the generated password
char* PassGen::passGen(char *charList, const int len) {
    std::srand(time(nullptr));
    unsigned int index;
    const char termChar = '\0';
    const char backSlash = '\\';
    char* output = new char[len+1]; // length of password + 1 terminating char
    if (output == NULL) {return 0;} // return 0 on the failiure of memory allocation
    while (strSize(output) != len) {
    for (int i = 0; i <= len; i++) {
        if (i == len) {output[i] = termChar;}
        else {
        index = std::rand()%(strSize(charList));
        output[i] = charList[index];
        char currentLetter = output[i];
        char previousLetter = output[i-1];
        // checks escape sequences which causes issues
        while (
            (previousLetter == backSlash && currentLetter == 'n') ||
            (previousLetter == backSlash && currentLetter == 'a') ||
            (previousLetter == backSlash && currentLetter == 'b') ||
            (previousLetter == backSlash && currentLetter == 'r') ||
            (previousLetter == backSlash && currentLetter == 't') ||
            (previousLetter == backSlash && currentLetter == 'v') ||
            (previousLetter == backSlash && currentLetter == 'f') ||
            (previousLetter == backSlash && currentLetter == 'u') ||
            (previousLetter == backSlash && currentLetter == 'U') ||
            (previousLetter == backSlash && currentLetter == 'x') ||
            (previousLetter == backSlash && currentLetter == 'c')) {
                printf("ESC warn: %c\n", currentLetter);
                index = std::rand()%(strSize(charList));
                output[i] = charList[index];
                currentLetter = output[i];
            }
        }
    }
    }
    return output;
}
