#include "testStackProduction.h"

void testInsertion(void){

    production *temp = createProduction(EXPRP,
                                        (enum labelTok []){PLUS, TERM, EXPRP},
                                        3);
    assert(temp -> head == EXPRP);
    assert(temp -> body[0] == PLUS);
    assert(temp -> body[1] == TERM);
    assert(temp -> body[2] == EXPRP);
    assert(temp -> longitud_body == 3);

    assert(pushProduction(temp));
    assert(peekLabel() == PLUS);
}
void testPop(void){
    production *temp = createProduction(EXPRP,
                                        (enum labelTok []){PLUS, TERM, EXPRP},
                                        3);
    assert(temp -> head == EXPRP);
    assert(temp -> body[0] == PLUS);
    assert(temp -> body[1] == TERM);
    assert(temp -> body[2] == EXPRP);
    assert(temp -> longitud_body == 3);

    assert(pushProduction(temp));
    assert(peekLabel() == PLUS);
    popLabel();
    assert(peekLabel()  == TERM);
    popLabel();
    assert(peekLabel() == EXPRP);
    popLabel();
    assert(isEmptyStack());

}
