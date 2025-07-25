#include <stdio.h>
#include "lexer.h"


int main(int argc, char ** argv){

    initBuffer();



#ifdef DEBUG
    token m = getNextToken();
    if(m -> string == STRING){
        printf("%s", m -> element.lexeme);
    }else{
        printf("%c", simbToChar(m ->element.simb));
    }
    m = getNextToken();
    if(m -> string == STRING){
        printf("%s", m -> element.lexeme);
    }else{
        printf("%c", simbToChar(m ->element.simb));
    }
    m = getNextToken();
    if(m -> string == STRING){
        printf("%s", m -> element.lexeme);
    }else{
        printf("%c", simbToChar(m ->element.simb));
    }

    m = getNextToken();
    if(m -> string == STRING){
        printf("%s", m -> element.lexeme);
    }else{
        printf("%c", simbToChar(m ->element.simb));
    }
#endif

    return 0;
}