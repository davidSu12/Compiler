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

/*
 * Por una parte definimos los token para los
 * cuales necesitamos guardar algun tipo de informacion
 * por otro guardamos los token simbolicos sobre
 * los cuales tenemos que saber unicamente
 * la clase de simbolo que nos encontramos ¡
 */


enum labelTok{
    NUM,    LEFTPAR,    RIGHTPAR,
    PLUS,   MINUS,      DOT,        DIV
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


//auxFunc
void initBuffer();
void printBuffer();


char simbToChar(enum labelTok);


//getNextToken -> token
/*This function returns the next token on the input and returns NULL if there is no more input
*/
token getNextToken();



//a few functions just to work on the token list
void deleteListToken();
bool isEmptyList();

#endif //LEXER_H
