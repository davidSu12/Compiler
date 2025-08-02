#ifndef SUPERSETITEMS_H
#define SUPERSETITEMS_H

#include "paths.h"
#include <stdbool.h>
#include BOTTOM_UP_SETITEMS_PATH

typedef struct NodeSuperSetItem{

    setItem *set;
    struct NodeSuperSetItem * next;

}NodeSuperSetItem;

typedef struct NodeSuperSetItem * superSetItem;

void createEmptySuperSet(superSetItem *set);
bool addSet(superSetItem *superSet, setItem *set);
void deleteSet(superSetItem *superSet, setItem *set);
bool isEmptySuperSetItem(superSetItem set);
void deleteSuperSet(superSetItem *superSet);


#endif
