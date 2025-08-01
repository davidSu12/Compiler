#ifndef PARSER_H
#define PARSER_H

#define ITEMS_PATH "parser/LR/items.h"
#define SET_ITEMS_PATH "parser/LR/setItems.h"

#define LIST_PRODUCTION_PATH "globalVar/listProduction.h"

#define TOKEN_PATH "token.h"
#define LEXER_HEADER_PATH "lexerMacros.h"

#include ITEMS_PATH
#include SET_ITEMS_PATH
#include LIST_PRODUCTION_PATH
#include TOKEN_PATH
#include LEXER_HEADER_PATH


/*
 * We may do a better approach
 * on listProduction by turning this list
 * into a hashtable for the heads of the production
 * than looking individually for each head
 */
setItem * closure(setItem *st1);
setItem gotoFunction(setItem *st1, enum labelTok token);


#endif
