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
#include "parser/LL/iterative/parseTable.h"
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


#ifdef TEST_PARSE_TABLE
#include "parser/LL/iterative/testParseTable/testParseTable.h"
#endif //TEST_PARSE_TABLE


int main(int argc, char ** argv) {




    /*Nos falta considerar la cadena vacia*/

    return 0;
}
