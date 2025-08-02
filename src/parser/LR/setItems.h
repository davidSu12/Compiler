#ifndef SETITEMS_H
#define SETITEMS_H


#include "paths.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include BOTTOM_UP_ITEMS_PATH

/**
 * Important macro that
 * can be obtained previously by
 * preprocessing the list of productions
 */


/*
 * We are gonna
 * interchange space complexity for time complexity
 */

typedef struct NodeSetItem{
    item data;
    struct NodeSetItem * next;
}NodeSetItem;

typedef struct NodeSetItem * setItem;


#define DELETE_ELEMENT(set, i) (set & ~((1U << i)))
#define INSERT_ELEMENT(set, i) ( set | (1U << i))
#define ELEMENT_IN_SET(set, i) (set & (1U << i))
#define UNION_SET(set1, set2) (set1 | set2)


void createEmptySetItem(setItem *st1);
setItem * unionSetItems(setItem *st1, setItem *st2);
void deleteSetItem(setItem *st1);
bool addItem(setItem *st1, item it);
bool itemInSet(setItem st1, item it);
bool isEmptySetItem(setItem st1);
void deleteItem(setItem *st1, item it);
void printSetItem(setItem st1, void (*viewBinary)(uint32_t));
NodeSetItem *getSetProduction(setItem st1, uint32_t num_production);


#endif
