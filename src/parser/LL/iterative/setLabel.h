#ifndef SETLABEL_H
#define SETLABEL_H


#define LEXER_INCLUDE_PATH "../../../lexer.h"
#include LEXER_INCLUDE_PATH

#define MAX_LEN_SET (LAST_VARIABLE)

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
