#include "parser.h"


static nodeToken lookahead;
static nodeTree * EXPRNODE; //this is our ast tree
static nodeTree * EXPRPNODE;
static nodeTree * EXPRINHERITED;
static nodeTree * TERMNODE;
static nodeTree * TERMPINHERITED;
static nodeTree * TERMPNODE;
static nodeTree * FACTORNODE;
static nodeTree * FACTORSYN;
static nodeTree * EXPRPINHERITED;
static int tempI = 0;

static void SyntaxError(void) {
    fprintf(stderr, "Syntax error\n");
    exit(EXIT_FAILURE);

}

void getQuadrupletList(nodeTree * tree, quadrupletList *L){
    if((tree -> left -> type == LEAF_NODE && tree -> right -> type == LEAF_NODE)){

        char buff[5] = {'\0'};
        sprintf(buff, "t%d", ++tempI);

        nodeQuadruplet *q = createNodeQuadruplet(
                tree -> entry.operation,
                tree -> left -> entry.lexeme,
                tree -> right -> entry.lexeme,
                buff);

        insertNodeQuadruplet(L, q);
    }else{

        if((tree -> left -> type != LEAF_NODE) && (tree -> right -> type == LEAF_NODE)){
            getQuadrupletList(tree -> left, L);
            int leftLabel = tempI;
            char buff[5] = {'\0'};
            sprintf(buff, "t%d", leftLabel);
            char buff1[5] = {'\0'};
            sprintf(buff1, "t%d", ++tempI);

            nodeQuadruplet *node = createNodeQuadruplet(
                    tree -> entry.operation,
                    buff,
                    tree -> right ->entry.lexeme,
                    buff1
                    );
            insertNodeQuadruplet(L, node);

        }else if((tree -> left -> type == LEAF_NODE)&&(tree -> right -> type != LEAF_NODE)){
            getQuadrupletList(tree -> right, L);
            int rightLabel = tempI;
            char buff[5] = {'\0'};
            sprintf(buff, "t%d", rightLabel);
            char buff1[5] = {'\0'};
            sprintf(buff1, "t%d", ++tempI);

            nodeQuadruplet * node = createNodeQuadruplet(
                    tree ->entry.operation,
                    tree -> left -> entry.lexeme,
                    buff,
                    buff1
                    );
            insertNodeQuadruplet(L, node);

        }else{
            getQuadrupletList(tree -> left,L);
            int leftLabel = tempI;
            getQuadrupletList(tree -> right,L);
            int rightLabel = tempI;
            char buff[5] = {'\0'};
            char buff1[5] = {'\0'};
            char buff2[5] = {'\0'};
            sprintf(buff, "t%d", leftLabel);
            sprintf(buff1, "t%d", rightLabel);
            sprintf(buff2, "t%d", ++tempI);

            nodeQuadruplet *node = createNodeQuadruplet(
                    tree -> entry.operation,
                    buff,
                    buff1,
                    buff2
                    );
            insertNodeQuadruplet(L, node);
        }
    }
}
void translateEntry(nodeTree *tree){
    if((tree -> left -> type == LEAF_NODE && tree -> right -> type == LEAF_NODE)){
        printf(
        "t%d= %s%c%s\n",
               ++tempI,
               tree -> left -> entry.lexeme ,
               simbToChar(simbToChar(tree -> entry.operation)),
              tree -> right -> entry.lexeme
              );
    }else{
        if((tree -> left -> type != LEAF_NODE) && (tree -> right -> type == LEAF_NODE)){
            translateEntry(tree -> left);
            int leftLabel = tempI;
            char buff[5] = {'\0'};
            sprintf(buff, "t%d", leftLabel);
            printf(
                    "t%d= %s%c%s\n",
                    ++tempI,
                    buff,
                    simbToChar(tree -> entry.operation),
                    tree -> right ->entry.lexeme
                    );
        }else if((tree -> left -> type == LEAF_NODE)&&(tree -> right -> type != LEAF_NODE)){
            translateEntry(tree -> right);
            int leftLabel = tempI;
            char buff[5] = {'\0'};
            sprintf(buff, "t%d", leftLabel);
            printf(
                    "t%d= %s%c%s\n",
                    ++tempI,
                    tree -> left -> entry.lexeme,
                    simbToChar(tree -> entry.operation),
                    buff
            );
        }else{
            translateEntry(tree -> left);
            int leftLabel = tempI;
            translateEntry(tree -> right);
            int rightLabel = tempI;
            char buff[5] = {'\0'};
            char buff1[5] = {'\0'};
            sprintf(buff, "t%d", leftLabel);
            sprintf(buff1, "t%d", rightLabel);
            printf(
                    "t%d= %s%c%s\n",
                    ++tempI,
                    buff,
                    simbToChar(tree -> entry.operation),
                    buff1
                    );
        }
    }
}
void initParser(){
    lookahead = getNextToken();
}

nodeTree * parse(void){
    initParser();
    expr();
    if(lookahead == NULL){
        return EXPRNODE;
    }else{
        SyntaxError();
    }
}


void expr(void){
#ifdef DEBUG
    printf("%s",__func__);
#endif
    term();
    EXPRPINHERITED = TERMNODE;
    exprP();
    EXPRNODE = EXPRPNODE;
}
void exprP(void){
#ifdef DEBUG
    printf("%s",__func__);
#endif
    if(lookahead == NULL){
        EXPRPNODE = EXPRPINHERITED;
        return;
    }

    nodeTree * node = malloc(sizeof(struct nodeTree));

    if(node == NULL){
        fprintf(stderr,
                "An error has ocurred on %s in %s in line %d",
                __func__,
                __FILE__,
                __LINE__);
        exit(EXIT_FAILURE);
    }

    if(lookahead -> label == PLUS){
        node -> type = INTERIOR_NODE;
        node -> entry.operation = PLUS;
        node -> left = EXPRPINHERITED;
        match(PLUS);
        term();
        node -> right = TERMNODE;
        EXPRPINHERITED = node;
        exprP();
        EXPRPNODE = EXPRPINHERITED;
    }else if(lookahead -> label == MINUS){
        node -> type = INTERIOR_NODE;
        node -> entry.operation = MINUS;
        node -> left = EXPRPINHERITED;
        match(MINUS);
        term();
        node -> right = TERMNODE;
        EXPRPINHERITED = node;
        exprP();
        EXPRPNODE = EXPRPINHERITED;
    }else{
        EXPRPNODE = EXPRPINHERITED;
        return;
    }


}
void term(void){
#ifdef DEBUG
    printf("%s",__func__);
#endif
    factor();
    TERMPINHERITED = FACTORNODE;
    termP();
    TERMNODE = TERMPNODE;

}
void termP(void){
#ifdef DEBUG
    printf("%s",__func__);
#endif
    if(lookahead == NULL){
        TERMPNODE = TERMPINHERITED;
        return;
    }

    nodeTree * node = malloc(sizeof(struct nodeTree));

    if(node == NULL){
        fprintf(stderr,
                "An error has ocurred on %s in %s in line %d",
                __func__,
                __FILE__,
                __LINE__);
        exit(EXIT_FAILURE);
    }
    if(lookahead -> label == DOT){

        node -> type = INTERIOR_NODE;
        node -> entry.operation = DOT;
        node -> left = TERMPINHERITED;
        match(DOT);
        factor();
        node -> right = FACTORNODE;
        TERMPINHERITED = node;
        termP();
        TERMPNODE = TERMPINHERITED;

    }else if(lookahead -> label == DIV){
        node -> type = INTERIOR_NODE;
        node -> entry.operation = DIV;
        node -> left = TERMPINHERITED;
        match(DIV);
        factor();
        node -> right = FACTORNODE;
        TERMPINHERITED = node;
        termP();
        TERMPNODE = TERMPINHERITED;
    }else{
        TERMPNODE = TERMPINHERITED;
        return;
    }

}
void factor(void){
#ifdef DEBUG
    printf("%s",__func__);
#endif
    if(lookahead == NULL){
        return;
    }
    if(lookahead -> label == NUM){
        nodeTree * node = malloc(sizeof(struct nodeTree));
        if(node == NULL){

            fprintf(
                    stderr,
                    "An error has ocurred on %s in %s in line %d",
                    __func__,
                    __FILE__,
                    __LINE__);

            exit(EXIT_FAILURE);
        }

        node -> type = LEAF_NODE;
        node -> entry.lexeme = malloc(sizeof(char) * strlen(lookahead -> element.lexeme));

        if(node -> entry.lexeme == NULL){
            fprintf(stderr,
                    "An error has ocurred on %s in %s in line %d",
                    __func__,
                    __FILE__,
                    __LINE__);
            exit(EXIT_FAILURE);
        }
        strcpy(node -> entry.lexeme, lookahead -> element.lexeme);
        FACTORNODE = node;

        match(NUM);
    }else if(lookahead -> label == LEFTPAR){
        match(LEFTPAR);
        expr();
        FACTORNODE = EXPRNODE;
        match(RIGHTPAR);
    }else{


        SyntaxError();
    }
}
void match(token simbolo){
    if(lookahead == NULL){
        SyntaxError();
    }

    if(lookahead -> label == simbolo){
        lookahead = getNextToken();
    }else{
        SyntaxError();
    }
}

