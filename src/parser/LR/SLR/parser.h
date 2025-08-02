#ifndef PARSER_H
#define PARSER_H

#include "paths.h"

#include BOTTOM_UP_ITEMS_PATH
#include BOTTOM_UP_SETITEMS_PATH
#include TOP_DOWN_LISTPRODUCTION_PATH
#include TOKEN_PATH
#include LEXER_MACROS_PATH


/*
 * We may do a better approach
 * on listProduction by turning this list
 * into a hashtable for the heads of the production
 * than looking individually for each head
 */
setItem * closure(setItem *st1);
setItem gotoFunction(setItem *st1, token tok);


#endif
