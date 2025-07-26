#include "parser.h"

static token lookahead;


void expr(){

    lookahead = getNextToken();

    if(lookahead -> label == LEFTPAR){
        expr();
        match(RIGHTPAR);
    }else{
        term();
        exprP();
    }

}
void exprP(){

}
void term(){

}
void termP(){

}
void factor(){

}
void match(enum labelTok tok){
    if(tok != lookahead -> label){
        fprintf(stderr, "Syntax error. Aborting compilation\n");
        exit(EXIT_FAILURE);
    }else{
        lookahead = getNextToken();
    }
}
