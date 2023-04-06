#include <utils.hxx>
#include <passgen.hxx>

auto PassGen::getLowerAlpha() -> char* {
    const int numOfLetters = 26; // 26 letters
    char* output = nullptr; // initialize pointer
    output = (char*)malloc(numOfLetters * sizeof(char) + 1); // allocate memory for 26 letters and a terminate character
    if (output == nullptr) {throw PassGen::exceptions::memoryAllocationFailiure(); return nullptr;} // check if memory allocation is failed
    const int offset = 97; // 97th letter in ASCII (a)
    // adds 26 letters (a-z)
    for (int i = 0; i < numOfLetters; i++) {
        output[i] = (char)(offset + i);
    }
    output[numOfLetters] = '\0'; // add terminate character at end
    return output;
}

auto PassGen::getUpperAlpha() -> char* {
    const int numOfLetters = 26; // 26 letters
    char* output = nullptr; // initialize pointer
    output = (char*)malloc(numOfLetters * sizeof(char) + 1); // allocate memory for 26 letters + terminate character
    if (output == nullptr) {throw PassGen::exceptions::memoryAllocationFailiure(); return nullptr;} // check if memory allocation is failed
    const int offset = 65; // 65th letter in ASCII (A)
    // adds 26 letters (A-Z)
    for (int i = 0; i < numOfLetters; i++) {
        output[i] = (char)(offset + i);
    }
    output[numOfLetters] = '\0'; // add terminate character at end
    return output;
}

auto PassGen::getNumber() -> char* {
    const int numOfLetters = 10; // 10 letters
    char* output = nullptr; // initialize pointer
    output = (char*)malloc((numOfLetters) * sizeof(char) + 1);
    if (output == nullptr) {throw PassGen::exceptions::memoryAllocationFailiure(); return nullptr;} // check if memory allocation is failed
    const int offset = 48; // 48th letter in ASCII (0)
    // adds 10 letters (0-9)
    for (int i = 0; i < numOfLetters; i++) {
        output[i] = (char)(offset + i);
    }
    output[numOfLetters] = '\0'; // add terminate character at end
    return output;

}

auto PassGen::getSpecialChars() -> char* {
    const int numOfLetters = 31; // 31 symbols
    char* output = nullptr; // initialize pointer
    output = (char*)malloc((numOfLetters) * sizeof(char) + 1);
    if (output == nullptr) {throw PassGen::exceptions::memoryAllocationFailiure(); return nullptr;} // check if memory allocation is failed
    int ind = 0;
    // loop config and range exclusion config
    const int start = 33;
    const int end = 127;
    const int numStart = 48;
    const int numEnd = 57;
    const int upperStart = 65;
    const int upperEnd = 90;
    const int lowerStart = 97;
    const int lowerEnd = 122;
    // adds special characters to output
    for (int i = start; i < end; i++) {
        if ((numStart <= i && i <= numEnd) || (upperStart <= i && i <= upperEnd) || (lowerStart <= i && i <= lowerEnd)) {
            continue; // skip at the number, upper case and lower case alphabets
        }
        output[ind] = (char)(i);
        ind++;
    }
    output[numOfLetters] = '\0'; // add terminate character at end
    return output;
}

auto PassGen::passGen(const char *charList, const unsigned int& len) -> char* {
    if (strSize(charList) == 0) {throw PassGen::exceptions::noCharList(); return nullptr;}

    std::srand(time(nullptr)); // set random seed to current time

    unsigned int randomCharPos = 0; // position of charList which will be randomly selected
    const char termChar = '\0';
    const char backSlash = '\\';
    const int charListSize = strSize(charList);
    char currentLetter = 0;
    char previousLetter = 0;

    char* output = new char[len+1]; // length of password + 1 terminating char
    // return null pointer on the failiure of memory allocation
    if (output == nullptr) {throw PassGen::exceptions::memoryAllocationFailiure(); return nullptr;}

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
        ((currentLetter == 'a') || // '\a'
        (currentLetter == 'b') || // '\b'
        (currentLetter == 'c') || // '\c'
        (currentLetter == 'n') || // '\n'
        (currentLetter == 'f') || // '\f'
        (currentLetter == 'r') || // '\r'
        (currentLetter == 't') || // '\t'
        (currentLetter == 'U') || // '\U'
        (currentLetter == 'u') || // '\u'
        (currentLetter == 'v') || // '\v'
        (currentLetter == 'x') // '\x'
        )) {
            // regenerate random letter
            randomCharPos = std::rand()%charListSize;
            output[i] = charList[randomCharPos];

            // re-set current letter
            currentLetter = output[i];
        }}
    }}
    return output;
}
