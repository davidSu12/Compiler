#ifndef TOKEN_H
#define TOKEN_H

enum labelTok{
    //unique terminals
    NUM,
    LEFTPAR,
    RIGHTPAR,
    PLUS,
    MINUS,
    DOT,
    DIV,

    //unique non terminals
    EXPR,
    TERM,
    FACTOR,

    //non terminals for top down parsing
    EXPRP,
    TERMP,

    //special symbols
    EMPTY,
    $
};


#endif
