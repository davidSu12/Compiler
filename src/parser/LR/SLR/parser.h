#ifndef PARSER_H
#define PARSER_H

#include "paths.h"

#include BOTTOM_UP_ITEMS_PATH
#include BOTTOM_UP_SETITEMS_PATH
#include TOP_DOWN_LISTPRODUCTION_PATH
#include TOKEN_PATH
#include LEXER_MACROS_PATH
#include BOTTOM_UP_TEST_SUPER_SET_ITEMS


setItem * closure(setItem *st1);
setItem * gotoFunction(setItem *st1, token tok);
superSetItem * canonicalSet(void);



#endif
