#include "lexer.h"



static char buff[MAX_LEN_BUFF];
static char * lexemeBegin;
static char * currPosition;

void initBuffer(){
    memset(buff, EOF, MAX_LEN_BUFF);
    fgets(buff, MAX_LEN_BUFF -1, stdin);
}
void printBuffer(){
    printf("%s",buff);
}