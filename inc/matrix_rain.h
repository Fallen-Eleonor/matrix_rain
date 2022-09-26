#ifndef MATRIX_RAIN
#define MATRIX_RAIN

#include <ncurses.h>
#include <unistd.h>

#include "s_matrix.h"

#define ERR_USAGE ("usage: ./matrix_rain")

void print_matrix(t_matrix matrix);
void mx_printerr(const char *s);
int mx_strlen(const char *s);
void mx_printstr(const char *s);

#endif  // !MATRIX_RAIN
