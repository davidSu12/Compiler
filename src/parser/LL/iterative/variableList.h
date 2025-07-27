#ifndef VARIABLELIST_H
#define VARIABLELIST_H

#define LEXER_INCLUDE_PATH "../../../lexer.h"
#include LEXER_INCLUDE_PATH


typedef struct nodeLabel{

    enum labelTok item;
    struct nodeLabel * next;

}nodeLabel;


typedef struct nodeLabel * positionLabel;
typedef positionLabel listLabel;


//basic functions to manage the list;
void createEmptyListLabel(listLabel * list);
bool isEmptyListLabel(listLabel list);
bool insertLabel(enum labelTok label, listLabel * list);
void deleteLabel(enum labelTok label, listLabel * list);
positionLabel searchLabel(enum labelTok label, listLabel list);


#endif
