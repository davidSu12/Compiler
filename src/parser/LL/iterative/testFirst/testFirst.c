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


static void auxtest2First(setLabel t, enum labelTok label){
    for(int i = 0; i < MAX_LEN_SET; i++){
        if(i == label){
            assert(t[i]);
        }else{
            assert(!t[i]);
        }
    }

}
void test2First(void){
    setLabel t;
    t = first(NUM);

    deleteLabelSet(&t);

    t = first(LEFTPAR);
    auxtest2First(t, LEFTPAR);

    deleteLabelSet(&t);

    t = first(RIGHTPAR);
    auxtest2First(t, RIGHTPAR);

    deleteLabelSet(&t);

    t = first(PLUS);
    auxtest2First(t, PLUS);
    deleteLabelSet(&t);


}
void test3First(void){

}
void test4First(void);
void test5First(void);
