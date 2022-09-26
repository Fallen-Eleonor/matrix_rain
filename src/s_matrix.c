#include "s_matrix.h"

t_matrix create_matrix(int n, int m) {
    t_matrix new_matrix;
    new_matrix.n = n;
    new_matrix.m = m;

    new_matrix.arr = (t_symbol **)malloc(n * sizeof(t_symbol *));

    for (int i = 0; i < n; i++) {
        new_matrix.arr[i] = (t_symbol *)malloc(m * sizeof(t_symbol));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            new_matrix.arr[i][j] = create_symbol(0);
        }
    }

    return new_matrix;
}

void free_matrix(t_matrix *matrix) {
    for (int i = 0; i < matrix->n; i++) {
        free(matrix->arr[i]);
    }
    free(matrix->arr);
    matrix->arr = NULL;
}

static void spend_symbols_life_time(t_matrix matrix);
static void generate_new_heads(t_matrix matrix);
static void delete_old_heads(t_matrix matrix);
static void generate_new_symbols(t_matrix matrix);
static void generated_done_update(t_matrix matrix);

void update_matrix(t_matrix matrix) {
    spend_symbols_life_time(matrix);
    generate_new_heads(matrix);
    delete_old_heads(matrix);
    generate_new_symbols(matrix);
    generated_done_update(matrix);
}

// Static functions
static void spend_symbols_life_time(t_matrix matrix) {
    for (int i = 1; i < matrix.n; i++) {
        for (int j = 0; j < matrix.m; j++) {
            if (matrix.arr[i][j].current_life > 0) {
                matrix.arr[i][j].current_life--;
            }
            else if (matrix.arr[i][j].current_life <= 0) {
                if (matrix.arr[i][j].c != ' ')
                    matrix.arr[i][j] = create_symbol(0);
            }
        }
    }
}

static void generate_new_heads(t_matrix matrix) {
    for (int j = 0; j < matrix.m; j++) {
        if (matrix.arr[0][j].current_life <= 0)
            if (matrix.arr[0][j].c == ' ') {
                if (rand() % 200 < 6) {
                    matrix.arr[0][j] = create_symbol(matrix.n - 3);
                    matrix.arr[0][j].is_head = true;
                }
            }
            else {
                matrix.arr[0][j] = create_symbol(0);
                matrix.arr[0][j].current_life = 5;
            }

        else {
            matrix.arr[0][j].current_life--;
        }
    }
}

static void delete_old_heads(t_matrix matrix) {
    for (int j = 0; j < matrix.m; j++) {
        matrix.arr[matrix.n - 1][j].is_head = false;
    }
}

static void generate_new_symbols(t_matrix matrix) {
    t_symbol *new_head;

    for (int i = 1; i < matrix.n; i++) {
        for (int j = 0; j < matrix.m; j++) {
            if (matrix.arr[i - 1][j].is_head) {
                if (matrix.arr[i - 1][j].is_generated == false) {
                    matrix.arr[i - 1][j].is_head = false;
                    matrix.arr[i][j] = create_symbol(matrix.n);
                    new_head = &(matrix.arr[i][j]);
                    new_head->is_head = true;
                    new_head->start_life =
                        matrix.arr[i - 1][j].start_life;
                    new_head->current_life = new_head->start_life;
                }
            }
        }
    }
}

static void generated_done_update(t_matrix matrix) {
    for (int i = 0; i < matrix.n; i++) {
        for (int j = 0; j < matrix.m; j++) {
            matrix.arr[i][j].is_generated = false;
        }
    }
}
