#ifndef QUADRUPLETS_H
#define QUADRUPLETS_H
#include "paths.h"
#include TOKEN_PATH
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>

typedef struct itemQuadruplet{
    token operation;
    char *arg1;
    char *arg2;
    char *result;
}itemQuadruplet;

typedef struct nodeQuadruplet{
    itemQuadruplet item;
    struct nodeQuadruplet * next;
}nodeQuadruplet;

typedef struct quadrupletList{
    struct nodeQuadruplet * first;
    struct nodeQuadruplet * last;
}quadrupletList;


void createEmptyQuadrupletList(quadrupletList * list);
nodeQuadruplet * createNodeQuadruplet(token operation, char * arg1, char * arg2, char * result);
bool insertNodeQuadruplet(quadrupletList * list, nodeQuadruplet *node);
void deleteListQuadruplet(quadrupletList * list);
bool isEmptyListQuadruplets(quadrupletList l);

#endif
