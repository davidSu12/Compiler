#ifndef PARSER_H
#define PARSER_H

#define ITEMS_PATH "parser/LR/items.h"
#define SET_ITEMS_PATH "parser/LR/setItems.h"
#define LIST_PRODUCTION_PATH "globalVar/listProduction.h"
#define TOKEN_PATH "token.h"

#include ITEMS_PATH
#include SET_ITEMS_PATH
#include LIST_PRODUCTION_PATH
#include TOKEN_PATH



setItem * closure(setItem *st1);
setItem * gotoFunction(setItem *st1, enum labelTok token);


#endif
