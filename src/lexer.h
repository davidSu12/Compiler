#ifndef LEXER_H
#define LEXER_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <assert.h>


#define END '\0'
#define MAX_LEN_BUFF 1024
#define LNULL NULL
#define ISNULLTOKEN(s) (s == LNULL)
#define NOTSTRING false
#define STRING true
#define IS_VARIABLE(s) (EXPR <= s && s <= FACTOR)
#define LAST_VARIABLE ($+1)

#define FIRST_TERMINAL NUM
#define LAST_TERMINAL DIV
#define IS_TERMINAL(s) (s <= DIV)
#define FIRST_NONTERMINAL EXPR
#define LAST_NONTERMINAL FACTOR

#define NUM_TERMINALS (LAST_TERMINAL - FIRST_TERMINAL + 1)
#define NUM_VARIABLES (LAST_NONTERMINAL - FIRST_NONTERMINAL + 1)

#define VARIABLE_INDEX(s) (s - EXPR)
#define TERMINAL_INDEX(s) (s)

enum labelTok{
    NUM,
    LEFTPAR,
    RIGHTPAR,
    PLUS,
    MINUS,
    DOT,
    DIV,
    EXPR,
    EXPRP,
    TERM,
    TERMP,
    FACTOR,
    EMPTY,
    $
};


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
