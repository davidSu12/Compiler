#include <stdio.h>
#include "lexer.h"

#define TOP_DOWN_PR
#ifdef TOP_DOWN_PR
#include "parser/LL/predictive/parser.h"
#endif
#ifdef TOP_DOWN_IT
#include "parser/LL/iterative/parser.h"
#endif


void test();
void ParserGoodCasesTest();
void ParserBadCasesTest();

int main(int argc, char ** argv){


#ifdef TEST_PARSER
    testParser();
#endif
    return 0;
}



void ParserBadCasesTest(){
#ifdef TEST_PARSER
    initBufferString("1++2");
initParser();
assert(!parse());
deleteListToken();

initBufferString("((1+2)");
initParser();
assert(!parse());
deleteListToken();

initBufferString("1+2)");
initParser();
assert(!parse());
deleteListToken();

initBufferString("(3*)4");
initParser();
assert(!parse());
deleteListToken();

initBufferString("5+");
initParser();
assert(!parse());
deleteListToken();

initBufferString("*3+2");
initParser();
assert(!parse());
deleteListToken();

initBufferString("((2+3)*(4-))");
initParser();
assert(!parse());
deleteListToken();

initBufferString("()");
initParser();
assert(!parse());
deleteListToken();

initBufferString("");
initParser();
assert(!parse());
deleteListToken();
#endif
}

void testParser(){
#ifdef TEST_PARSER
    initBufferString("1+2*3");
    initParser();
    assert(parse());
    deleteListToken();

    initBufferString("(1+2)*3");
    initParser();
    assert(parse());
    deleteListToken();

    initBufferString("((1+1)*3+4*5-8)");
    initParser();
    assert(parse());
    deleteListToken();

    initBufferString("((2+3)*(4-2))/2");
    initParser();
    assert(parse());
    deleteListToken();

    initBufferString("6/3+4*(2+1)");
    initParser();
    assert(parse());
    deleteListToken();

    initBufferString("((10-5)*(3+2))-4");
    initParser();
    assert(parse());
    deleteListToken();

    initBufferString("((2+3)+((4*5)/2))");
    initParser();
    assert(parse());
    deleteListToken();

    initBufferString("1+(2*(3+(4*(5+6))))");
    initParser();
    assert(parse());
    deleteListToken();

    initBufferString("(((((1+2))))+3)");
    initParser();
    assert(parse());
    deleteListToken();

#endif
};
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