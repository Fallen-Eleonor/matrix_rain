#ifndef MATRIX
#define MATRIX

#include <ncurses.h>
#include <stdbool.h>
#include <unistd.h>

#include "s_symbol.h"

typedef struct s_matrix {
    int n, m;
    t_symbol **arr;
} t_matrix;

t_matrix create_matrix(int n, int m);

void update_matrix(t_matrix matrix);

void free_matrix(t_matrix *matrix);

#endif  // !MATRIX
