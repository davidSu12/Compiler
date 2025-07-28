#include <stdio.h>
#include "lexer.h"

#define TOP_DOWN_IT

#ifdef TOP_DOWN_PR
#include "parser/LL/predictive/parser.h"
#endif //TOP_DOWN_PR
#ifdef TOP_DOWN_IT
#include "parser/LL/iterative/parser.h"
#include "parser/LL/iterative/stack_production.h"
#include "parser/LL/iterative/testStackProduction.h"
#endif //TOP_DOWN_IT

#define TEST_FIRST
#ifdef TEST_FIRST
#include "parser/LL/iterative/testFirst/testFirst.h"
#endif //TEST_FIRST
#undef TEST_FIRST

#define TEST_FOLLOW
#include "parser/LL/iterative/testFollow/testFollow.h"
#ifdef TEST_FOLLOW
#endif //TEST_FOLLOW

int main(int argc, char ** argv){

    printf("%d", FIRST_NONTERMINAL - EXPR);
    printf("%d", LAST_NONTERMINAL - EXPR);
    printf("num vars:%d", NUM_VARIABLES);
    printf("num terminals:%d",NUM_TERMINALS);
    printf("%d", FIRST_TERMINAL);
    printf("%d", LAST_TERMINAL);

    return 0;
}
