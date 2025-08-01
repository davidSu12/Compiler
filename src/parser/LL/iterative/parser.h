#ifndef PARSER_H
#define PARSER_H


#include "paths.h"

#include LEXER_PATH
#include TOP_DOWN_ITERATIVE_SETLABEL_PATH
#include TYPE_PRODUCTION_PATH
#include TOP_DOWN_ITERATIVE_STACKPRODUCTION_PATH
#include TOP_DOWN_LISTPRODUCTION_PATH
#include TOP_DOWN_PARSETABLE_PATH

/**
 * @param head head of the production
 * @param body body of the production
 * @param longitud_array length of the body of the productionn
 * @return the newly created production
 */
production *createProduction(enum labelTok head, enum labelTok body[], int longitud_array);


/**
 * @param head
 * @return the set first of the grammar symbol head
 */
setLabel first(enum labelTok head);

/**
 * @param head
 * @return just looks if there's some production A -> emptyString.
 * If there is, then it returns true. If there's not then just returns false
 */
bool derivesEmptyString(enum labelTok head);

/**
 * @param head
 * @return the set follow of the grammar symbol head
 */
setLabel follow(enum labelTok head);

/**
 * inits the parse table with the necessary info to come up with the parsing
 */
void initParseTable(void);

/**
 * Just the same as first but with only one production
 * @param p
 * @return returns the set first of the production p
 */
setLabel first_production(production p);
/**
 * This function parses the specified string by stdin
 */
bool parse();



#endif
