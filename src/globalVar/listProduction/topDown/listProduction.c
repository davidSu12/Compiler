#include "listProduction.h"

production listProduction[] = {
        {EXPR, (token[]){TERM, EXPRP}, 2},
        {EXPRP, (token[]){PLUS, TERM, EXPRP}, 3},
        {EXPRP, (token[]){MINUS, TERM, EXPRP}, 3},
        {EXPRP, (token[]){EMPTY}, 1},
        {TERM, (token[]){FACTOR, TERMP}, 2},
        {TERMP, (token[]){DOT, FACTOR, TERMP}, 3},
        {TERMP, (token[]){DIV, FACTOR, TERMP}, 3},
        {TERMP, (token[]){EMPTY}, 1},
        {FACTOR, (token[]){NUM},1},
        {FACTOR, (token[]){LEFTPAR,EXPR,RIGHTPAR},3},
        {EMPTY, NULL, 0} //final de production
};

