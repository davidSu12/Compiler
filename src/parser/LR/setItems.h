#ifndef SETITEMS_H
#define SETITEMS_H


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


/**
 * Important macro that
 * can be obtained previously by
 * preprocessing the list of productions
 */
#define NUM_PRODUCCIONES 10

typedef uint32_t *setItem;

#define DELETE_ELEMENT(set, i) (set ^ (1U << i))
#define INSERT_ELEMENT(set, i) ( set | (1U << i))
#define IS_ELEMENT(set, i) (set & (1U << i))


void createEmptySetItem(setItem *st1);
setItem * unionSetItems(setItem *st1, setItem *st2);
void deleteSetItem(setItem *st1);

#endif
