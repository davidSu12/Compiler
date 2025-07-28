#ifndef SETLABEL_H
#define SETLABEL_H


#define LEXER_INCLUDE_PATH "../../../lexer.h"
#include LEXER_INCLUDE_PATH


typedef bool * setLabel;

void createEmptySetLabel(setLabel *set);
bool isEmptySetLabel(setLabel set);
bool addLabel(enum labelTok label, setLabel * list);
void deleteLabel(enum labelTok label, setLabel * list);
bool searchLabel(enum labelTok label, setLabel list);
void printSetLabel(setLabel t);
setLabel *unionSet(setLabel *l1, setLabel *l2);
void deleteLabelSet(setLabel *l1);


#endif
