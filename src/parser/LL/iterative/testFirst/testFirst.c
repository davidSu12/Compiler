#include "testFirst.h"




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
    for(int i = 0; i < MAX_LEN_SET; i++){
        if(i == NUM){
            assert(t[i]);
        }else{
            assert(!t[i]);
        }
    }

}
void test3First(void){

}
void test4First(void);
void test5First(void);
