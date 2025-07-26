#include <stdio.h>
#include "lexer.h"

#define TOP_DOWN_PR

#ifdef TOP_DOWN_PR
#include "parser/LL/predictive/parser.h"
#endif


void test();

int main(int argc, char ** argv){

    return 0;
}


void test(){

#ifdef DEBUG
    token m;
    initBuffer();

    while((m = getNextToken()) != NULL){
        if(m -> label == NUM){

            //printf("longitud: %d\t",(int) strlen(m->element.lexeme));
            printf("%s\n", m -> element.lexeme);
        }else{
            printf("%c\n", simbToChar(m ->element.simb));
        }
    }
    deleteListToken();
#endif

}