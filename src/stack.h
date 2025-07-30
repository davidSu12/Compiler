#ifndef COMPILERIMP_STACK_H
#define COMPILERIMP_STACK_H

#include "lexer.h"




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
