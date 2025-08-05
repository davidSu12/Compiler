#include "testQuadruplets.h"



void testCreateQuadrupleNode(void){
    nodeQuadruplet *q = createNodeQuadruplet(PLUS, "t1","t0","t3");
    assert(q -> item.operation == PLUS);
    assert(strcmp(q -> item.arg1, "t1") == 0);
    assert(strcmp(q -> item.arg2, "t0") == 0);
    assert(strcmp(q -> item.result, "t3") == 0);
    free(q);
}
void testCreateEmptyQuadrupleList(void){
    quadrupletList  L;
    createEmptyQuadrupletList(&L);
    assert(isEmptyListQuadruplets(L));
}
void testInsertElementNode(void){
    quadrupletList  L;
    createEmptyQuadrupletList(&L);
    assert(isEmptyListQuadruplets(L));
    nodeQuadruplet *q = createNodeQuadruplet(PLUS, "t1","t0","t3");
    assert(q -> item.operation == PLUS);
    assert(strcmp(q -> item.arg1, "t1") == 0);
    assert(strcmp(q -> item.arg2, "t0") == 0);
    assert(strcmp(q -> item.result, "t3") == 0);
    assert(insertNodeQuadruplet(&L, q));
    assert(L.first == q);
    assert(L.last == q);

    nodeQuadruplet *q1 = createNodeQuadruplet(MINUS, "t1","t0","t4");
    assert(q1 -> item.operation == MINUS);
    assert(strcmp(q1 -> item.arg1, "t1") == 0);
    assert(strcmp(q1-> item.arg2, "t0") == 0);
    assert(strcmp(q1 -> item.result, "t4") == 0);
    assert(insertNodeQuadruplet(&L, q1));

    assert(L.first == q);
    assert(L.last == q1);


    nodeQuadruplet *q2 = createNodeQuadruplet(DOT, "t1","t0","t5");
    assert(q2 -> item.operation == DOT);
    assert(strcmp(q2 -> item.arg1, "t1") == 0);
    assert(strcmp(q2 -> item.arg2, "t0") == 0);
    assert(strcmp(q2 -> item.result, "t5") == 0);
    assert(insertNodeQuadruplet(&L, q2));

    nodeQuadruplet * temp = L.first;
    assert(temp == q);
    temp = temp -> next;
    assert(temp == q1);
    temp = temp -> next;
    assert(temp == q2);
    temp = temp -> next;
    assert(temp == NULL);
    free(q);
    free(q1);
    free(q2);


}
void testDeleteQuadrupletList(void){
    quadrupletList  L;
    createEmptyQuadrupletList(&L);
    assert(isEmptyListQuadruplets(L));
    nodeQuadruplet *q = createNodeQuadruplet(PLUS, "t1","t0","t3");
    assert(q -> item.operation == PLUS);
    assert(strcmp(q -> item.arg1, "t1") == 0);
    assert(strcmp(q -> item.arg2, "t0") == 0);
    assert(strcmp(q -> item.result, "t3") == 0);
    assert(insertNodeQuadruplet(&L, q));
    assert(L.first == q);
    assert(L.last == q);

    nodeQuadruplet *q1 = createNodeQuadruplet(MINUS, "t1","t0","t4");
    assert(q1 -> item.operation == MINUS);
    assert(strcmp(q1 -> item.arg1, "t1") == 0);
    assert(strcmp(q1-> item.arg2, "t0") == 0);
    assert(strcmp(q1 -> item.result, "t4") == 0);
    assert(insertNodeQuadruplet(&L, q1));

    assert(L.first == q);
    assert(L.last == q1);


    nodeQuadruplet *q2 = createNodeQuadruplet(DOT, "t1","t0","t5");
    assert(q2 -> item.operation == DOT);
    assert(strcmp(q2 -> item.arg1, "t1") == 0);
    assert(strcmp(q2 -> item.arg2, "t0") == 0);
    assert(strcmp(q2 -> item.result, "t5") == 0);
    assert(insertNodeQuadruplet(&L, q2));

    nodeQuadruplet * temp = L.first;
    assert(temp == q);
    temp = temp -> next;
    assert(temp == q1);
    temp = temp -> next;
    assert(temp == q2);
    temp = temp -> next;
    assert(temp == NULL);

    deleteListQuadruplet(&L);
    assert(isEmptyListQuadruplets(L));

}
void testIsEmptyListQuadrupletList(void){

    quadrupletList q;
    createEmptyQuadrupletList(&q);
    assert(isEmptyListQuadruplets(q));
}

