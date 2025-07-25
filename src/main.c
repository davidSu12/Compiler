#include <stdio.h>
#include "lexer.h"

#define DEBUG

int main(int argc, char ** argv){

    token m;
    initBuffer();



#ifdef DEBUG
    while((m = getNextToken()) != NULL){
        if(m -> string == STRING){
            printf("%s", m -> element.lexeme);
        }else{
            printf("%c", simbToChar(m ->element.simb));
        }
    }
#endif

    deleteListToken();
    return 0;
}