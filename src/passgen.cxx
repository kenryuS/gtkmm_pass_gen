#include <stdio.h>
#include <stdlib.h>

#include <passgen.hxx>

using namespace PassGen;

char* PassGen::getLowerAlpha() {
    char* output = malloc(26+1) // 26 letters + 1 terminating char
    int offset = 97; // 65th letter in ASCII (a)
    for (int i = 0; i < 26; i++) {
        output[i] = offset + i;
    }
    output[26] = '\0'; // terminating char
    return output;
}

char* PassGen::getUpperAlpha() {
    char* output = malloc(26+1) // 26 letters + 1 terminating char
    int offset = 65; // 65th letter in ASCII (a)
    for (int i = 0; i < 26; i++) {
        output[i] = offset + i;
    }
    output[26] = '\0'; // terminating char
    return output;
}

