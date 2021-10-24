#include "node.h"
#include "memory.h"
#include <stdlib.h>

Node *makeNode(NodeType type, char *token) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->nodeType = type;
    node->token = token;
    return node;
}

Node *makeBinaryOp(Node *left, Node *right, char *token, char op) {
    Node *node = makeNode(BINARY_OP, token);
    node->as.binaryOp = (BinaryOp *)malloc(sizeof(BinaryOp));
    node->as.binaryOp->left = left;
    node->as.binaryOp->right = right;
    node->as.binaryOp->op = op;
    return node;
}

Node *makeNumber(double value, char *token) {
    Node *node = makeNode(NUM, token);
    node->as.number = (Number *)malloc(sizeof(Number));
    node->as.number->value = value;
    return node;
}

Node *makeBoolean(int value, char *token) {
    Node *node = makeNode(BOOLEAN, token);
    node->as.boolean = (Boolean *)malloc(sizeof(Boolean));
    node->as.boolean->value = value;
    return node;
}

Node *makeFalse(char *token) { return makeBoolean(0, token); }
Node *makeTrue(char *token) { return makeBoolean(1, token); }

Node *makeProgram(char *token) {
    Node *node = makeNode(PROGRAM, token);
    node->as.program = (Program *)malloc(sizeof(Program));
    node->as.program->stmts = (NodeList *)malloc(sizeof(NodeList));
    node->as.program->stmts->capacity = 0;
    node->as.program->stmts->count = 0;
    node->as.program->stmts->nodes = NULL;
    return node;
}

void addNodeToProgram(Node *program, Node *nodeToAdd) {
    if (program->as.program->stmts->capacity <
        program->as.program->stmts->count + 1) {
        int oldCapacity = program->as.program->stmts->capacity;
        program->as.program->stmts->capacity = GROW_CAPACITY(oldCapacity);
        program->as.program->stmts->nodes =
            GROW_ARRAY(Node, program->as.program->stmts->nodes, oldCapacity,
                       program->as.program->stmts->capacity);
    }

    program->as.program->stmts->nodes[program->as.program->stmts->count] =
        *nodeToAdd;
    program->as.program->stmts->count++;
}

Node *makePrint(Node *exp, char *token) {
    Node *node = makeNode(PRINT_STMT, token);
    node->as.print = (Print *)malloc(sizeof(Print));
    node->as.print->exp = exp;
    return node;
}

Node *makeUnary(Node *right, char *token, char op) {
    Node *node = makeNode(UNARY_OP, token);
    node->as.unaryOp = (UnaryOp *)malloc(sizeof(UnaryOp));
    node->as.unaryOp->op = op;
    node->as.unaryOp->right = right;
    return node;
}