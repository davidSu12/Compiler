#ifndef PARSER_H
#define PARSER_H

#define LEXER_INCLUDE_PATH "../../../lexer.h"
#include LEXER_INCLUDE_PATH
#include "setLabel.h"


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


production *createProduction(enum labelTok head, enum labelTok body[], int longitud_array);
setLabel first(enum labelTok head);
bool derivesEmptyString(enum labelTok head);
setLabel follow(enum labelTok head);



#endif
