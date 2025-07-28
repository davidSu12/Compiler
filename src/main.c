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

void testParseTable1(void); //EXPR
void testParseTable2(void); //TERM
void testParseTable3(void); //EXPRP
void testParseTable4(void); //TERMP
void testParseTable5(void); //FACTOR

int main(int argc, char ** argv) {


    testParseTable1();
    testParseTable2();

    /*
    setLabel t = first(EXPRP);
    printSetLabel(t);
*/

    /*Nos falta considerar la cadena vacia*/

    return 0;
}


void testParseTable1(void){
    initParseTable();
    assert(parseTable[VARIABLE_INDEX(EXPR)][TERMINAL_INDEX(LEFTPAR)] == &listProduction[0]);
    assert(parseTable[VARIABLE_INDEX(EXPR)][TERMINAL_INDEX(RIGHTPAR)] == NULL);
    assert(parseTable[VARIABLE_INDEX(EXPR)][TERMINAL_INDEX(NUM)] == &listProduction[0]);
    assert(parseTable[VARIABLE_INDEX(EXPR)][TERMINAL_INDEX(PLUS)] == NULL);
    assert(parseTable[VARIABLE_INDEX(EXPR)][TERMINAL_INDEX(MINUS)] == NULL);
    assert(parseTable[VARIABLE_INDEX(EXPR)][TERMINAL_INDEX(DOT)] == NULL);
}
/*
production listProduction[] = {
        {EXPR, (enum labelTok[]){TERM, EXPRP}, 2},
        {EXPRP, (enum labelTok[]){PLUS, TERM, EXPRP}, 3},
        {EXPRP, (enum labelTok[]){MINUS, TERM, EXPRP}, 3},
        {EXPRP, NULL, 0},
        {TERM, (enum labelTok[]){FACTOR, TERMP}, 2},
        {TERMP, (enum labelTok[]){DOT, FACTOR, TERMP}, 3},
        {TERMP, (enum labelTok[]){DIV, FACTOR, TERMP}, 3},
        {TERMP, NULL, 0},
        {FACTOR, (enum labelTok[]){NUM},1},
        {FACTOR, (enum labelTok[]){LEFTPAR,EXPR,RIGHTPAR},3},
        {EMPTY, NULL, 0} //final de production
};
 */
void testParseTable2(void){

    initParseTable();
    assert(parseTable[VARIABLE_INDEX(EXPRP)][TERMINAL_INDEX(LEFTPAR)] == NULL);
    assert(parseTable[VARIABLE_INDEX(EXPRP)][TERMINAL_INDEX(RIGHTPAR)] == &listProduction[3]);
    assert(parseTable[VARIABLE_INDEX(EXPRP)][TERMINAL_INDEX(NUM)] == NULL);
    assert(parseTable[VARIABLE_INDEX(EXPRP)][TERMINAL_INDEX(PLUS)] == &listProduction[1]);
    assert(parseTable[VARIABLE_INDEX(EXPRP)][TERMINAL_INDEX(MINUS)] == &listProduction[2]);
    assert(parseTable[VARIABLE_INDEX(EXPRP)][TERMINAL_INDEX(DOT)] == NULL);
    assert(parseTable[VARIABLE_INDEX(EXPRP)][TERMINAL_INDEX(DIV)] == NULL);

}
