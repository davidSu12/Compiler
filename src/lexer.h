#ifndef LEXER_H
#define LEXER_H

#include "paths.h"
#include LEXER_MACROS_PATH
#include TOKEN_PATH


typedef struct node{
    union{
        char *lexeme;
        enum labelTok simb;
    }element;

    enum labelTok label;
    struct node * next;
}node;


typedef struct node * token;
typedef token ListToken;


/**
 * inits the buffer from stdin
 */
void initBuffer();

/**
 * inits the buffer with str
 * @param str
 */
void initBufferString(char *str);

/**
 * auxiliar function just to se the buffer
 * @deprecated
 */
void printBuffer();

/**
 * corresponding char for item
 * @param item
 * @return the corresponding char for item
 */
char simbToChar(enum labelTok item);


/**
 * function tha returns the next token in the buffer
 * @return the next token from the buffer
 */
token getNextToken(void);


/**
 * delete the corresponfing list for token
 */
void deleteListToken(void);


/**
 * finds out if the list of tokens is empty
 * @return true if the list of tokens is empty false otherwise
 */
bool isEmptyList(void);

#endif //LEXER_H
