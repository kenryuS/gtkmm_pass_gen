#include <cstdlib>
#include <ctime>

#include <utils.hxx>
#include <passgen.hxx>

// getSpecialChars - get the lower case alphabets
// void : takes nothing
// return (char*) : the string with all lower case alphabets in standard ASCII
char* PassGen::getLowerAlpha() {
    char* output = new char[26]; // 26 letters
    if (output == nullptr) {return nullptr;} // check if memory allocation is failed
    int offset = 97; // 97th letter in ASCII (a)
    // adds 26 letters (a-z)
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
    if (output == nullptr) {return nullptr;} // check if memory allocation is failed
    int offset = 65; // 65th letter in ASCII (A)
    // adds 26 letters (A-Z)
    for (int i = 0; i < 26; i++) {
        output[i] = offset + i;
    }
    return output;
}

// getNumber - get the numbers
// void : takes nothing
// return (char*) : the string with all numbers in standard ASCII
char* PassGen::getNumber() {
    char* output = new char[10]; // 10 letters
    if (output == nullptr) {return nullptr;} // check if memory allocation is failed
    int offset = 48; // 48th letter in ASCII (0)
    // adds 10 letters (0-9)
    for (int i = 0; i < 10; i++) {
        output[i] = offset + i;
    }
    return output;

}

// getSpecialChars - get the special characters
// void : takes nothing
// return (char*) : the string with all special characters in standard ASCII
char* PassGen::getSpecialChars() {
    char* output = new char[31]; // 31 symbols
    if (output == nullptr) {return nullptr;} // check if memory allocation is failed
    int ind = 0;
    // adds special characters to output
    for (int i = 33; i < 127; i++) {
        if ((48 <= i && i <= 57) || (65 <= i && i <= 90) || (97 <= i && i <= 122)) {
            continue; // skip at the number, upper case and lower case alphabets
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
    if (strSize(charList) == 0) {return nullptr;}
    std::srand(time(nullptr));
    unsigned int randomCharPos; // position of charList which will be randomly selected
    const char termChar = '\0';
    const char backSlash = '\\';
    const int charListSize = strSize(charList);
    char currentLetter = 0;
    char previousLetter = 0;
    char* output = new char[len+1]; // length of password + 1 terminating char
    if (output == nullptr) {return nullptr;} // return 0 on the failiure of memory allocation
    while (strSize(output) != len) { // to make sure output is in desired length
    for (int i = 0; i <= len; i++) {
        if (i == len) {output[i] = termChar;} // ends with terminating char
        else { // adds other chars otherwise
        // adds random character from charList
        randomCharPos = std::rand()%charListSize;
        output[i] = charList[randomCharPos];
        // set current and previous letter for check
        currentLetter = output[i];
        previousLetter = output[i-1];
        // checks escape sequences which causes issues
        while (previousLetter == backSlash &&
            ((currentLetter == 'n') ||
            (currentLetter == 'a') ||
            (currentLetter == 'b') ||
            (currentLetter == 'r') ||
            (currentLetter == 't') ||
            (currentLetter == 'v') ||
            (currentLetter == 'f') ||
            (currentLetter == 'u') ||
            (currentLetter == 'U') ||
            (currentLetter == 'x') ||
            (currentLetter == 'c'))) {
                // regenerate random letter
                randomCharPos = std::rand()%charListSize;
                output[i] = charList[randomCharPos];
                // re-set current letter
                currentLetter = output[i];
            }
        }
    }
    }
    return output;
}
