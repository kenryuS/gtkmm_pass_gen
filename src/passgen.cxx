#include <stdio.h>
#include <stdlib.h>

#include <passgen.hxx>

char* PassGen::getLowerAlpha() {
    char* output = (char*)malloc(26+1); // 26 letters + 1 terminating char
    if (output == NULL) {return 0;} // check if memory allocation is failed
    int offset = 97; // 97th letter in ASCII (a)
    for (int i = 0; i < 26; i++) {
        output[i] = offset + i;
    }
    output[26] = '\0'; // terminating char
    return output;
}

char* PassGen::getUpperAlpha() {
    char* output = (char*)malloc(26+1); // 26 letters + 1 terminating char
    if (output == NULL) {return 0;} // check if memory allocation is failed
    int offset = 65; // 65th letter in ASCII (A)
    for (int i = 0; i < 26; i++) {
        output[i] = offset + i;
    }
    output[26] = '\0';
    return output;
}

char* PassGen::getNumber() {
    char* output = (char*)malloc(10+1); // 10 letters + 1 terminating char
    if (output == NULL) {return 0;} // check if memory allocation is failed
    int offset = 48; // 48th letter in ASCII (0)
    for (int i = 0; i < 10; i++) {
        output[i] = offset + i;
    }
    output[10] = '\0';
    return output;

}

char* PassGen::getSpecialChars() {
    char* output = (char*)malloc(42+1); // 42 symbols + 1 terminating char
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
    output[42] = '\0';
    return output;
}
