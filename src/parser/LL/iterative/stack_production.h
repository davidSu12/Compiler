#ifndef STACK_PRODUCTION_H
#define STACK_PRODUCTION_H

#include "typeProduction.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct nodeProduction{
    enum labelTok item;
    struct nodeProduction *next;
}nodeProduction;

typedef struct nodeProduction * stackProduction;



void createEmptyStackProd();
/**
 * @param el element to introduce in the stack
 * @return true if everything goes right false otherwise
 */
bool pushProduction(production el);

/**
 * @return element that is in the top of the stack
 */
enum labelTok peekLabel();

/**
 * @return true if the stack is empty, false otherwise
 */
bool isEmptyStack();

/**
 * pops the element on the top of the stack.
 * If everything goes wrong, then a message is emited
 */
void popLabel();

/**
 *
 * @param label label to push on the stack
 * @return returns true if everything goes right, else otherwise
 */
bool pushLabel(enum labelTok label);


void printStack();
#endif
