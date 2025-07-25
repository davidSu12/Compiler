#ifndef LEXER_H
#define LEXER_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define EOF '\0'
#define MAX_LEN_BUFF 1024


typedef struct token{
    char *lexeme;
    struct token * next;
}token;


typedef struct token * ListToken;


//auxFunc
void initBuffer();
void printBuffer();


#endif //LEXER_H
