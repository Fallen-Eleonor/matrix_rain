#include "matrix_rain.h"

static void wake_up() {
   char *print_mat_words[4] = {"Wake up , Neo..", "The Matrix has you.." , 
                              "Follow the white rabbit", "Knock, knock, Neo" };
    for (int i=0; i<mx_strlen(print_mat_words[i]); i++) {
    for (int j = 0; j < mx_strlen(print_mat_words[i]); j++)
        {
            attron(COLOR_PAIR(1));
            mvaddch(1, j + 4, print_mat_words[i][j]);
            
            attroff(COLOR_PAIR(1));
            usleep(10000);
        }
    }
    // clear(); 
}

int main(int args, char *argv[]) {
    argv++;
    if (args != 1) {
        mx_printerr(ERR_USAGE);
        exit(0);
    }
    time_t t;
    srand((unsigned)time(&t));
    initscr();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    int n = LINES;
    int m = COLS - 1;
    t_matrix matrix = create_matrix(n, m);
    bool need_to_stop = false;
    nodelay(stdscr, true);
    noecho();
    while (!need_to_stop) {
        clear();
               wake_up(); 
        update_matrix(matrix);
        print_matrix(matrix);
        if (getch() == 'q') {
            need_to_stop = true;
            continue;
        }
        usleep(100000);
        refresh();
    }
    free_matrix(&matrix);
    endwin();
}

