#ifndef PASSGEN
#define PASSGEN

#include <stdlib.h>
#include <stdio.h>

namespace PassGen {
    char* getUpperAlpha();
    char* getLowerAlpha();
    char* getNumber();
    char* getSpecialChars();
    char* passGen(char* charList, int len);
}

#endif // PASSGEN
