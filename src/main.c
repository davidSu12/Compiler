#include <stdio.h>
#include "lexer.h"

#define DEBUG

int main(int argc, char ** argv){

    token m;
    initBuffer();



#ifdef DEBUG
    while((m = getNextToken()) != NULL){
        if(m -> label == NUM){

            //printf("longitud: %d\t",(int) strlen(m->element.lexeme));
            printf("%s\n", m -> element.lexeme);
        }else{
            printf("%c\n", simbToChar(m ->element.simb));
        }
    }
#endif

    deleteListToken();
    return 0;
}