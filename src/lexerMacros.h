#ifndef LEXERMACROS_H
#define LEXERMACROS_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <assert.h>


#define FIRST_NONTERMINAL EXPR
#define LAST_NONTERMINAL FACTOR
#define END '\0'
#define MAX_LEN_BUFF 1024
#define LNULL NULL
#define ISNULLTOKEN(s) (s == LNULL)
#define NOTSTRING false
#define STRING true
#define IS_VARIABLE(s) (FIRST_NONTERMINAL <= s && s <= LAST_NONTERMINAL)
#define LAST_VARIABLE ($+1)

#define FIRST_TERMINAL NUM
#define LAST_TERMINAL DIV
#define IS_TERMINAL(s) (s <= DIV)

#define NUM_TERMINALS (LAST_TERMINAL - FIRST_TERMINAL + 1)
#define NUM_VARIABLES (LAST_NONTERMINAL - FIRST_NONTERMINAL + 1)

#define VARIABLE_INDEX(s) (s - EXPR)
#define TERMINAL_INDEX(s) (s)

#endif
