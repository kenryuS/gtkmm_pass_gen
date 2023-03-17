#ifndef UTILS
#define UTILS

int strSize(char* a) {
    int out = 0;
    int i = 0;
    while (a[i] != 0) {
        i++;
        out++;
    }
    return out;
}

#endif // UTILS
