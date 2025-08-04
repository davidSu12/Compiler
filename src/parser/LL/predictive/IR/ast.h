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


typedef struct nodeTree{

    typeNode type;

    union{
        token operation;
        char * lexeme;
    }entry;

    struct nodeTree * left;
    struct nodeTree * right;

}nodeTree;



typedef struct nodeTree * astTree;







#endif
