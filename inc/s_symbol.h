#ifndef SYMBOL
#define SYMBOL

#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

typedef struct s_symbol {
    char c;
    bool is_head;
    bool is_generated;
    int start_life;
    int current_life;
} t_symbol;

t_symbol create_symbol(int max_life_time);
#endif  // !SYMBOL
