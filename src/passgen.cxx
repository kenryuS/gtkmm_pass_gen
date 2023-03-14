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
    output[26] = '\0'; // terminating char
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
