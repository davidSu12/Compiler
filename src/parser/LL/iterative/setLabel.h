#ifndef SETLABEL_H
#define SETLABEL_H


#include "paths.h"

#include LEXER_PATH
#include TOKEN_PATH

#define MAX_LEN_SET (LAST_SYMBOL)

typedef bool * setLabel;

void createEmptySetLabel(setLabel *set);
bool isEmptySetLabel( setLabel set);
bool addLabel(enum labelTok label, setLabel * set);
void deleteLabel(enum labelTok label, setLabel * set);
bool searchLabel(enum labelTok label, setLabel set);
void printSetLabel(setLabel t);
setLabel *unionSet(setLabel *set1, setLabel *set2);
void deleteLabelSet(setLabel *set);


#endif
