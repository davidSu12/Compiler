#ifndef AST_H
#define AST_H

#include "paths.h"
#include TOKEN_PATH
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


typedef enum typeEntry{
    AST_INTERIOR,
    AST_LEAF
}typeEntry;

typedef enum typeNode{
    INTERIOR_NODE,
    LEAF_NODE,
    EMPTY_TREE
}typeNode;

typedef struct nodeLeaf{
    char *lexeme;
}nodeLeaf;

typedef struct nodeInterior{
    token operation;
    typeEntry entryLeft;
    typeEntry entryRight;
    union{
        struct nodeLeaf * leaf;
        struct nodeInterior * nonLeaf;
    }left;

    union{
        struct nodeLeaf * leaf;
        struct nodeInterior * nonLeaf;
    }right;

}nodeInterior;


typedef struct nodeTree{
    union{
        struct nodeInterior n1;
        struct nodeLeaf n2;
    } * entry;

    typeNode type;
    struct nodeTree *left;
    struct nodeTree *right;
}nodeTree;

typedef struct nodeTree * astTree;







#endif
