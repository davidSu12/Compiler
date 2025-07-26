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

/**
 * @param head is the head of the production
 * @param body is an array that is equal to the body of the production
 * @param longitud_array is the length of body
 * @return a node pointing to a production containing all the necessary info
 */
production *createProduction(enum labelTok head, enum labelTok body[], int longitud_array);

/**
 * inits the parse table
 */
void initParseTable(void);


#endif
