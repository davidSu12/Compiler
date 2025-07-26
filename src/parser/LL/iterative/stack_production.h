#ifndef STACK_PRODUCTION_H
#define STACK_PRODUCTION_H

#include "parser.h"

typedef struct nodeProduction{
    production item;
    struct production *next;
}nodeProduction;


/**
 * @param el element to introduce in the stack
 * @return true if everything goes right false otherwise
 */
bool push(production el);

/**
 * @return element that is in the top of the stack
 */
production peek();

/**
 * @return true if the stack is empty, false otherwise
 */
bool isEmptyList();

/**
 * pops the element on the top of the stack.
 * If everything goes wrong, then a message is emited
 */
void pop();

#endif
