#include "matrix_rain.h"

int mx_strlen(const char *s) {
    int lenth = 0;
    while (*(s++)) {
        lenth++;
    }
    return lenth;
}

void mx_printerr(const char *s) {
    write(2, s, mx_strlen(s));
    write(2, "\n", 1);
}

void mx_printstr(const char *s) {
	write(1, s, mx_strlen(s));
}

