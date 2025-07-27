#ifndef PARSER_H
#define PARSER_H

#define LEXER_INCLUDE_PATH "../../../lexer.h"
#include LEXER_INCLUDE_PATH
#include "variableList.h"


enum TypeEntry{ERROR, NORMAL};

typedef struct production{
    enum labelTok head;
    enum labelTok * body;
    int longitud_body;
}production;

typedef struct entryTable{
    enum TypeEntry tipoEntrada;
    union element{
        production prod;
        void (*error_func)(void);
    };
}entryTable;


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




production *createProduction(enum labelTok head, enum labelTok body[], int longitud_array);
listLabel first(enum labelTok head);
bool derivesEmptyString(enum labelTok head);


#endif
