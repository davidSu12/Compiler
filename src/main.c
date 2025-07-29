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


#ifdef TEST_FIRST
#include "parser/LL/iterative/testFirst/testFirst.h"
#endif //TEST_FIRST



#ifdef TEST_FOLLOW
#include "parser/LL/iterative/testFollow/testFollow.h"
#endif //TEST_FOLLOW


#define TEST_PARSE_TABLE
#ifdef TEST_PARSE_TABLE
#include "parser/LL/iterative/testParseTable/testParseTable.h"
#endif //TEST_PARSE_TABLE


int main(int argc, char ** argv) {
    initParseTable();
    initBuffer();
    parse();
    /*
    pushProduction(*&listProduction[9]);
    assert(!isEmptyStack());
    assert(peekLabel() == LEFTPAR);
    popLabel();
    assert(peekLabel() == EXPR);
    popLabel();
    assert(peekLabel() == RIGHTPAR);
    popLabel();
    assert(isEmptyStack());
*/

    //testParseTable1();
    return 0;
}
