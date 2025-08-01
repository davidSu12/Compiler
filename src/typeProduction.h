#ifndef TYPEPRODUCTION_H
#define TYPEPRODUCTION_H

#define TOKEN_PATH "token.h"
#include TOKEN_PATH

typedef struct production{
    token head;
    token * body;
    int longitud_body;
}production;

#endif
