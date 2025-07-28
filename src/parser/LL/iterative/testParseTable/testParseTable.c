#include "testParseTable.h"

#define PATH_PARSER_H "../parser.h"
#define PATH_PARSE_TABLE "../parseTable.h"

#include PATH_PARSER_H
#include PATH_PARSE_TABLE


void testParseTable1(void){
    initParseTable();
    assert(parseTable[VARIABLE_INDEX(EXPR)][TERMINAL_INDEX(LEFTPAR)] == &listProduction[0]);
    assert(parseTable[VARIABLE_INDEX(EXPR)][TERMINAL_INDEX(RIGHTPAR)] == NULL);
    assert(parseTable[VARIABLE_INDEX(EXPR)][TERMINAL_INDEX(NUM)] == &listProduction[0]);
    assert(parseTable[VARIABLE_INDEX(EXPR)][TERMINAL_INDEX(PLUS)] == NULL);
    assert(parseTable[VARIABLE_INDEX(EXPR)][TERMINAL_INDEX(MINUS)] == NULL);
    assert(parseTable[VARIABLE_INDEX(EXPR)][TERMINAL_INDEX(DOT)] == NULL);
}

void testParseTable2(void){
    initParseTable();
    assert(parseTable[VARIABLE_INDEX(TERM)][TERMINAL_INDEX(LEFTPAR)] == &listProduction[4]);
    assert(parseTable[VARIABLE_INDEX(TERM)][TERMINAL_INDEX(RIGHTPAR)] == NULL);
    assert(parseTable[VARIABLE_INDEX(TERM)][TERMINAL_INDEX(NUM)] == &listProduction[4]);
    assert(parseTable[VARIABLE_INDEX(TERM)][TERMINAL_INDEX(PLUS)] == NULL);
    assert(parseTable[VARIABLE_INDEX(TERM)][TERMINAL_INDEX(MINUS)] == NULL);
    assert(parseTable[VARIABLE_INDEX(TERM)][TERMINAL_INDEX(DOT)] == NULL);
    assert(parseTable[VARIABLE_INDEX(TERM)][TERMINAL_INDEX(DIV)] == NULL);
}
void testParseTable3(void){

    initParseTable();
    assert(parseTable[VARIABLE_INDEX(EXPRP)][TERMINAL_INDEX(LEFTPAR)] == NULL);
    assert(parseTable[VARIABLE_INDEX(EXPRP)][TERMINAL_INDEX(RIGHTPAR)] == &listProduction[3]);
    assert(parseTable[VARIABLE_INDEX(EXPRP)][TERMINAL_INDEX(NUM)] == NULL);
    assert(parseTable[VARIABLE_INDEX(EXPRP)][TERMINAL_INDEX(PLUS)] == &listProduction[1]);
    assert(parseTable[VARIABLE_INDEX(EXPRP)][TERMINAL_INDEX(MINUS)] == &listProduction[2]);
    assert(parseTable[VARIABLE_INDEX(EXPRP)][TERMINAL_INDEX(DOT)] == NULL);
    assert(parseTable[VARIABLE_INDEX(EXPRP)][TERMINAL_INDEX(DIV)] == NULL);

}

void testParseTable4(void){
    initParseTable();
    assert(parseTable[VARIABLE_INDEX(TERMP)][TERMINAL_INDEX(LEFTPAR)] == NULL);
    assert(parseTable[VARIABLE_INDEX(TERMP)][TERMINAL_INDEX(RIGHTPAR)] == &listProduction[7]);
    assert(parseTable[VARIABLE_INDEX(TERMP)][TERMINAL_INDEX(NUM)] == NULL);
    assert(parseTable[VARIABLE_INDEX(TERMP)][TERMINAL_INDEX(PLUS)] == &listProduction[7]);
    assert(parseTable[VARIABLE_INDEX(TERMP)][TERMINAL_INDEX(MINUS)] == &listProduction[7]);
    assert(parseTable[VARIABLE_INDEX(TERMP)][TERMINAL_INDEX(DOT)] == &listProduction[5]);
    assert(parseTable[VARIABLE_INDEX(TERMP)][TERMINAL_INDEX(DIV)] == &listProduction[6]);
}
void testParseTable5(void){
    initParseTable();
    assert(parseTable[VARIABLE_INDEX(FACTOR)][TERMINAL_INDEX(LEFTPAR)] == &listProduction[9]);
    assert(parseTable[VARIABLE_INDEX(FACTOR)][TERMINAL_INDEX(RIGHTPAR)] == NULL);
    assert(parseTable[VARIABLE_INDEX(FACTOR)][TERMINAL_INDEX(NUM)] == &listProduction[8]);
    assert(parseTable[VARIABLE_INDEX(FACTOR)][TERMINAL_INDEX(PLUS)] == NULL);
    assert(parseTable[VARIABLE_INDEX(FACTOR)][TERMINAL_INDEX(MINUS)] == NULL);
    assert(parseTable[VARIABLE_INDEX(FACTOR)][TERMINAL_INDEX(DOT)] == NULL);
    assert(parseTable[VARIABLE_INDEX(FACTOR)][TERMINAL_INDEX(DIV)] == NULL);
}
