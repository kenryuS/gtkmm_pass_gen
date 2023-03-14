#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include <passgen.hxx>
using namespace PassGen;

int main(int argc, char** argv) {
    std::cout << getUpperAlpha() << std::endl;
    char* num = getNumber();
    std::cout << num[5] << std::endl;
    return 0;
}
