
#include "s_symbol.h"

t_symbol create_symbol(int max_life_time) {
    t_symbol new_symbol;
    if (max_life_time > 0) {
        new_symbol.c = 33 + rand() % 93;
        max_life_time -= 7;
        new_symbol.start_life = rand() % max_life_time + 5;
    }
    else {
        new_symbol.c = ' ';
        new_symbol.start_life = 0;
    }
    new_symbol.is_generated = true;
    new_symbol.is_head = false;
    new_symbol.current_life = new_symbol.start_life;
    return new_symbol;
}
