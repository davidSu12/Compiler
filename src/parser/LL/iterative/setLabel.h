#ifndef SETLABEL_H
#define SETLABEL_H


#include "paths.h"

#include LEXER_PATH
#include TOKEN_PATH

#define MAX_LEN_SET (LAST_SYMBOL)

typedef bool * setLabel;

void createEmptySetLabel(setLabel *set);
bool isEmptySetLabel( setLabel set);
bool addLabel(token label, setLabel * set);
void deleteLabel(token label, setLabel * set);
bool searchLabel(token label, setLabel set);
void printSetLabel(setLabel t);
setLabel *unionSet(setLabel *set1, setLabel *set2);
void deleteLabelSet(setLabel *set);


#endif
