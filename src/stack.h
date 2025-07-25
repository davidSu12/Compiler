//
// Created by sam_s on 26/07/2025.
//

#ifndef COMPILERIMP_STACK_H
#define COMPILERIMP_STACK_H

#include "lexer.h"


/*
 * stack with a direct relation with list
 */

struct nodeStack{
    token elemento;
    struct nodeStack *next;
};

typedef struct nodeStack * stack;


void createEmptyStack();
bool insertElement(token elemento);
token pop();
token peek();
bool isEmptyStack();


#endif //COMPILERIMP_STACK_H
