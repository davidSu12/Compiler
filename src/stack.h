#ifndef COMPILERIMP_STACK_H
#define COMPILERIMP_STACK_H

#include "lexer.h"




struct nodeStack{
    nodeToken elemento;
    struct nodeStack *next;
};

typedef struct nodeStack * stack;


void createEmptyStack();
bool insertElement(nodeToken elemento);
nodeToken pop();
nodeToken peek();
bool isEmptyStack();


#endif //COMPILERIMP_STACK_H
