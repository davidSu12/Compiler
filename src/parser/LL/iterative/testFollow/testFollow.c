#include "testFollow.h"


static void auxtestFollow(setLabel t, enum labelTok label){
    for(int i = 0; i < MAX_LEN_SET; i++){
        if(i == label){
            assert(t[i]);
        }else{
            assert(!t[i]);
        }
    }

}


void test1Follow(void){
    setLabel t = follow(EXPR);

    for(int i = 0; i < MAX_LEN_SET; i++){
        if(i == $ || i == RIGHTPAR){
            assert(t[i]);
        }else{
            assert(!t[i]);
        }
    }

    deleteLabelSet(&t);
}
void test2Follow(void){

    setLabel t= follow(FACTOR);
    for(int i = 0; i < MAX_LEN_SET; i++){
        switch(i){
            case RIGHTPAR:
            case PLUS:
            case MINUS:
            case DOT:
            case DIV:
            case $:
                assert(t[i]);
                break;
            default:
                //el resto de simbolos
                assert(!t[i]);

        }
    }
    deleteLabelSet(&t);
}

void test3Follow(void){
    setLabel t = follow(LEFTPAR);
    for(int i = 0; i < MAX_LEN_SET; i++){
        switch(i){
            case NUM:
            case LEFTPAR:
                assert(t[i]);
                break;
            default:
                assert(!t[i]);

        }
    }

    deleteLabelSet(&t);
    t = follow(RIGHTPAR);
    for(int i = 0; i < MAX_LEN_SET; i++){
        switch(i){
            case RIGHTPAR:
            case PLUS:
            case MINUS:
            case DOT:
            case DIV:
            case $:
                assert(t[i]);
                break;
            default:
                assert(!t[i]);

        }
    }
    deleteLabelSet(&t);

}
