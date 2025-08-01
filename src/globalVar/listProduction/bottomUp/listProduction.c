#include "listProduction.h"

production listProduction[] = {
        {EXPR, (token[]){EXPR, PLUS, TERM}, 3},
        {EXPR, (token[]){EXPR, MINUS, TERM}, 3},
        {EXPR, (token[]){TERM}, 1},
        {TERM, (token[]){TERM, DOT, FACTOR}, 3},
        {TERM, (token[]){TERM, DIV, FACTOR}, 3},
        {TERM, (token[]){FACTOR},1},
        {FACTOR, (token[]){LEFTPAR, EXPR, RIGHTPAR},3},
        {FACTOR, (token[]){NUM}, 1},
        {EMPTY, NULL, 0}
};