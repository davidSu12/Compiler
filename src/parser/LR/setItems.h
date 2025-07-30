#ifndef SETITEMS_H
#define SETITEMS_H


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "items.h"
#include <assert.h>

/**
 * Important macro that
 * can be obtained previously by
 * preprocessing the list of productions
 */
#define NUM_PRODUCCIONES 10

typedef uint32_t *setItem;

#define DELETE_ELEMENT(set, i) (set ^ (1U << i))
#define INSERT_ELEMENT(set, i) ( set | (1U << i))
#define ELEMENT_IN_SET(set, i) (set & (1U << i))
#define UNION_SET(set1, set2) (set1 | set2)


void createEmptySetItem(setItem *st1);
setItem * unionSetItems(setItem *st1, setItem *st2);
void deleteSetItem(setItem *st1);
bool insertItem(setItem *st1, item it);
bool itemInSet(setItem st1, item it);
bool isEmptySetItem(setItem st1);
void deleteItem(setItem *st1, item it);

#endif
