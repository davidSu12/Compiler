#include "testFirst.h"



static void auxtestFirst(setLabel t, token label){
    for(int i = 0; i < MAX_LEN_SET; i++){
        if(i == label){
            assert(t[i]);
        }else{
            assert(!t[i]);
        }
    }

}

void test1First(void){

    setLabel t;
    t = first(EXPR);

    assert(EXPR == 7);
    for(int i = 0; i < MAX_LEN_SET; i++){
        if(i == LEFTPAR || i == NUM){
            assert(t[i]);
        }else{
            assert(!t[i]);
        }
    }
    deleteLabelSet(&t);
    t = first(FACTOR);
    for(int i = 0; i < MAX_LEN_SET; i++){
        if(i == LEFTPAR || i == NUM){
            assert(t[i]);
        }else{
            assert(!t[i]);
        }
    }
    deleteLabelSet(&t);

}

void test2First(void){
    setLabel t;
    t = first(NUM);

    deleteLabelSet(&t);

    t = first(LEFTPAR);
    auxtestFirst(t, LEFTPAR);

    deleteLabelSet(&t);

    t = first(RIGHTPAR);
    auxtestFirst(t, RIGHTPAR);

    deleteLabelSet(&t);

    t = first(PLUS);
    auxtestFirst(t, PLUS);
    deleteLabelSet(&t);


}
void test3First(void){
    setLabel t;
    t = first(EXPRP);

    for(int i = 0; i<  MAX_LEN_SET; i++){
        if(i == PLUS || i == MINUS || i == EMPTY){
            assert(t[i]);
        }else{
            assert(!t[i]);
        }
    }

}
