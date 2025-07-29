#ifndef TESTHEADER_H
#define TESTHEADER_H

#ifdef TEST_FIRST_FUNCTION
#include "parser/LL/iterative/testFirst/testFirst.h"
#endif //TEST_FIRST_FUNCTION

#ifdef TEST_FOLLOW_FUNCTION
#include "parser/LL/iterative/testFollow/testFollow.h"
#endif //TEST_FOLLOW_FUNCTION

#ifdef TEST_PARSE_TABLE_FUNCTION
#include "parser/LL/iterative/testParseTable/testParseTable.h"
#endif //TEST_PARSE_TABLE_FUNCTION

#endif