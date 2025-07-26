#ifndef PARSER_H
#define PARSER_H

#define LEXER_INCLUDE_PATH "../../../lexer.h"
#include LEXER_INCLUDE_PATH

//num_variables = 5
//num_terminals = 7

typedef struct production{
    enum labelTok head;
    enum labelTok * body;
    int longitud_body;
}production;


production *createProduction(enum labelTok head, enum labelTok body[], int longitud_array);
void initParseTable(void);


#endif
