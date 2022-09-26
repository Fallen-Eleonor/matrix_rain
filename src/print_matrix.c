#include "matrix_rain.h"

void print_matrix(t_matrix matrix) {
    if (has_colors()) {
        if (start_color() == OK) {
            init_pair(1, COLOR_GREEN, COLOR_BLACK);
            init_pair(2, COLOR_WHITE, COLOR_BLACK);
            for (int i = 0; i < matrix.n; i++) {
                for (int j = 0; j < matrix.m; j++) {
                    if (matrix.arr[i][j].is_head == true) {
                        attrset(COLOR_PAIR(2));
                        printw("%c", matrix.arr[i][j].c);
                        attroff(COLOR_PAIR(2));
                        continue;
                    }
                    attrset(COLOR_PAIR(1));
                    printw("%c", matrix.arr[i][j].c);
                    attroff(COLOR_PAIR(1));
                }
                printw("\n");
            }
        }
    }
}
